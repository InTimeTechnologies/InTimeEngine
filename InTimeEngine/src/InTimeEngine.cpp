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
 * Updated on: 13DEC2024
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

// class InTimeEngine

// Static | private

// Properties
IT::InTimeEngine* IT::InTimeEngine::singleton = nullptr;

// Static | public

// Getters
IT::InTimeEngine* IT::InTimeEngine::getSingleton() {
	return singleton;
}

// Functions
void IT::InTimeEngine::voidEmptyFunction() {
	return; // Left empty intentionally
}
bool IT::InTimeEngine::boolEmptyFunction() {
	return true; // Defaults to return true to force engine to stop when called without this function being replaced by user.
}
void IT::InTimeEngine::physicsUpdateEmptyFunction(float timeStep) {
	return; // Left empty intentionally
}


// Object | public

// Constructor / Destructor
IT::InTimeEngine::InTimeEngine(const std::filesystem::path& applicationDirectoryPath) {
	if (singleton == nullptr)
		singleton = this;

	// EngineTime
	physicsTime.settings.fixedUpdate = true;
	coreTime.settings.fixedUpdate = false;
}
IT::InTimeEngine::~InTimeEngine() {
	if (singleton != nullptr)
		singleton = nullptr;

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
	engineTime.updateRealTime();
	coreTime.resetTime(engineTime.runTime);
	physicsTime.resetTime(engineTime.runTime);

	// Engine / game loop
	while (!shouldStop) {
		// Update real time / run time. It's necessary for physics and core time to work
		engineTime.updateRealTime();

		// bool physicsRequiresUpdate = time.physicsTime.updateTime(time.runTime);
		bool coreRequiresUpdate = coreTime.updateTime(engineTime.runTime);
		bool physicsRequiresUpdate = physicsTime.updateTime(engineTime.runTime);

		// Reset keyboard keys (justPressed, justReleased, repeat)
		resetInput();

		// If core requires update, update UI and input
		if (coreRequiresUpdate) {
			processInput();
			processUIEvents();
		}

		// Init components (enable, disable, start)
		initializeLogics();

		// Update physics if it requires update
		if (physicsRequiresUpdate) {
			do {
				// Update physics engine
				prePhysicsUpdate();
				updatePhysics(physicsTime.getScaledDeltaTimeF());
				postPhysicsUpdate();
			} while (physicsTime.updateTime(engineTime.runTime));
		}

		// Update core if it requires update
		if (coreRequiresUpdate) {
			// Update core engine
			preUpdate();
			coreUpdate();
			postUpdate();
		}

		// Render
		if (iRenderer != nullptr && coreRequiresUpdate) {
			preRender();
			render();
			postRender();
		}

		// Collect garbage
		collectGarbage();

		// Process termination
		if (shouldStop) {
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
	IWindow::resetKeyboardInputFunction();
	IInput::resetJoystickInputFunction();
}
void IT::InTimeEngine::processInput() {
	IInput::processInput();
}
void IT::InTimeEngine::processUIEvents() {
	IWindow::pollEventsFunction();
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
	for (IWindow* window : IWindow::windowList)
		window->swapBuffers();
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