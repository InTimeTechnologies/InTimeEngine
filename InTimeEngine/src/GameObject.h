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
 * File: GameObject.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 * Updated on: 13DEC2024
 *
 * Description:
 *  Serves as a container for components created by the user. It has a
 *  transorm object that the user can use, but so as the physics and rendering
 *  system.
 *  Calling destroy or destroyImmediately will unlink the game object from the
 *  engine.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <string>
#include <typeinfo>
#include <vector>
#include <list>

// Dependencies | CoreEngine
#include "Transform.h"
#include "ObjectStatus.h"
#include "MemoryAllocationType.h"

// Forward declarations
namespace IT {
	// Forward declarations
	class GameObject;
	class Component;

	class GameObject {
		// Friends
		friend class Component;
		friend class InTimeEngine;

		// Static
		private:
			// Properties
			static IT::MemoryAllocationType currentObjectMemoryAllocationType; // Used by the new function to pass data from it to the object

			// Functions
			static void collectGarbage();

		public:
			// Properties | System
			static std::list<GameObject*> gameObjects;
			static std::list<GameObject*> gameObjectsToDelete;

			// Properties | Default values
			static int defaultId;
			static std::string defaultName;

			// Functions
			static void destroyGameObjects();
			static void destroyGameObjectsImmediately();

		// Object
		public:
			// Properties
			int id = defaultId;
			std::string name = defaultName;
			Transform transform = Transform(*this);
			bool deleteOnDestroy = true;

		private:
			// Properties
			ObjectStatus status = ObjectStatus::HEALTHY;
			MemoryAllocationType memoryAllocationType = MemoryAllocationType::STACK;
			int uuid = -1;
			std::list<GameObject*>::iterator node;
			std::list<Component*> components = std::list<Component*>();

		public:
			// Constructors / Destructor
			GameObject();
			GameObject(std::string name);
			GameObject(int id);
			GameObject(int id, const std::string& name); // This is the contructor that the other ones call
			~GameObject();

			// Getters
			ObjectStatus getStatus() const;
			MemoryAllocationType getMemoryAllocationType() const;

			// Functions
			void destroy();
			void destroyImmediately();

			// Functions | Component
			long long getNumberOfComponents() const;
			std::vector<Component*> getComponents() const;
			std::vector<Component*> getComponents(const type_info& typeInfo) const;
			Component* getComponent(const type_info& typeInfo) const;
			Component* getFirstComponent() const;
			Component* getLastComponent() const;
			int getComponentIndex(Component* component) const;

			// Operators
			void* operator new(size_t size);
	};
}