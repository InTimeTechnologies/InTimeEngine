#include "JointB2D.h"

// Dependencies | Box2DEngine
#include "../Box2DEngine.h"

// class JointB2D

// Object | public

// Constructor / Destructor
JointB2D::JointB2D(IT::GameObject& gameObject, b2JointDef* jointDefinition) : Component(gameObject, typeid(JointB2D)) {
	// Associate joint with this component
	jointDefinition->userData.pointer = (uintptr_t)this;

	// Create joint
	joint = Box2DEngine::getBox2DEngine()->world.CreateJoint(jointDefinition);
}
JointB2D::~JointB2D() {
	// Error check (will only be true if rigid body is destroyed first)
	if (joint == nullptr)
		return;

	// Remove the joint from the world
	Box2DEngine::getBox2DEngine()->world.DestroyJoint(joint);
}
