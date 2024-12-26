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
 * File: Transform.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  Owned through "has a" relationship by the GameObject class.
 *  This is the means to control game objects three dimensional behaviour
 *  (translation, rotation (euler & quaternion) and scale).
 *  Parent and child transforms can be assigned.
 *  Parent and child relationships are automatically broken through
 *  destructor.
 *  Game objects's transform will live even after the destroy or
 *  destroyImmediately are called if stack allocated until the game object's
 *  destructro is called.
 *****************************************************************************/

#include "Transform.h"

// Dependencies | glm
#include <glm/gtx/matrix_decompose.hpp>

// Local functions
static void voidEmptyFunction() {

}

// class ITransform

// Object | public

// Constructor / Destructor
IT::ITransform::ITransform() {

}
IT::ITransform::~ITransform() {
	if (listPointer != nullptr)
		listPointer->erase(node);
}

// Functions
void IT::ITransform::onTransformChange() {
	// To be implemented in child class
}

// class Transform

// Object | public

// Constructor / Destructor
IT::Transform::Transform(GameObject& gameObject) : gameObject(gameObject), position(glm::vec3()), rotation(glm::vec3()), scale(glm::vec3(1)), orientation(glm::quat(glm::vec3())), globalMatrix(glm::mat4(1)), requiresUpdate(true), parent(nullptr), children(std::vector<Transform*>(0)) {

}
IT::Transform::~Transform() {
	setParent(nullptr);
	for (Transform* currentChildTransform : children)
		currentChildTransform->setParent(nullptr);

	for (ITransform* iTransform : listeners)
		iTransform->listPointer = nullptr;
}

// Getters / Setters
IT::GameObject& IT::Transform::getGameObject() const {
	return gameObject;
}
glm::vec3 IT::Transform::getPosition() const {
	return position;
}
glm::vec3 IT::Transform::getRotation() const {
	return rotation;
}
glm::vec3 IT::Transform::getScale() const {
	return scale;
}
glm::quat IT::Transform::getOrientation() const {
	return orientation;
}
glm::mat4 IT::Transform::getGlobalMatrix() {
	if (requiresUpdate)
		calculateGlobalMatrix();
	return globalMatrix;
}
bool IT::Transform::getRequiresUpdate() const {
	return requiresUpdate;
}
IT::Transform* IT::Transform::getParent() const {
	return parent;
}
std::vector<IT::Transform*> IT::Transform::getChildren() const {
	return children;
}

void IT::Transform::setPosition(const glm::vec3& position) {
	setRequiresUpdate(true);

	this->position = position;
}
void IT::Transform::setRotation(const glm::vec3& rotation) {
	setRequiresUpdate(true);

	this->rotation = rotation;
	orientation = glm::quat(rotation);
}
void IT::Transform::setScale(const glm::vec3& scale) {
	setRequiresUpdate(true);

	this->scale = scale;
}
void IT::Transform::setOrientation(const glm::quat& orientation) {
	setRequiresUpdate(true);

	this->orientation = orientation;
	rotation = glm::eulerAngles(orientation);
}
void IT::Transform::setRequiresUpdate(bool requiresUpdate) {
	this->requiresUpdate = requiresUpdate;
	for (ITransform* iTransform : listeners)
		iTransform->onTransformChange();

	for (Transform* currentChildTransform : children)
		currentChildTransform->setRequiresUpdate(requiresUpdate);
}
void IT::Transform::setParent(IT::Transform* transform) {
	setRequiresUpdate(true);

	// Unlink from current parent
	if (parent != nullptr)
		for (unsigned int i = 0; i < parent->children.size(); i++)
			if (parent->children[i] == this) {
				parent->children.erase(parent->children.begin() + i);
				parent = nullptr;
				break;
			}

	// Exit if new parent == mullptr
	if (transform == nullptr)
		return;

	// Link to new parent
	parent = transform;
	parent->children.push_back(this);
}

// Functions | Local
void IT::Transform::translateBy(const glm::vec3& translation) {
	setRequiresUpdate(true);

	position += translation;
}
void IT::Transform::rotateBy(const glm::vec3& rotation) {
	setRequiresUpdate(true);

	this->rotation += rotation;
	orientation = glm::quat(this->rotation);
}
void IT::Transform::scaleBy(const glm::vec3& scale) {
	setRequiresUpdate(true);

	this->scale *= scale;
}
void IT::Transform::setLocalMatrix(const glm::mat4& matrix) {
	setRequiresUpdate(true);

	glm::vec3 skew = glm::vec3(0); // Ignored
	glm::vec4 perspective = glm::vec4(0); // Ignored
	glm::decompose(matrix, scale, orientation, position, skew, perspective);
	rotation = glm::eulerAngles(orientation);
}
glm::mat4 IT::Transform::getMatrix() const {
	glm::mat4 matrix = glm::mat4(1);
	matrix = glm::translate(matrix, position);
	matrix *= glm::mat4_cast(orientation);
	matrix = glm::scale(matrix, scale);
	return matrix;
}

// Functions | Global
void IT::Transform::calculateGlobalMatrix() {
	requiresUpdate = false;

	if (parent == nullptr)
		globalMatrix = getMatrix();
	else
		globalMatrix = getMatrix() * parent->getGlobalMatrix();
}
glm::vec3 IT::Transform::getGlobalPosition() {
	glm::mat4 matrix = getGlobalMatrix();
	return glm::vec3(matrix[3][0], matrix[3][1], matrix[3][2]);
}
glm::vec3 IT::Transform::getGlobalRotation() const {
	if (parent == nullptr)
		return rotation;
	return parent->getGlobalRotation() + rotation;
}
glm::vec3 IT::Transform::getGlobalScale() const {
	if (parent == nullptr)
		return scale;
	return scale * parent->getGlobalScale();
}
glm::quat IT::Transform::getGlobalOrientation() const {
	if (parent == nullptr)
		return orientation;
	return orientation * parent->getGlobalOrientation();
}

// ITransform | Functions
void IT::Transform::addListener(ITransform* iTransform) {
	listeners.push_back(iTransform);
	iTransform->listPointer = &listeners;
	iTransform->node = std::prev(listeners.end());
}
void IT::Transform::removeListener(ITransform* iTransform) {
	listeners.erase(iTransform->node);
	iTransform->listPointer = nullptr;
}
