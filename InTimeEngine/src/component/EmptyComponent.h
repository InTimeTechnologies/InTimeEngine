#pragma once

// Dependencies | InTimeEngine
#include "../InTimeEngine.h"

namespace IT {
	class EmptyComponent : public Component {
		public:
			// Constructor / Destructor
			EmptyComponent(GameObject& gameObject) : Component(gameObject, typeid(EmptyComponent)) {};
			~EmptyComponent() = default;
	};
}