#include "SceneManager.h"

// Dependencies | InTimeEngine
#include "Serializer.h"

// class JSONScene

// Object | public

// Functions
bool IT::SceneManager::loadSceneFromJSON(const std::filesystem::path& pathToJSONScene) {
    // Open the file
    std::ifstream ifstream(pathToJSONScene);
    if (!ifstream.is_open())
        return false;

    // Load file contents into an ordered_json object
    nlohmann::ordered_json sceneJSON;
    
    // Try loading the JSON data from the file (the file must follow the scene standard)
    try {
        ifstream >> sceneJSON;
    }
    catch (const nlohmann::ordered_json::parse_error& e) {
        return false;
    }
    
    // Create references to gameObjects, transformRelationships, components
    const nlohmann::ordered_json& gameObjectsJSON = sceneJSON.at("gameObjects");
    const nlohmann::ordered_json& transformRelationshipsJSON = sceneJSON.at("transformRelationships");
    const nlohmann::ordered_json& componentsJSON = sceneJSON.at("components");

    // Deserialize game objects and add them to gameObjects
    for (const nlohmann::ordered_json& gameObjectJSON : gameObjectsJSON) {
        GameObject* gameObject = Serializer::s_deserializeGameObject(gameObjectJSON);
        gameObjects.push_back(gameObject);
    }

    // Deserialize transform relationships
    for (const nlohmann::ordered_json& transformRelationshipJSON : transformRelationshipsJSON) {
        Serializer::s_deserializeTransformRelationship(transformRelationshipJSON, gameObjects);
    }

    // Deserialize components and add them to components
    for (const nlohmann::ordered_json& componentJSON : componentsJSON) {
        Component* component = Serializer::s_deserializeComponent(componentJSON, gameObjects);
        components.push_back(component);
    }

    // Print the parsed JSON
    std::cout << sceneJSON.dump(4) << std::endl;

	return true; // Success
}
bool IT::SceneManager::saveSceneAsJSON(const std::filesystem::path& pathToJSONScene) {
    // Set scene index to game objects and components
    size_t sceneIndex = 0ULL;
    for (size_t i = 0ULL; i < gameObjects.size(); i++) {
        gameObjects[i]->sceneIndex = i;
        const std::vector<Component*> components = gameObjects[i]->getComponents();
        for (size_t i = 0ULL; i < components.size(); i++) {
            components[i]->sceneIndex = this->components.size();
            this->components.push_back(components[i]);
        }
    }

    // Open file
    std::ofstream ofstream(pathToJSONScene);
    if (!ofstream.is_open())
        return false; // Fail

    // Create major category JSON objects
    nlohmann::ordered_json sceneJSON = nlohmann::ordered_json::object();
    nlohmann::ordered_json gameObjectsJSON = nlohmann::ordered_json::array();
    nlohmann::ordered_json transformRelationshipsJSON = nlohmann::ordered_json::array();
    nlohmann::ordered_json componentsJSON = nlohmann::ordered_json::array();

    for (GameObject* gameObject : gameObjects) {
        gameObjectsJSON.push_back(Serializer::s_serializeGameObject(gameObject));
        if (gameObject->transform.getParent() != nullptr)
            transformRelationshipsJSON.push_back(Serializer::s_serializeTransformRelationship(gameObject, gameObjects));
    }

    // To-Do: Implement it
    for (Component* component: components)
        componentsJSON.push_back(Serializer::s_serializeComponent(component));

    // Store JSON data into JSON file and close it
    sceneJSON["gameObjects"] = gameObjectsJSON;
    sceneJSON["transformRelationships"] = transformRelationshipsJSON;
    sceneJSON["components"] = componentsJSON;
    std::cout << sceneJSON.dump(4);
    ofstream << sceneJSON.dump(4);
    ofstream.close();

    // Reset scene index to game objects and components to -1
    for (GameObject* gameObject : gameObjects) {
        gameObject->sceneIndex = -1;
        const std::vector<Component*> components = gameObject->getComponents();
        for (Component* component : components)
            component->sceneIndex = -1;
    }

    return true; // Success
}
void IT::SceneManager::destoyScene() {
    for (GameObject* gameObject : gameObjects)
        gameObject->destroy();
    gameObjects.clear();
}
