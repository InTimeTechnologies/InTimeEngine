#pragma once

// Dependencies | Box2D
#include <box2d/box2d.h>

// Dependencies | CoreEngine
#include <src/Component.h>

class FixtureB2D : public IT::Component {
	// Static
	public:
		// Proprties
		static b2FixtureDef defaultFixtureDefinition;

	// Object
	public:
		// Properties
		b2Fixture* fixture = nullptr;

		// Constructor / Destructor
		FixtureB2D(IT::GameObject& gameObject);
		FixtureB2D(IT::GameObject& gameObject, b2FixtureDef& fixtureDefinition);
		~FixtureB2D();
};
