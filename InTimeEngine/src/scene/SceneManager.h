#pragma once

// Dependencies | std
#include <vector>
#include <filesystem>
#include <fstream>

// Dependencies | jsoncpp
#include <jsoncpp/json.hpp>

// Dependencies | InTimeEngine
#include "../InTimeEngine.h"

namespace IT {
	struct SceneManager {
		// Properties
		std::vector<GameObject*> gameObjects;
		std::vector<Component*> components;

		// Constructor / Destructor
		SceneManager() = default;
		~SceneManager() = default;

		// Functions
		bool loadSceneFromJSON(const std::filesystem::path& pathToJSONScene);
		bool saveSceneAsJSON(const std::filesystem::path& pathToJSONScene);
		void destoyScene();
	};
}
