#pragma once

// Dependencies | std
#include <functional>
#include <list>

namespace IT {
	class IWindow {
		// Friends
		friend class InTimeEngine;

		// Static
		protected:
			// Properties
			static std::list<IWindow*> windowList;

		public:
			// Properties
			static std::function<void()> pollEventsFunction;
			static std::function<void()> resetKeyboardInputFunction;

			// Functions
			static void emptyVoidFunction();

		// Object
		protected:
			// Properties
			std::list<IWindow*>::iterator node;

		public:
			// Constructor / Destructor
			IWindow();
			virtual ~IWindow();

			// Functions
			virtual void swapBuffers();
	};
}
