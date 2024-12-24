#include "FPSConsoleDisplay.h"

// Dependencies | std
#include <iostream>

// class FPSConsoleDisplay

// Object | public

// Functions
void Test::FPSConsoleDisplay::onPreCoreUpdate() {
	IT::Time* coreTime = &IT::InTimeEngine::getSingleton()->coreTime;
	IT::Time* physicsTime = &IT::InTimeEngine::getSingleton()->physicsTime;
	
	if (coreTime->getTime() > timeToPrint) {
		unsigned long long coreTickCount = coreTime->getTickCount() - coreLastTickCount;
		unsigned long long physicsTickCount = physicsTime->getTickCount() - physicLastTickCount;

		std::cout << "Time report:\n";
		std::cout << "    Core time:\n";
		std::cout << "        Time:        " << coreTime->getTime() << "\n";
		std::cout << "        Scaled time: " << coreTime->getScaledTime() << "\n";
		std::cout << "        Tick count:  " << coreTickCount << "\n";
		std::cout << "    Physics time:\n";
		std::cout << "        Time:        " << physicsTime->getTime() << "\n";
		std::cout << "        Scaled time: " << physicsTime->getScaledTime() << "\n";
		std::cout << "        Tick count:  " << physicsTickCount << std::endl;

		coreLastTickCount = coreTime->getTickCount();
		physicLastTickCount = physicsTime->getTickCount();

		timeToPrint += std::chrono::seconds(1);
	}
}
