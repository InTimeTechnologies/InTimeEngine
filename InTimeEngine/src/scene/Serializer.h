#pragma once

// Dependencies | std
#include <utility>

// Dependencies | jsoncpp
#include <jsoncpp/json.hpp>

// Dependencies | InTimeEngine
#include "../InTimeEngine.h"

// Dependencies | InTimeEngine
#include "../ComponentType.h"

namespace IT {
	class Serializer {
		// Static
		public:
			// Inner classes
			struct Key {
				public:
					// Properties
					static const std::string GAME_OBJECTS;
					static const std::string TRANSFORM_RELATIONSHIPS;
					static const std::string COMPONENTS;

					static const std::string SCENE_INDEX;
					static const std::string ID;
					static const std::string NAME;
					static const std::string DELETE_ON_DESTROY;
					static const std::string TRANSFORM;
					static const std::string POSITION;
					static const std::string ROTATION;
					static const std::string SCALE;
					static const std::string PARENT;
					static const std::string DATA;
					static const std::string GAME_OBJECT;
					static const std::string TYPE_INFO;
					static const std::string COMPONENT_TYPE;
			};

			// Functions | Serialize
			static nlohmann::ordered_json s_serializeGameObject(IT::GameObject* gameObject);
			static nlohmann::ordered_json s_serializeTransformRelationship(IT::GameObject* gameObject, const std::vector<GameObject*> gameObjects);
			static nlohmann::ordered_json s_serializeComponent(IT::Component* component);
			static nlohmann::ordered_json s_serializeComponentData(IT::Component* component);
			static nlohmann::ordered_json s_serializeEmptyComponent(IT::EmptyComponent* component);

			// Functions | Deserialize
			static GameObject* s_deserializeGameObject(const nlohmann::ordered_json& json);
			static void s_deserializeTransformRelationship(const nlohmann::ordered_json& json, const std::vector<GameObject*> gameObjects);
			static Component* s_deserializeComponent(const nlohmann::ordered_json& json, const std::vector<GameObject*> gameObjects);
			static EmptyComponent* s_deserializeEmptyComponentData(const nlohmann::ordered_json& json, IT::GameObject* gameObject);
	};
}
