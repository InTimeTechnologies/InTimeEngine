/******************************************************************************
 * Copyright (c) 2024 Christopher Barrios Agosto. All Rights Reserved.
 *
 * Licensing Information:
 *  This software and associated documentation files (the "Software") may not
 *  be used, copied, modified, merged, published, distributed, sublicensed,
 *  or sold without the prior written permission of the copyright owner.
 *
 *  Unauthorized use of this file, via any medium, is strictly prohibited.
 *****************************************************************************/

/******************************************************************************
 * Project: In Time Engine
 * File: InTimeEngine.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  Operates all the core systems of the engine such as:
 *  - Game loop
 *  - Game object and component lifetime tracking to the game egine
 *  - Garbage collection through the interfaces
 *  - Time synchronization
 *  - Third party system update(s) such as but not limited to physics engine
 *  - Notification of engine events such as:
 *    - update
 *    - physicsUpdate
 *    - render
 *    - component initialization events
 *    - etc.
 *****************************************************************************/

#include "InTimeEngine.h"

// Dependencies | std
#include <thread>

// class InTimeEngine

// Static | private

// Properties
IT::InTimeEngine* IT::InTimeEngine::s_singleton = nullptr;
bool IT::InTimeEngine::s_initialized = false;

// Static | public

// Getters
IT::InTimeEngine* IT::InTimeEngine::s_getSingleton() {
	return s_singleton;
}

// Object | public

// Constructor / Destructor
IT::InTimeEngine::InTimeEngine(const std::filesystem::path& applicationDirectoryPath) {
	if (s_singleton == nullptr)
		s_singleton = this;

	// Initialize component registry
	{
		componentRegistry.engineEntries = std::vector<EntityRegistry::EngineEntry>(1);
		IT::EntityRegistry::EngineEntry engineEntry = IT::EntityRegistry::EngineEntry();

		// EmptyComponent
		engineEntry.componentTypeID = 0;
		engineEntry.typeInfo = &typeid(nullptr);
		engineEntry.factory = [](GameObject& gameObject) -> Component* { return new EmptyComponent(gameObject); };
		engineEntry.toJSON = [](Component*) -> nlohmann::ordered_json { return nlohmann::ordered_json::object(); };
		engineEntry.fromJSON = [](GameObject& gameObject, nlohmann::ordered_json) -> Component* { return new EmptyComponent(gameObject); };
		componentRegistry.engineEntries[0] = engineEntry;

		// Other components
	}
}
IT::InTimeEngine::~InTimeEngine() {
	if (s_singleton != nullptr)
		s_singleton = nullptr;

	if (destroyGameObjectsOnDelete)
		GameObject::destroyGameObjectsImmediately();
}

// Getters
bool IT::InTimeEngine::getShouldPause() const {
	return shouldPause;
}
bool IT::InTimeEngine::getShouldTerminate() const {
	return shouldStop;
}

// Functions
void IT::InTimeEngine::run() {
	// Set up time
	realTime.updateRealTime();
	time.resetTime(realTime.runTime);
	fixedTime.resetTime(realTime.runTime);

	// Engine / game loop
	while (!shouldStop) {
		// Update real time / run time. It's necessary for physics and core time to work
		realTime.updateRealTime();

		// Sleep thread if it is not necessary to updte
		if (!(time.shouldUpdate(realTime.runTime) || fixedTime.shouldUpdate(realTime.runTime))) {
			std::chrono::nanoseconds nextTimeUpdate = time.nextTimeToUpdate();
			std::chrono::nanoseconds nextFixedTimeUpdate= fixedTime.nextTimeToUpdate();
			std::chrono::nanoseconds sleepTime = (nextTimeUpdate < nextFixedTimeUpdate ? nextTimeUpdate : nextFixedTimeUpdate);
			std::chrono::high_resolution_clock::time_point sleepUntilTime = std::chrono::high_resolution_clock::time_point(sleepTime);
			//if (sleepTime - realTime.runTime > std::chrono::microseconds(1LL)) {
				//std::cout << "Game loop sleep time: " << sleepTime << std::endl;
			std::this_thread::sleep_until(sleepUntilTime);
			//}
			continue;
		}

		// bool physicsRequiresUpdate = time.fixedTime.updateTime(time.runTime);
		bool coreRequiresUpdate = time.update(realTime.runTime);
		bool physicsRequiresUpdate = fixedTime.update(realTime.runTime);

		// If core or physics requires update, update UI and input
		if (coreRequiresUpdate || physicsRequiresUpdate) {
			resetInput();
			processInput();

			// Init components (enable, disable, start)
			initializeLogics();
		}

		// Update physics if it requires update
		if (physicsRequiresUpdate) {
			do {
				// Update physics engine
				prePhysicsUpdate();
				updatePhysics(fixedTime.getScaledDeltaTimeF());
				postPhysicsUpdate();
			} while (fixedTime.update(realTime.runTime));
		}

		// Update core if it requires update
		if (coreRequiresUpdate) {
			// Update core engine
			preUpdate();
			coreUpdate();
			postUpdate();

			// Render
			if (iRenderer != nullptr) {
				preRender();
				render();
				postRender();
			}
		}

		// Collect garbage
		collectGarbage();

		// Process termination
		if (shouldStop) {
			bool callbackIsSet = static_cast<bool>(onStopCallback);
			if (callbackIsSet)
				shouldStop = onStopCallback();

			if (!shouldStop)
				continue;

			if (destroyGameObjectsOnStop)
				GameObject::destroyGameObjectsImmediately();
		}

		// Process pause
		if (shouldPause) {
			bool processed = false;
			do {
				bool callbackIsSet = static_cast<bool>(onPauseCallback);
				if (callbackIsSet)
					processed = onPauseCallback();
			} while (!processed);

			shouldPause = false;
		}
	}
}

