#include "Serializer.h"

// Test
#include <iostream>

// struct Serializer::Key

// Static | public

// Properties
const std::string IT::Serializer::Key::GAME_OBJECTS = "gameObjects";
const std::string IT::Serializer::Key::TRANSFORM_RELATIONSHIPS = "transformRelationships";
const std::string IT::Serializer::Key::COMPONENTS = "components";

const std::string IT::Serializer::Key::SCENE_INDEX = "sceneIndex";
const std::string IT::Serializer::Key::ID = "id";
const std::string IT::Serializer::Key::NAME = "name";
const std::string IT::Serializer::Key::DELETE_ON_DESTROY = "deleteOnDestroy";
const std::string IT::Serializer::Key::TRANSFORM = "transform";
const std::string IT::Serializer::Key::POSITION = "position";
const std::string IT::Serializer::Key::ROTATION = "rotation";
const std::string IT::Serializer::Key::SCALE = "scale";
const std::string IT::Serializer::Key::PARENT = "parent";
const std::string IT::Serializer::Key::DATA = "data";
const std::string IT::Serializer::Key::GAME_OBJECT = "gameObject";
const std::string IT::Serializer::Key::TYPE_INFO = "typeInfo";
const std::string IT::Serializer::Key::COMPONENT_TYPE = "componentType";

// class Serializer

// Object | public

// Functinos | Serialize
nlohmann::ordered_json IT::Serializer::s_serializeGameObject(IT::GameObject* gameObject) {
	// Validate game object
	if (gameObject == nullptr || gameObject->sceneIndex < 0)
		return nlohmann::ordered_json::object(); // Fail

	// Get reference of transform to simplify and optimize code
	const Transform& transform = gameObject->transform;

	// Serialize game object
	nlohmann::ordered_json json {
		{Key::SCENE_INDEX, gameObject->sceneIndex},
		{Key::ID, gameObject->id},
		{Key::NAME, gameObject->name},
		{Key::DELETE_ON_DESTROY, gameObject->deleteOnDestroy},
		{Key::TRANSFORM, {
			{Key::POSITION, { transform.position.x, transform.position.y, transform.position.z }},
			{Key::ROTATION, { transform.rotation.x, transform.rotation.y, transform.rotation.z }},
			{Key::SCALE, { transform.scale.x, transform.scale.y, transform.scale.z }}
		}}
	};

	return json; // Success
}
nlohmann::ordered_json IT::Serializer::s_serializeTransformRelationship(IT::GameObject* gameObject, const std::vector<GameObject*> gameObjects) {
	// Validate game object
	if (gameObject == nullptr || gameObject->sceneIndex < 0)
		return nlohmann::ordered_json::object(); // Fail

	// Get parent pointer to simplify and optimize code
	Transform* parent = gameObject->transform.getParent();

	// Serialize transform parent, child relationship
	nlohmann::ordered_json json{
		{Key::SCENE_INDEX, gameObject->sceneIndex},
		{Key::PARENT, parent == nullptr ? -1 : parent->getGameObject().sceneIndex}
	};

	return json; // Success
}
nlohmann::ordered_json IT::Serializer::s_serializeComponent(IT::Component* component) {
	// Validate comnponent
	if (component == nullptr || component->sceneIndex < 0 || component->getGameObject().sceneIndex < 0)
		return nlohmann::ordered_json::object(); // Fail

	// Serialize component
	nlohmann::ordered_json componentJSON{
		{Key::SCENE_INDEX, component->sceneIndex},
		{Key::GAME_OBJECT, component->getGameObject().sceneIndex},
		{Key::COMPONENT_TYPE, static_cast<int>(component->getComponentType())},
		{Key::TYPE_INFO, component->getTypeInfo().name()},
		{Key::DATA, s_serializeComponent(component)}
	};

	return componentJSON; // Success
}
nlohmann::ordered_json IT::Serializer::s_serializeComponentData(IT::Component* component) {
	// Validate component
	if (component == nullptr || component->sceneIndex < 0)
		return nlohmann::ordered_json::object(); // Fail

	// Choose the function in charge of serializing the type of component provided
	switch (component->getComponentType()) {
		case ComponentType::EMPTY_COMPONENT:
			return s_serializeEmptyComponent((EmptyComponent*)component); // Success
		case ComponentType::COMPONENT:
		default:
			return nlohmann::ordered_json::object(); // Fail
	}
}
nlohmann::ordered_json IT::Serializer::s_serializeEmptyComponent(IT::EmptyComponent* component) {
	return nlohmann::ordered_json::object();
}

// Functinos | Deserialize
IT::GameObject* IT::Serializer::s_deserializeGameObject(const nlohmann::ordered_json& json) {
	// Game object to return
	GameObject* gameObject = new GameObject();

	// Deserialize game object data into game object
	Transform& transform = gameObject->transform;
	gameObject->sceneIndex = json.at(Key::SCENE_INDEX).get<int>();
	gameObject->id = json.at(Key::ID).get<int>();
	gameObject->name = json.at(Key::NAME).get<std::string>();
	gameObject->deleteOnDestroy = json.at(Key::DELETE_ON_DESTROY).get<bool>();
	
	// Access position, rotation and scale JSON by reference
	const nlohmann::ordered_json& transformJSON = json.at(Key::TRANSFORM);
	const nlohmann::ordered_json& positionJSON= transformJSON.at(Key::POSITION);
	const nlohmann::ordered_json& rotationJSON = transformJSON.at(Key::ROTATION);
	const nlohmann::ordered_json& scaleJSON = transformJSON.at(Key::SCALE);
	
	// Deserialize position, rotation and scale data into transform
	transform.position.x = positionJSON.at(0);
	transform.position.y = positionJSON.at(1);
	transform.position.z = positionJSON.at(2);

	transform.rotation.x = rotationJSON.at(0);
	transform.rotation.y = rotationJSON.at(1);
	transform.rotation.z = rotationJSON.at(2);

	transform.scale.x = scaleJSON.at(0);
	transform.scale.y = scaleJSON.at(1);
	transform.scale.z = scaleJSON.at(2);

	return gameObject; // Success
}
void IT::Serializer::s_deserializeTransformRelationship(const nlohmann::ordered_json& json, const std::vector<GameObject*> gameObjects) {
	// Get game object
	int gameObjectSceneIndex = json.at(Key::SCENE_INDEX).get<int>();
	GameObject* gameObject = gameObjects[gameObjectSceneIndex];

	// Get other game object
	int sceneIndex = json.at(Key::SCENE_INDEX).get<int>();
	GameObject* otherGameObject = gameObjects[sceneIndex];

	// Link transform to parent transform
	gameObject->transform.setParent(&otherGameObject->transform);
}
IT::Component* IT::Serializer::s_deserializeComponent(const nlohmann::ordered_json& json, const std::vector<GameObject*> gameObjects) {
	int gameObjectSceneIndex = json.at(Key::GAME_OBJECT).get<int>();
	GameObject* gameObject = gameObjects[gameObjectSceneIndex];
	ComponentType componentType = static_cast<ComponentType>(json.at(Key::COMPONENT_TYPE).get<int>());
	
	switch (componentType) {
		case ComponentType::EMPTY_COMPONENT:
			return s_deserializeEmptyComponentData(json, gameObject);
		default:
			return nullptr; // Fail
	}
}
IT::EmptyComponent* IT::Serializer::s_deserializeEmptyComponentData(const nlohmann::ordered_json& json, IT::GameObject* gameObject) {
	return new EmptyComponent(*gameObject);
}
