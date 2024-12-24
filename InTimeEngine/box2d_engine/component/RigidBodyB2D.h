#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

// Dependencies | CoreEngine
#include <src/Component.h>

class RigidBodyB2D : public IT::Component {
	// Static
	public:
		// Properties
		static b2BodyDef defaultBodyDefinition;

	// Object
	public:
		// Properties
		b2Body* rigidBody = nullptr;

		// Constructor / Destructor
		RigidBodyB2D(IT::GameObject& gameObject);
		RigidBodyB2D(IT::GameObject& gameObject, b2BodyDef& bodyDefinition);
		~RigidBodyB2D();
		
		// Component | Events
		void onDestroy() override;
};
