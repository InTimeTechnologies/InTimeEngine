#pragma once

// Dependencies | InTimeEngine
#include "src/Component.h"

class TestEmptyComponent1 : public IT::Component {
	// Object
	public:
		// Constructor / Destructor
		TestEmptyComponent1(IT::GameObject& gameObject) : Component(gameObject, typeid(TestEmptyComponent1)) {}
		virtual ~TestEmptyComponent1() {}
};
