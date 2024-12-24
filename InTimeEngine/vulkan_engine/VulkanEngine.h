#pragma once

// Dependencies | std
#include <string>
#include <vector>

// Dependencies | InTimeEngine
#include <src/IRenderer.h>

// Dependencies | Vulkan
#include <vulkan/vulkan.hpp>

// Dependencies | GLFW
#include <GLFW/glfw3.h>

namespace IT {
	class VulkanEngine : public IRenderer {
		// Static
		private:
			// Properties
			static VulkanEngine* singleton;
			static const bool VALIDATION_LAYERS_ENABLED;
			static bool validationLayersAvailable;

		public:
			// Getters
			static VulkanEngine* getSingleton();

		// Object
		private:
			// Properties
			bool error = false;
			std::string errorMessage = std::string("None");

		public:
			// Properties
			VkInstance instance;
			VkApplicationInfo applicationInfo {};
			
			// Constructor / Destructor
			VulkanEngine();
			~VulkanEngine();

			// Getters
			bool getError();
			std::string getErrorMessage();

			// Functions
			void render() override;
	};
}
