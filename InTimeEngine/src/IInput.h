#pragma once

// Dependencies | std
#include <functional>

namespace IT {
	class IInput {
		// Static
		public:
			// Properties
			static std::function<void()> resetJoystickInputFunction;
			static std::function<void()> processInput;

			// Functions
			static void emptyVoidFunction();
	};
}