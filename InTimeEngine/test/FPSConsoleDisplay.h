#pragma once

// Dependencies | InTimeEngine
#include "src/InTimeEngine.h"

namespace Test {
	class FPSConsoleDisplay : public IT::ICoreUpdate {
		// Object
		public:
			// Properties
			std::chrono::nanoseconds timeToPrint = std::chrono::nanoseconds(0);
			unsigned long long coreLastTickCount = 0LL;
			unsigned long long physicLastTickCount = 0LL;

			// Constructor / Destructor
			FPSConsoleDisplay() = default;
			~FPSConsoleDisplay() = default;

			// Engine events
			void onPreCoreUpdate() override;
	};
}
