#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

// Dependencies | Box2DEngine
#include "ContactListener.h"
#include "DestructionListener.h"
#include "Box2DCallback.h"
#include "component/RigidBodyB2D.h"
#include "component/FixtureB2D.h"
#include "component/JointB2D.h"

// Dependencies | InTimeEngine
#include <src/IPhysicsEngine2D.h>

class Box2DEngine : public IT::IPhysicsEngine2D {
	// Static
	private:
		// Properties
		static Box2DEngine* singleton;
		static b2Vec2 defaultGravity;

	public:
		// Getters
		static Box2DEngine* getBox2DEngine();

	// Object
	public:
		// Properties
		b2World world = b2World(defaultGravity);
		b2Vec2 gravity = defaultGravity;
		int velocityIterations = 6;
		int positionIterations = 2;
		ContactListener contactListener = ContactListener();
		DestructionListener destructionListener = DestructionListener();

		// Constructor / Destructor
		Box2DEngine();
		Box2DEngine(const b2Vec2& gravity);
		~Box2DEngine();

		// Functions
		void update(float timeStep) override;
};
