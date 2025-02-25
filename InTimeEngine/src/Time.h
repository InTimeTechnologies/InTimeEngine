/******************************************************************************
 * Copyright (c) 2024 Christopher Barrios Agosto. All Rights Reserved.
 *
 * Licensing Information:
 *  This software and associated documentation files (the "Software") may not
 *  be used, copied, modified, merged, published, distributed, sublicensed,
 *  or sold without the prior written permission of the copyright owner.
 *
 *  Unauthorized use of this file, via any medium, is strictly prohibited.
 *****************************************************************************/

/******************************************************************************
 * Project: In Time Engine
 * File: Time.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  class Time:
 *   Used to synchronize systems such as core engine systems and physics.
 *   Has the ability to update every frame or on a fixed manner E.g 60 FPS.
 *   Has the ability to scale time up and down.
 *  class EngineTime:
 *   Used to track real time of each engine loop iteration and update other
 *   Time objects using the current EngineTime's real time.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <chrono>

// 1sec == 1,000,000,000ns

namespace IT {
	class RealTime {
		// Friends
		friend class InTimeEngine;

		// Object
		private:
			// Properties
			std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::time_point();
			std::chrono::high_resolution_clock::time_point previousUpdateTime = std::chrono::high_resolution_clock::time_point();
			std::chrono::nanoseconds runTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds runDeltaTime = std::chrono::nanoseconds(0LL);

		public:
			// Constructor / Destructor
			RealTime() = default;
			~RealTime() = default;

			// Getters
			std::chrono::high_resolution_clock::time_point getStartTime() const;
			std::chrono::high_resolution_clock::time_point getRunPreviousUpdateTime() const;
			std::chrono::nanoseconds getRunTime() const;
			std::chrono::nanoseconds getRunDeltaTime() const;

			// Functions
			void updateRealTime();
	};

	class Time {
		// Friends
		friend class InTimeEngine;

		// Object
		protected:
			// Properties
			std::chrono::nanoseconds time = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds deltaTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds scaledTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds scaledDeltaTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds previousRealTimeUpdate = std::chrono::nanoseconds(0LL);
			unsigned long long tickCount = 0ULL;
			double scale = 1.0;

			// Functions
			bool shouldUpdate(const std::chrono::nanoseconds& realTime);
			bool update(const std::chrono::nanoseconds& realTime);
			void resetTime(const std::chrono::nanoseconds& lastUpdateTime);
			void resetTickCount();
			std::chrono::nanoseconds nextTimeToUpdate() const;

		public:
			// Properties
			std::chrono::nanoseconds updateFrequency = std::chrono::nanoseconds(0);
			bool fixed = false;

			// Constructor / Destructor
			Time() = default;
			Time(std::chrono::nanoseconds updateFrequency, bool fixed) : updateFrequency(updateFrequency), fixed(fixed) {}
			~Time() = default;

			// Getters
			std::chrono::nanoseconds getTime() const;
			std::chrono::nanoseconds getDeltaTime() const;
			std::chrono::nanoseconds getScaledTime() const;
			std::chrono::nanoseconds getScaledDeltaTime() const;
			std::chrono::nanoseconds getPreviousUpdateTime() const;
			unsigned long long getTickCount() const;

			// Functions
			float getTimeF() const;
			float getDeltaTimeF() const;
			float getScaledTimeF() const;
			float getScaledDeltaTimeF() const;

			double getTimeD() const;
			double getDeltaTimeD() const;
			double getScaledTimeD() const;
			double getScaledDeltaTimeD() const;
	};
}
