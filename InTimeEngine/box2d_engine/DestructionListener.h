#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

class DestructionListener : public b2DestructionListener {
	// Object
	public:
		// Constructor / Destructor
		DestructionListener();
		~DestructionListener();

		// b2DestructorListener | Events
		virtual void SayGoodbye(b2Fixture* fixture) override;
		virtual void SayGoodbye(b2Joint* joint) override;
};
