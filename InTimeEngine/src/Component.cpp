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
 * File: Component.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This is what gives functionality to whatever game object it is attached to
 *  and is meant to be overriden by user defined classes. It can be stack or
 *  heap allocated. Memory management relies on the user. Calling destroy or
 *  destroyImmediately will unlink the component from the game engine. You can
 *  get notified of when destruction happens by overriding onMarkForDestroy
 *  and onDestroy.
 *****************************************************************************/

#include "Component.h"

// Dependencies | InTimeEngine
#include "GameObject.h"
#include "ComponentRegistry.h"

// Component

// Static | private

// Properties
std::list<IT::Component*> IT::Component::componentsToDelete = std::list<IT::Component*>();
IT::MemoryAllocationType IT::Component::currentObjectMemoryAllocationType = IT::MemoryAllocationType::STACK;

// Functions
void IT::Component::collectGarbage() {
	// Note: A while loop is used because deleting a component can cause other components to be deleted
	// Do not replace with any other type of loop
	// Do not replace std::list for componentsToDelete with any other data structures. New components to be deleted must be added to the back, not the front
	while (componentsToDelete.size() > 0) {
		Component* component = componentsToDelete.front();
		component->onDestroy();
		component->gameObject.components.erase(component->componentNode);
		component->status = ObjectStatus::DESTROYED;
		componentsToDelete.pop_front();

		if (component->deleteOnDestroy && component->memoryAllocationType == MemoryAllocationType::HEAP)
			delete(component);
	}
}

// Object | public

// Constructor / Destructor
IT::Component::Component(GameObject& gameObject, const type_info& typeInfo) : gameObject(gameObject), typeInfo(typeInfo) {
	if (gameObject.status != ObjectStatus::HEALTHY) {
		status = ObjectStatus::DESTROYED;
		return;
	}
	
	gameObject.components.push_back(this);
	componentNode = std::prev(gameObject.components.end());

	if (currentObjectMemoryAllocationType == MemoryAllocationType::HEAP) {
		memoryAllocationType = currentObjectMemoryAllocationType;
		currentObjectMemoryAllocationType = MemoryAllocationType::STACK;
	}
}
IT::Component::~Component() {
	deleteOnDestroy = false;
	if (status != ObjectStatus::DESTROYED)
		destroyImmediately();
}

// Getters
IT::GameObject& IT::Component::getGameObject() const {
	return gameObject;
}
const type_info& IT::Component::getTypeInfo() const {
	return typeInfo;
}
IT::ObjectStatus IT::Component::getStatus() const {
	return status;
}
IT::MemoryAllocationType IT::Component::getMemoryAllocationType() const {
	return memoryAllocationType;
}
IT::ComponentType IT::Component::getComponentType() const {
	return COMPONENT_TYPE;
}

// Functions
void IT::Component::destroy() {
	// Error check
	if (status != ObjectStatus::HEALTHY)
		return;

	// Add component to the list of components to be deleted
	componentsToDelete.push_back(this);
	status = ObjectStatus::MARKED_FOR_DESTROY;
	onMarkForDestroy();
}
void IT::Component::destroyImmediately() {
	onDestroy();

	if (status == ObjectStatus::MARKED_FOR_DESTROY)
		componentsToDelete.remove(this);

	gameObject.components.erase(componentNode);
	status = ObjectStatus::DESTROYED;

	if (deleteOnDestroy && memoryAllocationType == MemoryAllocationType::HEAP)
		delete(this);
}

// Events
void IT::Component::onMarkForDestroy() {
	// To be implemented in child class
}
void IT::Component::onDestroy() {
	// To be implemented in child class
}

// Operators
void* IT::Component::operator new(size_t size) {
	currentObjectMemoryAllocationType = MemoryAllocationType::HEAP;
	return ::operator new(size);
}
