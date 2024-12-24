#pragma once

// Dependencies | std
#include <vector>

// Dependencies | InTimeEngine
#include <src/InTimeEngine.h>

namespace Test {
	class GameObjectTest {
		// Object
		public:
			// Properties
			IT::GameObject stackGameObject = IT::GameObject("Stack Game Object");
			IT::EmptyComponent stackEmptyComponent = IT::EmptyComponent(stackGameObject);

			IT::GameObject* heapGameObject = new IT::GameObject("Heap Game Object");
			IT::EmptyComponent* heapEmptyComponent = new IT::EmptyComponent(*heapGameObject);

			// Constructor / Destructor
			GameObjectTest();
			~GameObjectTest();
	};
}
