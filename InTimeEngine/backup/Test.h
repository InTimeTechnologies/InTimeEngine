// Dependencies | InTimeEngine
#include <src/InTimeEngine.h>

// Dependencies | std
#include <vector>

// Dependencies | Test
#include "FPSConsoleDisplay.h"

class Test {
	// Enum
	public:
		enum class TestType {
			TIME = 0,
			FPS_CONSOLE_DISPLAY,
			TEST_TYPE_COUNT
		};
	
	// Object
	private:	
		// Properties
		std::vector<bool> testsToRun = std::vector<bool>((int)TestType::TEST_TYPE_COUNT);

		// Functions
		bool isValidTest(TestType testType);

	public:
		// Constructor / Destructor
		Test() = default;
		~Test() = default;

		// Getters
		std::vector<TestType> getTestsToRun() const;

		// Setters
		void setTestToRun(TestType testType);
		void setTestsToRun(const std::vector<TestType>& testTypes);
		void unsetTestToRun(TestType testType);
		void unsetTestsToRun(const std::vector<TestType>& testTypes);

		// Functions
		void configureToTestEverything();
		void clearTests();
};

class ITest {
	// Enum
	public:
		enum class TestState {
			STOPPED,
			RUNNING,
			PAUSED
		};

	// Object
	public:
		// Properties
		TestState testState = TestState::STOPPED;

		// Constructor / Destructor
		ITest() = default;
		~ITest() = default;

		// Interface functions
		virtual void start() {};
		virtual void pause() {};
		virtual void resume() {};
		virtual void stop() {};
};
