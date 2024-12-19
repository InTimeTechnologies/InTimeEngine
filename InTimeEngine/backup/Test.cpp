#include "Test.h"

// class Test

// Object | private

// Getters
bool Test::isValidTest(TestType testType) {
	int testTypeInteger = (int)testType;
	return (testTypeInteger > 0 && testTypeInteger < (int)TestType::TEST_TYPE_COUNT) ? true : false;
}

// Object | public

// Getters
std::vector<Test::TestType> Test::getTestsToRun() const {
	std::vector<TestType> testsToRun = std::vector<TestType>();
	for (int i = 0; i < (int)TestType::TEST_TYPE_COUNT; i++)
		if (this->testsToRun[i])
			testsToRun[i] = (TestType)i;

	return testsToRun;
}

// Setters
void Test::setTestToRun(TestType testType) {
	if (!isValidTest(testType))
		return;

	int testIndex = (int)testType;
	testsToRun[testIndex] = true;
}
void Test::setTestsToRun(const std::vector<TestType>& testTypes) {
	for (TestType testType : testTypes) {
		if (!isValidTest(testType))
			continue;

		int testIndex = (int)testType;
		testsToRun[testIndex] = true;
	}
}
void Test::unsetTestToRun(TestType testType) {
	if (!isValidTest(testType))
		return;

	int testIndex = (int)testType;
	testsToRun[testIndex] = false;
}
void Test::unsetTestsToRun(const std::vector<TestType>& testTypes) {
	for (TestType testType : testTypes) {
		if (!isValidTest(testType))
			continue;

		int testIndex = (int)testType;
		testsToRun[testIndex] = false;
	}
}


// Functions
void Test::configureToTestEverything() {
	for (int i = 0; i < (int)TestType::TEST_TYPE_COUNT; i++)
		testsToRun[i] = true;
}
void Test::clearTests() {
	for (int i = 0; i < (int)TestType::TEST_TYPE_COUNT; i++)
		testsToRun[i] = false;
}
