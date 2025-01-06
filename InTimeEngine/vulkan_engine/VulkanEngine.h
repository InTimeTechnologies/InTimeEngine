#pragma once

// Dependencies | std
#include <string>
#include <vector>
#include <optional>
#include <set>

// Dependencies | InTimeEngine
#include <src/IRenderer.h>

// Dependencies | Vulkan
#include <vulkan/vulkan.hpp>

// Dependencies | GLFW
#include <GLFW/glfw3.h>

namespace IT {
	class VulkanEngine : public IRenderer {
		// Structures
		public:
			struct QueueFamilyIndices {
				std::optional<uint32_t> graphicsFamily;
				std::optional<uint32_t> presentFamily;

				bool isComplete() const {
					return graphicsFamily.has_value() && presentFamily.has_value();
				}
			};

			struct SwapChainSupportDetails {
				VkSurfaceCapabilitiesKHR capabilities;
				std::vector<VkSurfaceFormatKHR> formats;
				std::vector<VkPresentModeKHR> presentModes;
			};

		// Static
		private:
			// Properties
			static VulkanEngine* s_singleton;
			static std::vector<const char*> s_validationLayersToEnable;
			static std::vector<std::string> s_availableValidationLayers;
			static std::vector<const char*> s_extensionsToEnable;

			// Functions
			static std::vector<const char*> s_getGLFWRequiredExtensions();

		public:
			// Properties
			static bool s_enableValidationLayers;

			// Getters
			static VulkanEngine* s_getSingleton();
			static std::vector<std::string> s_getAvailableValidationLayers();
			static std::vector<const char*> s_getValidationLayersToEnable();

			// Functions
			static void s_init();

		// Object
		private:
			// Properties
			bool error = false;
			std::string errorMessage = std::string("None");

			// Properties
			GLFWwindow* glfwWindow = nullptr;

			VkApplicationInfo applicationInfo {};
			VkInstance instance;
			VkDebugUtilsMessengerEXT debugMessenger;
			VkPhysicalDevice physicalDevice = VK_NULL_HANDLE; // Deleted through VkInstance object when it is deleted
			VkDevice vulkanDevice;
			VkQueue graphicsQueue; // Deleted through VkInstance object when it is deleted
			VkSurfaceKHR surface;
			VkQueue presentQueue;
			VkSwapchainKHR swapChain;
			std::vector<VkImage> swapChainImages;
			VkFormat swapChainImageFormat;
			VkExtent2D swapChainExtent;

			std::vector<VkImageView> swapChainImageViews;

			// Functions
			void createVulkanInstance();
			void initDebugMessenger();
			void pickPhysicalDevice();
			bool isPhysicalDeviceSuitable(VkPhysicalDevice device);
			QueueFamilyIndices findQueueFamilies(VkPhysicalDevice physicalDevice);
			void createLogicalDevice();
			void createSurface();
			bool checkDeviceExtensionSupport(VkPhysicalDevice physicalDevice);
			SwapChainSupportDetails querySwapChainSupport(VkPhysicalDevice device);
			VkSurfaceFormatKHR chooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
			VkPresentModeKHR chooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
			VkExtent2D chooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
			void createSwapChain();
			void createImageViews();

			void createGraphicsPipeline();

		public:
			// Constructor / Destructor
			VulkanEngine(GLFWwindow* glfwWindow);
			~VulkanEngine();

			// Functions
			void render() override;
	};
}
