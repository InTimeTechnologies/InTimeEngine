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
#include "glfw_interface/GLFWWindow.h"

// Dependencies | Test
#include "test/FPSConsoleDisplay.h"
#include "test/GameObjectTest.h"
#include "test/EngineKillTimer.h"

int main(int argc, char* argv[]) {
	std::cout << "Program operating" << std::endl;

	// Closed in brakets for memory test
	{
		// Create In Time Engine
		std::filesystem::path applicationDirectoryPath = std::filesystem::path(argv[0]).parent_path();
		IT::InTimeEngine* engine = new IT::InTimeEngine(applicationDirectoryPath); // Allocated in heap for memory test

		// Create Box2D Engine
		Box2DEngine* box2DEngine = new Box2DEngine();

		// Create Vulkan engine
		IT::VulkanEngine vulkanEngine = IT::VulkanEngine();

		// Create window
		GLFWWindow window = GLFWWindow();

		// Create test cases
		Test::FPSConsoleDisplay fpsCounterDisplay = Test::FPSConsoleDisplay();
		Test::GameObjectTest gameObjectTest = Test::GameObjectTest();
		Test::EngineKillTimer engineKillTimer = Test::EngineKillTimer();

		// Run engine
		engine->run();

		// Clean resources
		delete(engine); // Calling delete to run memory test
	}

	// Clean resources
	glfwTerminate();

	std::cout << "Program terminating" << std::endl;
}
