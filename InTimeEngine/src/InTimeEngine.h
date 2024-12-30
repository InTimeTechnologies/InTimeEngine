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

#pragma once

// Dependencies | std
#include <functional>
#include <vector>
#include <string>
#include <filesystem>

// Dependencies | InTimeEngine
#include "GameObject.h"
#include "Transform.h"
#include "Component.h"
#include "Time.h"
#include "IEngineEvents.h"
#include "IPhysicsEngine2D.h"
#include "IRenderer.h"
#include "IInput.h"

// Namespace
namespace IT {
	class InTimeEngine {
		// Friends
		friend class IPhysics;

		// Static
		private:
			// Properties
			static InTimeEngine* singleton;

		public:
			// Getters
			static InTimeEngine* getSingleton();

		// Object
		private:
			// Properties
			bool shouldPause = false;
			bool shouldStop = false;

		public:
			// Properties
			EngineTime engineTime = EngineTime();
			Time coreTime = Time();
			Time physicsTime = Time();
			IPhysicsEngine2D* iPhysicsEngine2D = nullptr;
			IRenderer* iRenderer = nullptr;

			// Callbacks
			std::function<bool()> onPauseCallback = std::function<bool()>();
			std::function<bool()> onStopCallback = std::function<bool()>();

			// Flags
			bool destroyGameObjectsOnStop = false;
			bool destroyGameObjectsOnDelete = true;

			// Constructor / Destructor
			InTimeEngine(const std::filesystem::path& applicationDirectoryPath);
			~InTimeEngine();

			// Getters
			bool getShouldPause() const;
			bool getShouldTerminate() const;

			// Functions
			void run();

			void pause();
			void stop();

		private:
			// Functions
			void initializeLogics();

			void resetInput();
			void processInput();

			void preUpdate();
			void coreUpdate();
			void postUpdate();

			void prePhysicsUpdate();
			void updatePhysics(float timeStep);
			void postPhysicsUpdate();

			void preRender();
			void render();
			void postRender();


			void collectGarbage();
	};
}

// Dependencies | Components
#include "component/EmptyComponent.h"

// Dependencies | InTimeEngine | Object
#include "object/Stopwatch.h"
#include "object/Timer.h"
