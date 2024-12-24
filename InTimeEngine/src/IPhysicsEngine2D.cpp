#include "IPhysicsEngine2D.h"

// Dependencies | InTimeEngine
#include "InTimeEngine.h"

// class IPhysicsEngine2D

// Object | public

// Constructor / Destructor
IT::IPhysicsEngine2D::IPhysicsEngine2D() {
	InTimeEngine* inTimeEngine = InTimeEngine::getSingleton();
	if (inTimeEngine == nullptr)
		return;

	// If no 2D physics engine has been registered to In Time Engine
	if (inTimeEngine->iPhysicsEngine2D == nullptr)
		inTimeEngine->iPhysicsEngine2D = this; // Register this as In Time Engine's 2D physics engine
}
IT::IPhysicsEngine2D::~IPhysicsEngine2D() {
	InTimeEngine* inTimeEngine = InTimeEngine::getSingleton();
	if (inTimeEngine == nullptr)
		return;

	// If this 2D physics engine has been registered to In Time Engine
	if (inTimeEngine->iPhysicsEngine2D == this)
		inTimeEngine->iPhysicsEngine2D = nullptr; // Unegister this as In Time Engine's 2D physics engine
}
