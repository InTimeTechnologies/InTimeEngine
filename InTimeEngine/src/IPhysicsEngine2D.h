#pragma once

// Dependencies | std
#include <list>

namespace IT {
	class IPhysicsEngine2D {
		// Friends
		friend class InTimeEngine;

		// Object
		public:
			// Constructor / Destructor
			IPhysicsEngine2D();
			virtual ~IPhysicsEngine2D();

		private:
			// Functions
			virtual void update(float timeStep) {};
	};
}
