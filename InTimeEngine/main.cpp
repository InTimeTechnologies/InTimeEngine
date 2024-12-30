// Dependencies | std
#include <iostream>
#include <filesystem>

// Dependencies | InTimeEngine
#include "src/InTimeEngine.h"

// Dependencies | Box2DEngine
#include "box2d_engine/Box2DEngine.h"

// Dependencies | Vulkan
#include <vulkan_engine/VulkanEngine.h>

// Dependencies | GLFW
#include "glfw_system/System.h"

// Dependencies | Test
#include "test/FPSConsoleDisplay.h"
#include "test/GameObjectTest.h"

int main(int argc, char* argv[]) {
	std::cout << "Program operating" << std::endl;

	// Create Box2D engine
	Box2DEngine* box2DEngine = new Box2DEngine();

	// Create GLFW window system
	GLFW::System glfwSystem = GLFW::System();
	GLFW::Window window = GLFW::Window();

	// Create Vulkan engine
	IT::VulkanEngine vulkanEngine = IT::VulkanEngine();

	// Closed in brakets for memory test
	{
		// Create In Time Engine
		std::filesystem::path applicationDirectoryPath = std::filesystem::path(argv[0]).parent_path();
		IT::InTimeEngine* engine = new IT::InTimeEngine(applicationDirectoryPath); // Allocated in heap for memory test

		// Create test cases
		Test::FPSConsoleDisplay fpsCounterDisplay = Test::FPSConsoleDisplay();
		Test::GameObjectTest gameObjectTest = Test::GameObjectTest();

		// Set timer to stop the engine
		IT::Timer engineKillTimer = IT::Timer(std::chrono::seconds(10));
		engineKillTimer.function = []() { IT::InTimeEngine::getSingleton()->stop(); };
		engineKillTimer.start();

		// Run engine
		engine->run();

		// Clean resources
		delete(engine); // Calling delete to run memory test
	}

	std::cout << "Program terminating" << std::endl;
}
