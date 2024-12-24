#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

// Dependencies | Box2DEngine
#include "Box2DCallback.h"

class ContactListener : public b2ContactListener {
	// Object
	public:
		// Constructor / Destructor
		ContactListener();
		~ContactListener();

		// b2ContactListener | Functions
		void BeginContact(b2Contact* contact) override;
		void EndContact(b2Contact* contact) override;
		void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
		void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;
};
