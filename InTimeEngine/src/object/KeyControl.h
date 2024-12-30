#pragma once

// Dependencies | InTimeEngine
#include <src/InTimeEngine.h>
#include <glfw_system/System.h>

// Dependencies | std
#include <vector>
#include <functional>
#include <iostream>

namespace IT {
	class KeyControl : public ICoreUpdate {
		public:
			// Properties
			std::vector<GLFW::KeyCode> keysToMatch;
			std::function<void()> function;

			// Constructor / Destructor
			KeyControl() = default;
			~KeyControl() = default;

			// Events
			void onPreCoreUpdate() override {
				if (!static_cast<bool>(function))
					return;

				std::list<GLFW::Window*> windowList = GLFW::Window::getWindowList();
				if (windowList.size() == 0)
					return;

				GLFW::Input& input = windowList.front()->input;
				for (GLFW::KeyCode& keyCode : keysToMatch)
					if (!input.getKey(keyCode).pressed)
						return;

				function();
			}
			void onPostCoreUpdate() override {
				// Ignored
			}
	};
}
