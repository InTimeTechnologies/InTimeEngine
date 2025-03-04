#pragma once

// Dependencies | std
#include <list>
#include <utility>

class IDFactory {
	// Object
	private:
		// Properties
		std::list<std::pair<int, int>> idRangeList = std::list<std::pair<int, int>>();
		int registeredIdsCount = 1;
		int idsAvailableCount = 1;

	public:
		// Constructor / Destructor
		IDFactory();
		IDFactory(int idCount);
		~IDFactory();

		// Getters
		std::list<std::pair<int, int>> getIdRangeList() const;
		int getRegisteredIdsCount() const;
		int getIdsAvailableCount() const;

		// Functions
		bool increaseIdLimit(int idAmount);
		int extractID();
		bool insertID(int id);
};