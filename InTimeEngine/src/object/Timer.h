#pragma once

// Dependencies | std
#include <chrono>

namespace IT {
	class Timer {
		private:
			// Properties
			std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

		public:
			// Constructor / Destructor
			Timer() = default;
			~Timer() = default;

			// Getters
			std::chrono::high_resolution_clock::time_point getStartTime() const;
	};
}