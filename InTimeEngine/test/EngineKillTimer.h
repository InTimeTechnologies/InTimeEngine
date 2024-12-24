#pragma once

// Dependencies | InTimeEngine
#include "src/InTimeEngine.h"

namespace Test {
	class EngineKillTimer : public IT::ICoreUpdate {
		// Object
		public:
			// Constructor / Destructor
			EngineKillTimer() = default;
			~EngineKillTimer() = default;

			// Events
			void onPreCoreUpdate() override;
	};
}
