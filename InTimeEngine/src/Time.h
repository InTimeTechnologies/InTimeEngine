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

// Note 1sec == 1000000000ns

namespace IT {
	class Time {
		// Friends
		friend class InTimeEngine;

		// Internal structs
		struct TimeSettings {
			// Properties
			double scale = 1.0;
			std::chrono::nanoseconds updateFrequency = std::chrono::nanoseconds(16666666); // 1 / 60 (60 FPS)
			bool fixedUpdate = false;
		};

		// Object
		private:
			// Properties
			std::chrono::nanoseconds time = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds deltaTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds scaledTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds scaledDeltaTime = std::chrono::nanoseconds(0LL);
			std::chrono::nanoseconds previousUpdateTime = std::chrono::nanoseconds(0LL);
			unsigned long long tickCount = 0ULL;

			// Functions
			bool updateTime(const std::chrono::nanoseconds& runTime);
			void resetTime(const std::chrono::nanoseconds& lastUpdateTime);
			void resetTickCount();

		public:
			// Properties
			TimeSettings settings = TimeSettings();

			// Constructor / Destructor
			Time() = default;
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

	class EngineTime {
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
			EngineTime() = default;
			~EngineTime() = default;

			// Getters
			std::chrono::high_resolution_clock::time_point getStartTime() const;
			std::chrono::high_resolution_clock::time_point getRunPreviousUpdateTime() const;
			std::chrono::nanoseconds getRunTime() const;
			std::chrono::nanoseconds getRunDeltaTime() const;

			// Functions
			void updateRealTime();
	};
}
