// Dependencies | std
#include <iostream>
#include <filesystem>

// Dependencies | InTimeEngine
#include "src/InTimeEngine.h"

// Dependencies | Box2DEngine
#include "box2d_engine/Box2DEngine.h"

// Dependencies | Vulkan
#include <vulkan_engine/VulkanEngine.h>

// Dependencies | GLFW system
#include "glfw_system/System.h"

// Dependencies | Test
#include "test/FPSConsoleDisplay.h"
#include "test/GameObjectTest.h"
#include "test/TestEmptyComponent1.h"
#include "test/TestEmptyComponent2.h"

int main(int argc, char* argv[]) {
	std::cout << "Program operating" << std::endl;

	// Test
	{
		std::cout << typeid(nullptr).name() << std::endl;
	}

	{
		// Create Box2D engine
		Box2DEngine* box2DEngine = new Box2DEngine();

		// Create GLFW window system
		GLFW::System glfwSystem = GLFW::System();
		GLFW::Window window = GLFW::Window();

		// Create Vulkan engine
		IT::Vulkan::VulkanEngine::s_init();
		IT::Vulkan::VulkanEngine vulkanEngine = IT::Vulkan::VulkanEngine(window.getWindow());
		window.renderer = &vulkanEngine;	

		IT::Vulkan::ShaderModule vertexShaderModule = IT::Vulkan::ShaderModule();
		vertexShaderModule.create(std::filesystem::path("D:\\source\\vs_repos\\InTimeEngine\\InTimeEngine\\shader_out\\triangle\\triangle.vert.spv"));

		IT::Vulkan::ShaderModule fragmentShaderModule = IT::Vulkan::ShaderModule();
		fragmentShaderModule.create(std::filesystem::path("D:\\source\\vs_repos\\InTimeEngine\\InTimeEngine\\shader_out\\triangle\\triangle.frag.spv"));
		
		// Closed in brakets for memory test
		{
			// Create In Time Engine
			std::filesystem::path applicationDirectoryPath = std::filesystem::path(argv[0]).parent_path();
			IT::InTimeEngine* engine = new IT::InTimeEngine(applicationDirectoryPath); // Allocated in heap for memory test

			// Create test cases
			Test::FPSConsoleDisplay fpsCounterDisplay = Test::FPSConsoleDisplay();
			Test::GameObjectTest gameObjectTest = Test::GameObjectTest();

			// Set engine killer
			IT::KeyControl engineKiller = IT::KeyControl();
			engineKiller.keysToMatch = { GLFW::KeyCode::LEFT_SHIFT, GLFW::KeyCode::ESCAPE };
			engineKiller.function = []() { IT::InTimeEngine::s_getSingleton()->stop(); };

			// To-Do: Delete post-test
			//{
			//	IT::GameObject gameObject1 = IT::GameObject(1, "Game Object 1");
			//	IT::GameObject gameObject2 = IT::GameObject(2, "Game Object 2");
			//	IT::GameObject gameObject3 = IT::GameObject(3, "Game Object 3");
			//	gameObject3.transform.setParent(&gameObject2.transform);
			//	IT::EmptyComponent emptyComponent1(gameObject1);
			//	IT::EmptyComponent emptyComponent2(gameObject1);
			//	IT::EmptyComponent emptyComponent3(gameObject2);
			//	IT::EmptyComponent emptyComponent4(gameObject2);
			//	IT::EmptyComponent emptyComponent5(gameObject3);
			//	IT::EmptyComponent emptyComponent6(gameObject3);
			//	IT::EmptyComponent testEmptyComponent1(gameObject1);
			//	IT::EmptyComponent testEmptyComponent2(gameObject2);
			//	IT::EmptyComponent testEmptyComponent3(gameObject3);

			//	IT::SceneManager sceneManager = IT::SceneManager();
			//	sceneManager.gameObjects.push_back(&gameObject1);
			//	sceneManager.gameObjects.push_back(&gameObject2);
			//	sceneManager.gameObjects.push_back(&gameObject3);
			//	sceneManager.saveSceneAsJSON("D:\\source\\vs_repos\\InTimeEngine\\InTimeEngine\\scenes\\scene0.json");
			//}
			//{
			//	IT::SceneManager sceneManager = IT::SceneManager();
			//	sceneManager.loadSceneFromJSON("D:\\source\\vs_repos\\InTimeEngine\\InTimeEngine\\scenes\\scene0.json");
			//	std::cout << "Finished loading scene0";
			//}
			
			
			// Vertex buffer
			VkBufferCreateInfo vertexBufferCreateInfo{};
			vertexBufferCreateInfo.sType = VK_STRUCTURE_TYPE_BUFFER_CREATE_INFO;
			vertexBufferCreateInfo.size = sizeof(vulkanEngine.vertices[0]) * vulkanEngine.vertices.size();
			vertexBufferCreateInfo.usage = VK_BUFFER_USAGE_VERTEX_BUFFER_BIT;
			vertexBufferCreateInfo.sharingMode = VK_SHARING_MODE_EXCLUSIVE;

			IT::Vulkan::Buffer vertexBuffer = IT::Vulkan::Buffer(vertexBufferCreateInfo, (void*)vulkanEngine.vertices.data(), 0ULL, vertexBufferCreateInfo.size, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT);
			vulkanEngine.vertexBuffer = &vertexBuffer;

			//IT::SceneManager jsonSceneSaver = IT::SceneManager();
			//jsonSceneSaver.gameObjects.push_back(&gameObject1);
			//jsonSceneSaver.gameObjects.push_back(&gameObject2);
			//jsonSceneSaver.gameObjects.push_back(&gameObject3);
			//std::filesystem::path pathToScene = std::filesystem::path("D:\\source\\vs_repos\\InTimeEngine\\InTimeEngine\\scenes\\game_object_test.json");
			//jsonSceneSaver.saveSceneAsJSON(std::filesystem::path(pathToScene));

			// Run engine
			engine->run();

			// Clean resources
			delete(engine); // Calling delete to run memory test
		}
	}

	std::cout << "Program terminating" << std::endl;
}
