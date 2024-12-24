#include "Box2DEngine.h"

// Dependencies | CoreEngine
#include <src/GameObject.h>

// class Box2DEngine

// Static | private

// Properties
Box2DEngine* Box2DEngine::singleton = nullptr;
b2Vec2 Box2DEngine::defaultGravity = b2Vec2(0.0f, -10.0f);

// Static | public

// Getters
Box2DEngine* Box2DEngine::getBox2DEngine() {
	return singleton;
}

// Object | public

// Constructor / Destructor
Box2DEngine::Box2DEngine() : Box2DEngine(defaultGravity) {

}
Box2DEngine::Box2DEngine(const b2Vec2& gravity) : gravity(gravity) {
	if (singleton == nullptr)
		singleton = this;

	world.SetGravity(gravity);
	world.SetContactListener(&contactListener);
	world.SetDestructionListener(&destructionListener);
}
Box2DEngine::~Box2DEngine() {
	if (singleton == this)
		singleton = nullptr;
}

// Functions
void Box2DEngine::update(float timeStep) {
	// Error check
	if (singleton == nullptr)
		return;

	// Simulate world using timeStep seconds
	world.Step(timeStep, velocityIterations, positionIterations);

	// Iterator through all the bodies
	for (b2Body* rigidBody = world.GetBodyList(); rigidBody; rigidBody = rigidBody->GetNext()) {
		// If rigid body is dynamic, apply position and rotation to game object
		b2BodyType rigidBodyType = rigidBody->GetType();
		if (rigidBodyType == b2_dynamicBody && rigidBody->IsAwake()) {
			// Get rigid body position and rotation
			b2Vec2 rigidBodyPosition = rigidBody->GetPosition();
			float rigidBodyRotation = rigidBody->GetAngle();

			// Get game object position and rotation
			RigidBodyB2D* rigidBodyB2D = (RigidBodyB2D*)rigidBody->GetUserData().pointer;
			IT::GameObject& gameObject = rigidBodyB2D->getGameObject();
			glm::vec3 gameObjectPosition = gameObject.transform.getPosition();
			glm::vec3 gameObjectRotation = gameObject.transform.getRotation();

			// Apply rigid body position and rotation
			gameObject.transform.setPosition(glm::vec3(rigidBodyPosition.x, rigidBodyPosition.y, gameObjectPosition.z));
			gameObject.transform.setRotation(glm::vec3(gameObjectRotation.x, gameObjectRotation.y, rigidBodyRotation));
		}
	}
}
