#pragma once

namespace IT {
	class IRenderer {
		// Static
		private:
			// Properties
			static IRenderer* singleton;

		public:
			// Getters
			static IRenderer* getSingleton();

		// Object
		public:
			// Constructor / Destructor
			IRenderer();
			~IRenderer();

			// Functions
			virtual void render();
	};
}
