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

#include "GameObject.h"

// Dependencies | CoreEngine
#include "Component.h"

// GameObject

// Static | private

// Properties
IT::MemoryAllocationType IT::GameObject::currentObjectMemoryAllocationType = IT::MemoryAllocationType::STACK;

// Functions
void IT::GameObject::collectGarbage() {
	// Note: A while loop is used because deleting a game object can cause other game objects to be deleted
	// Do not replace with any other type of loop
	// Do not replace std::list for gameObjectsToDelete with any other data structures. New game objects to be deleted must be added to the back, not the front
	while (gameObjectsToDelete.size() > 0) {
		GameObject* gameObject = gameObjectsToDelete.front();
		gameObjectsToDelete.pop_front();
		gameObject->status = ObjectStatus::DESTROYED;

		gameObjects.erase(gameObject->node);
		
		if (gameObject->deleteOnDestroy && gameObject->memoryAllocationType == MemoryAllocationType::HEAP)
			delete(gameObject);
	}
}

// Static | public

// Properties | System
std::list<IT::GameObject*> IT::GameObject::gameObjects = std::list<IT::GameObject*>();
std::list<IT::GameObject*> IT::GameObject::gameObjectsToDelete = std::list<IT::GameObject*>();

// Properties | Default values
int IT::GameObject::defaultId = 0;
std::string IT::GameObject::defaultName = "Game Object";

// Functions
void IT::GameObject::destroyGameObjects() {
	for (GameObject* gameObject : gameObjects)
		gameObject->destroy();
}
void IT::GameObject::destroyGameObjectsImmediately() {
	while (gameObjects.size() > 0) {
		GameObject* gameObject = gameObjects.front();
		gameObject->destroyImmediately();
	}
}

// Object | public

// Constructors / Destructor
IT::GameObject::GameObject() : GameObject(GameObject::defaultId, GameObject::defaultName) {

}
IT::GameObject::GameObject(std::string name) : GameObject(GameObject::defaultId, name) {

}
IT::GameObject::GameObject(int id) : GameObject(id, GameObject::defaultName) {

}
// This is the contructor that the other ones call
IT::GameObject::GameObject(int id, const std::string& name) :  id(id), name(name) {
	gameObjects.push_back(this);
	node = std::prev(gameObjects.end());

	if (currentObjectMemoryAllocationType == MemoryAllocationType::HEAP) {
		memoryAllocationType = currentObjectMemoryAllocationType;
		currentObjectMemoryAllocationType = MemoryAllocationType::STACK;
	}
}
IT::GameObject::~GameObject() {
	deleteOnDestroy = false;
	if (status != ObjectStatus::DESTROYED)
		destroyImmediately();
}

// Object | public

// Getters
IT::ObjectStatus IT::GameObject::getStatus() const {
	return status;
}
IT::MemoryAllocationType IT::GameObject::getMemoryAllocationType() const {
	return memoryAllocationType;
}

// Functions
void IT::GameObject::destroy() {
	// If a lready marked for deletion or is already deleted, return
	if (status != ObjectStatus::HEALTHY)
		return;

	// Mark game object for deletion
	gameObjectsToDelete.push_back(this);
	status = ObjectStatus::MARKED_FOR_DESTROY;

	// Notify components that game object is marked for deletion
	for (Component* component : components)
		component->destroy();
}
void IT::GameObject::destroyImmediately() {
	// Destroy each component attached to this game object immediately
	while (components.size() > 0)
		components.front()->destroyImmediately();

	// If this game object is currently marked for deletion, remove it from the list
	if (status == ObjectStatus::MARKED_FOR_DESTROY)
		gameObjectsToDelete.remove(this);

	gameObjects.erase(node);
	status = ObjectStatus::DESTROYED;
	if (deleteOnDestroy && memoryAllocationType == MemoryAllocationType::HEAP)
		delete(this);
}

// Functions | Component
long long IT::GameObject::getNumberOfComponents() const {
	return components.size();
}
std::vector<IT::Component*> IT::GameObject::getComponents() const {
	std::vector<Component*> components = std::vector<Component*>();

	for (Component* component : this->components)
		if (component->status == ObjectStatus::HEALTHY)
			components.push_back(component);

	return components;
}
std::vector<IT::Component*> IT::GameObject::getComponents(const type_info& typeInfo) const {
	std::vector<Component*> components = std::vector<Component*>();

	for (Component* component : this->components)
		if (component->status == ObjectStatus::HEALTHY && typeInfo == component->typeInfo)
			components.push_back(component);

	return components;
}
IT::Component* IT::GameObject::getComponent(const type_info& typeInfo) const {
	// Match typeInfo to any component attached to this game object
	for (Component* component : components)
		if (component->getTypeInfo() == typeInfo && component->status == ObjectStatus::HEALTHY)
			return component; // Return matched component

	// Did not match give typeInfo to any of the components in the game object
	return nullptr;
}
IT::Component* IT::GameObject::getFirstComponent() const {
	if (components.size() == 0)
		return nullptr;

	return components.front();
}
IT::Component* IT::GameObject::getLastComponent() const {
	if (components.size() == 0)
		return nullptr;

	return components.back();
}
int IT::GameObject::getComponentIndex(Component* component) const {
	int i = 0;
	for (Component* currentComponent : components) {
		if (currentComponent == component)
			return i;
		i++;
	}
	return -1;
}

// Operators
void* IT::GameObject::operator new(size_t size) {
	currentObjectMemoryAllocationType = MemoryAllocationType::HEAP;
	return ::operator new(size);
}
