#include "FixtureB2D.h"

// Dependencies | CoreEngine
#include <src/GameObject.h>

// Dependencies | Box2DEngine
#include "RigidBodyB2D.h"

// class FixtureB2D

// Object | public

// Properties
b2FixtureDef FixtureB2D::defaultFixtureDefinition;

// Object | public

// Constructor / Destructor
FixtureB2D::FixtureB2D(IT::GameObject& gameObject) : FixtureB2D(gameObject, defaultFixtureDefinition) {

}
FixtureB2D::FixtureB2D(IT::GameObject& gameObject, b2FixtureDef& fixtureDefinition) : Component(gameObject, typeid(FixtureB2D)) {
	// Get rigid body attached to this game object
	RigidBodyB2D* rigidBodyComponent = (RigidBodyB2D*)gameObject.getComponent(typeid(RigidBodyB2D));

	// If there is no rigid body attached, add it
	if (rigidBodyComponent == nullptr)
		rigidBodyComponent = new RigidBodyB2D(gameObject);

	// Attach fixture to rigid body
	fixtureDefinition.userData.pointer = (uintptr_t)this;
	fixture = rigidBodyComponent->rigidBody->CreateFixture(&fixtureDefinition);
}
FixtureB2D::~FixtureB2D() {
	// Error check (will only be true if rigid body is destroyed first)
	if (fixture == nullptr)
		return;

	// Remove the fixture from the rigid body
	b2Body* rigidBody = fixture->GetBody();
	rigidBody->DestroyFixture(fixture);
}
