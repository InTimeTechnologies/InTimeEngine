#include "DestructionListener.h"

// Dependencies | Box2DEngine
#include "component/FixtureB2D.h"
#include "component/JointB2D.h"

// Dependencies | CoreEngine
#include <src/GameObject.h>

// class DestructionListener

// Object | public

// Constructor / Destructor
DestructionListener::DestructionListener() : b2DestructionListener() {
	
}
DestructionListener::~DestructionListener() {

}

// b2DestructionListener | Events
void DestructionListener::SayGoodbye(b2Fixture* fixture) {
	FixtureB2D* fixtureB2D = (FixtureB2D*)fixture->GetUserData().pointer;
	if (fixtureB2D == nullptr)
		return;
	fixtureB2D->fixture = nullptr;
	fixtureB2D->destroy();
}
void DestructionListener::SayGoodbye(b2Joint* joint) {
	JointB2D* jointB2D = (JointB2D*)joint->GetUserData().pointer;
	if (jointB2D == nullptr)
		return;
	jointB2D->joint = nullptr;
	jointB2D->destroy();
}
