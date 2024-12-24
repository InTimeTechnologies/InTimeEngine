#include "RigidBodyB2D.h"

// Dependencies | CoreEngine
#include <src/GameObject.h>

// Dependencies | Box2DEngine
#include "../Box2DEngine.h"

// class RigidBody2D

// Static | public

// Properties
b2BodyDef RigidBodyB2D::defaultBodyDefinition;

// Object | public

// Constructor / Destructor
RigidBodyB2D::RigidBodyB2D(IT::GameObject& gameObject) : Component(gameObject, typeid(RigidBodyB2D)) {
	// Change game object's position to match the rigid body's
	b2Vec2 rigidBodyPosition = defaultBodyDefinition.position;
	glm::vec3 gameObjectPosition = gameObject.transform.getPosition();
	gameObjectPosition.x = rigidBodyPosition.x;
	gameObjectPosition.y = rigidBodyPosition.y;
	gameObject.transform.setPosition(gameObjectPosition);

	// Create rigid body
	defaultBodyDefinition.userData.pointer = (uintptr_t)this;
	b2World* world = &Box2DEngine::getBox2DEngine()->world;
	rigidBody = world->CreateBody(&defaultBodyDefinition);
}
RigidBodyB2D::RigidBodyB2D(IT::GameObject& gameObject, b2BodyDef& bodyDefinition) : Component(gameObject, typeid(RigidBodyB2D)) {
	// Change game object's position to match the rigid body's
	b2Vec2 rigidBodyPosition = bodyDefinition.position;
	glm::vec3 gameObjectPosition = gameObject.transform.getPosition();
	gameObjectPosition.x = rigidBodyPosition.x;
	gameObjectPosition.y = rigidBodyPosition.y;
	gameObject.transform.setPosition(gameObjectPosition);

	// Create rigid body
	bodyDefinition.userData.pointer = (uintptr_t)this;
	b2World* world = &Box2DEngine::getBox2DEngine()->world;
	rigidBody = world->CreateBody(&bodyDefinition);
}
RigidBodyB2D::~RigidBodyB2D() {
	// Destroy body
	b2World* world = &Box2DEngine::getBox2DEngine()->world;
	world->DestroyBody(rigidBody);
}

// Component | Events
void RigidBodyB2D::onDestroy() {

}
