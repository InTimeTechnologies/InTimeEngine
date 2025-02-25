#pragma once

// Dependencies | InTimeEngine
#include "src/Component.h"

class TestEmptyComponent2 : public IT::Component {
	// Object
	public:
		// Constructor / Destructor
		TestEmptyComponent2(IT::GameObject& gameObject) : Component(gameObject, typeid(TestEmptyComponent2)) {}
		virtual ~TestEmptyComponent2() {}
};
