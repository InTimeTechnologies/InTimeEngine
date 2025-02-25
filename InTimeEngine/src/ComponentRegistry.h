#pragma once

// Dependencies | std
#include <vector>
#include <functional>

// Dependencies | InTimeEngine
#include "GameObject.h"
#include "Component.h"

// Dependencies | Utility
#include <utility/IDFactory.h>

// Dependencies | jsoncpp
#include <jsoncpp/json.hpp>

// Forward declarations | InTimeEngine
class IT::GameObject;

namespace IT {
	class EntityRegistry {
		// Friends
		friend class InTimeEngine;

		// Structs
		public:
			struct EngineEntry {
				int componentTypeID = -1;
				const type_info* typeInfo = &typeid(nullptr);
				std::function<Component* (GameObject&)> factory = std::function<Component * (GameObject&)>();
				std::function <nlohmann::ordered_json(Component*)> toJSON;
				std::function <Component* (GameObject& gameObject, const nlohmann::ordered_json& json)> fromJSON;
			};
			struct Entry {
				// Properties
				int componentTypeID = -1;
				const type_info& typeInfo = typeid(nullptr);
				std::function<Component* (GameObject&)> factory = std::function<Component * (GameObject&)>();
				std::function <nlohmann::ordered_json (Component*)> serialize;
				std::function <Component* (const nlohmann::ordered_json& json)> deserialize;
			};

		public:
			// Enumerations
			enum class ComponentID {
				EMPTY_COMPONENT = 0,
				LAST_COMPONENT
			};

		// Object
		private:
			// Properties
			std::vector<EngineEntry> engineEntries = std::vector<EngineEntry>(0);

			// Functions
			bool registerComponent(const EngineEntry& engineEntry);

		public:
			// Properties
			std::vector<Entry> entries = std::vector<Entry>(0);

			// Constructor / Destructor
			EntityRegistry();
			~EntityRegistry() = default;

			// Getters
			std::vector<EngineEntry> getEngineEntries() const;
			std::vector<Entry> getEntries() const;

			// Functions
			bool registerComponent(const Entry& entry);
			nlohmann::ordered_json serialize(Component* component);
			Component* deserialize(GameObject& gameObject, const nlohmann::ordered_json& json);

		// Static
		public:
			// Functions
			static nlohmann::ordered_json getJSONTemplate(const Component& component);

	};
}
