#include "FPSConsoleDisplay.h"

// Dependencies | std
#include <iostream>

// class FPSConsoleDisplay

// Object | public

// Functions
void Test::FPSConsoleDisplay::onPreCoreUpdate() {
	IT::Time* coreTime = &IT::InTimeEngine::s_getSingleton()->time;
	IT::Time* fixedTime = &IT::InTimeEngine::s_getSingleton()->fixedTime;
	
	if (coreTime->getTime() > timeToPrint) {
		unsigned long long coreTickCount = coreTime->getTickCount() - coreLastTickCount;
		unsigned long long physicsTickCount = fixedTime->getTickCount() - physicLastTickCount;

		std::cout << "Time report:\n";
		std::cout << "    Time:\n";
		std::cout << "        Time:        " << coreTime->getTime() << "\n";
		std::cout << "        Scaled time: " << coreTime->getScaledTime() << "\n";
		std::cout << "        Tick count:  " << coreTickCount << "\n";
		std::cout << "    Fixed time:\n";
		std::cout << "        Time:        " << fixedTime->getTime() << "\n";
		std::cout << "        Scaled time: " << fixedTime->getScaledTime() << "\n";
		std::cout << "        Tick count:  " << physicsTickCount << std::endl;

		coreLastTickCount = coreTime->getTickCount();
		physicLastTickCount = fixedTime->getTickCount();

		timeToPrint += std::chrono::seconds(1);
	}
}
