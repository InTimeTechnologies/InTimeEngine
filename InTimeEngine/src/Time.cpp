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
 * Updated on: 13DEC2024
 *
 * Description:
 *  EngineTime has run time, core time and physics time.
 *  - Run time: The real time the engine is currently at the beginning of each
 *    loop iteration. It is used to update the other core and physics time.
 *  - Core time: The time used to synchronize all systems other than physics.
 *    By default, it will update at an uncapped rate, but it can be capped to
 *    update at a fixed rate. It can be set to update at a fixed rate or
 *    update each possible loop iteration (no recommended). The graphics engine
 *    will use this as its time to update.
 *    This time can be scaled up and down.
 *  - Physic update: The time used to update physics.
 *    By default, it will update at a fixed rate, but can be uncapped (not
 *    recommended)
 *    This time can be scaled up and down.
 *****************************************************************************/

#include "Time.h"

// class Time

// Object | private

// Functions
bool IT::Time::updateTime(const std::chrono::nanoseconds& time) {
	if (settings.fixedUpdate) {
		if (time - previousUpdateTime > settings.updateFrequency) {
			deltaTime = settings.updateFrequency;

			// Scale time
			scaledDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime * settings.scale);

			// Update times
			this->time += deltaTime;
			scaledTime += scaledDeltaTime;
			previousUpdateTime += deltaTime;
			tickCount++;

			return true; // Updated time
		}
		else {
			return false; // Did not update time
		}
	}
	else {
		deltaTime = time - previousUpdateTime;
		
		// Scale time
		scaledDeltaTime = std::chrono::duration_cast<std::chrono::nanoseconds>(deltaTime * settings.scale);

		// Update times
		this->time += deltaTime;
		scaledTime += scaledDeltaTime;
		previousUpdateTime = time;
		tickCount++;

		return true; // Updated time
	}
}
void IT::Time::resetTime(const std::chrono::nanoseconds& lastUpdateTime) {
	time = std::chrono::nanoseconds(0LL);
	deltaTime = std::chrono::nanoseconds(0LL);
	this->previousUpdateTime = lastUpdateTime;
}
void IT::Time::resetTickCount() {
	tickCount = 0ULL;
}

// Object | public

// Getters
std::chrono::nanoseconds IT::Time::getTime() const {
	return time;
}
std::chrono::nanoseconds IT::Time::getDeltaTime() const {
	return deltaTime;
}
std::chrono::nanoseconds IT::Time::getPreviousUpdateTime() const {
	return previousUpdateTime;
}
std::chrono::nanoseconds IT::Time::getScaledTime() const {
	return scaledTime;
}
std::chrono::nanoseconds IT::Time::getScaledDeltaTime() const {
	return scaledDeltaTime;
}
unsigned long long IT::Time::getTickCount() const {
	return tickCount;
}

// Functions
float IT::Time::getTimeF() const {
	return std::chrono::duration<float>(time).count();
}
float IT::Time::getDeltaTimeF() const {
	return std::chrono::duration<float>(deltaTime).count();
}
float IT::Time::getScaledTimeF() const {
	return std::chrono::duration<float>(scaledTime).count();
}
float IT::Time::getScaledDeltaTimeF() const {
	return std::chrono::duration<float>(scaledDeltaTime).count();
}

double IT::Time::getTimeD() const {
	return std::chrono::duration_cast<std::chrono::duration<double>>(time).count();
}
double IT::Time::getDeltaTimeD() const {
	return std::chrono::duration_cast<std::chrono::duration<double>>(deltaTime).count();
}
double IT::Time::getScaledTimeD() const {
	return std::chrono::duration<double>(scaledTime).count();
}
double IT::Time::getScaledDeltaTimeD() const {
	return std::chrono::duration<double>(scaledDeltaTime).count();
}


// class EngineTime

// Object | public

// Getters
std::chrono::high_resolution_clock::time_point IT::EngineTime::getStartTime() const {
	return startTime;
}
std::chrono::high_resolution_clock::time_point IT::EngineTime::getRunPreviousUpdateTime() const {
	return previousUpdateTime;
}
std::chrono::nanoseconds IT::EngineTime::getRunTime() const {
	return runTime;
}
std::chrono::nanoseconds IT::EngineTime::getRunDeltaTime() const {
	return runDeltaTime;
}

// Functions
void IT::EngineTime::updateRealTime() { // To-Do: Run test to make sure runDeltaTime and runTime and runPreviousUpdateTime are accurately counted
	std::chrono::high_resolution_clock::time_point now = std::chrono::high_resolution_clock::now();
	runTime = now - startTime;
	runDeltaTime = now - previousUpdateTime;
	previousUpdateTime = now;
}
