#include "VulkanEngine.h"

// Dependencies | std
#include <iostream>

// class VulkanEngine

// Static | private

// Properties
IT::VulkanEngine* IT::VulkanEngine::singleton = nullptr;
#ifdef NDEBUG
const bool IT::VulkanEngine::VALIDATION_LAYERS_ENABLED = false;
#lese
const bool IT::VulkanEngine::VALIDATION_LAYERS_ENABLED = true;
#endif
bool IT::VulkanEngine::validationLayersAvailable = false;

// Static | public

// Getters
IT::VulkanEngine* IT::VulkanEngine::getSingleton() {
	return singleton;
}

// Object | public

// Constructor / Destructor
IT::VulkanEngine::VulkanEngine() {
	if (singleton == nullptr)
		singleton = this;

	// Create instance
	{
		applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		applicationInfo.pApplicationName = "Game Name";
		applicationInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		applicationInfo.pEngineName = "In Time Engine";
		applicationInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		applicationInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &applicationInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;
		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		createInfo.enabledExtensionCount = glfwExtensionCount;
		createInfo.ppEnabledExtensionNames = glfwExtensions;

		createInfo.enabledLayerCount = 0;

		VkResult vulkanResult = vkCreateInstance(&createInfo, nullptr, &instance);
		if (vulkanResult != VK_SUCCESS) {
			error = true;
			error = "Failed to create instance.";
			return;
		}
	}

	// Check for extension support
	{
		uint32_t extensionCount = 0;
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
		std::vector<VkExtensionProperties> extensions(extensionCount);
		vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
		std::cout << extensionCount << " extensions supported\n";
	}

	// Check validation layer support
	{
		std::vector<const char*> validationLayers = { "VK_LAYER_KHRONOS_validation" };
		uint32_t layerCount = 0;
		vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

		std::vector<VkLayerProperties> availableLayers(layerCount);
		vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

		for (const char* layerName : validationLayers) {
			bool layerFound = false;

			for (const auto& layerProperties : availableLayers) {
				if (strcmp(layerName, layerProperties.layerName) == 0) {
					layerFound = true;
					break;
				}
			}

			if (layerFound) {
				validationLayersAvailable = true;
				break;
			}
		}
	}
}
IT::VulkanEngine::~VulkanEngine() {
	vkDestroyInstance(instance, nullptr);

	if (singleton == this)
		singleton = nullptr;
}

// Functions
void IT::VulkanEngine::render() {

}
