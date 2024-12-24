#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

// Dependencies | CoreEngine
#include <src/Component.h>

class JointB2D : public IT::Component {
	// Object
	public:
		// Properties
		b2Joint* joint = nullptr;

		// Constructor / Destructor
		JointB2D(IT::GameObject& gameObject, b2JointDef* jointDefinition);
		~JointB2D();
};