void IT::InTimeEngine::pause() {
	shouldPause = true;
}
void IT::InTimeEngine::stop() {
	shouldStop = true;
}

// Object | private
void IT::InTimeEngine::initializeLogics() {
	for (ILogicInitialization* iComponentInit : ILogicInitialization::iComponentInitList)
		iComponentInit->onInit();

	ILogicInitialization::iComponentInitList.clear();
}

void IT::InTimeEngine::resetInput() {
	IInputSystem* inputSystem = IInputSystem::getSingleton();
	if (inputSystem != nullptr)
		inputSystem->resetInput();
}
void IT::InTimeEngine::processInput() {
	IInputSystem* inputSystem = IInputSystem::getSingleton();
	if (inputSystem != nullptr)
		inputSystem->processInput();
}

void IT::InTimeEngine::preUpdate() {
	for (ICoreUpdate* iUpdate : ICoreUpdate::iCoreUpdateList)
		iUpdate->onPreCoreUpdate();
}
void IT::InTimeEngine::coreUpdate() {

}
void IT::InTimeEngine::postUpdate() {
	for (ICoreUpdate* iUpdate : ICoreUpdate::iCoreUpdateList)
		iUpdate->onPostCoreUpdate();
}

void IT::InTimeEngine::prePhysicsUpdate() {
	for (IPhysicsUpdate* iPhysicsUpdate : IPhysicsUpdate::iPhysicsUpdateList)
		iPhysicsUpdate->onPrePhysicsUpdate();
}
void IT::InTimeEngine::updatePhysics(float timeStep) {
	// In physics engine is not present nor create, return
	if (iPhysicsEngine2D == nullptr)
		return;

	// Update physics engine timeStep seconds
	iPhysicsEngine2D->update(timeStep);
}
void IT::InTimeEngine::postPhysicsUpdate() {
	for (IPhysicsUpdate* iPhysicsUpdate : IPhysicsUpdate::iPhysicsUpdateList)
		iPhysicsUpdate->onPostPhysicsUpdate();
}

void IT::InTimeEngine::preRender() {
	for (IRender* iRender : IRender::iRenderList)
		iRender->onPreRender();
}
void IT::InTimeEngine::render() {
	iRenderer->render();

	// To-Do: Integrate these functionalities
	// Setup ImGui for next frame
	//ImGui_ImplOpenGL3_NewFrame();
	//ImGui_ImplGlfw_NewFrame();
	//ImGui::NewFrame();

	// Render custom user defined objects to the wold
	for (IRender* iRender : IRender::iRenderList)
		iRender->render();

	// Render UI
	for (IRenderUI* iRenderUI : IRenderUI::iRenderUIList)
		iRenderUI->renderUI();

	// To-Do: Integrate these functionalities
	// Render Dear ImGUI UI
	//ImGui::Render();
	//ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

	// Swap the frame buffer
	//for (IWindow* window : IWindow::windowList)
	//	window->swapBuffers();
}
void IT::InTimeEngine::postRender() {
	for (IRender* iRender : IRender::iRenderList)
		iRender->onPostRender();
}


void IT::InTimeEngine::collectGarbage() {
	// Note: Do not change order of garbage collection. Components must be collected first to keep data integrity.
	Component::collectGarbage();
	GameObject::collectGarbage();
}
