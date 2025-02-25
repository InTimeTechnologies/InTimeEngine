#include "ComponentRegistry.h"

// Dependencies | std
#include <cassert>

// Dependencies | InTimeEngine
#include "InTimeEngine.h"

// class ComponentRegistry

// Static | public

// Functions
nlohmann::ordered_json IT::EntityRegistry::getJSONTemplate(const Component& component) {
	nlohmann::ordered_json jsonTemplate = nlohmann::ordered_json::object();
	jsonTemplate["gameObject"] = -1;
	jsonTemplate["index"] = -1;
	jsonTemplate["typeName"] = component.getTypeInfo().name();
	
	return jsonTemplate;
}

// Object | private
bool IT::EntityRegistry::registerComponent(const EngineEntry& engineEntry) {
	// Check if new engine entry was previously registered
	for (const EngineEntry& currentEngineEntry : engineEntries)
		if (currentEngineEntry.typeInfo == engineEntry.typeInfo)
			return false; // Fail

	// Register entry
	size_t entryIndex = engineEntries.size();
	engineEntries.push_back(engineEntry);
	engineEntries[entryIndex].componentTypeID = entryIndex;
	return true; // Success
}

// Object | public

// Constructor
IT::EntityRegistry::EntityRegistry() {
	engineEntries = std::vector<EntityRegistry::EngineEntry>(1);
	IT::EntityRegistry::EngineEntry engineEntry = IT::EntityRegistry::EngineEntry();
	int index = 0;

	// EmptyComponent
	engineEntry.componentTypeID = index;
	engineEntry.typeInfo = &typeid(nullptr);
	engineEntry.factory = [](GameObject& gameObject) -> Component* { return new EmptyComponent(gameObject); };
	engineEntry.toJSON = [](Component*) -> nlohmann::ordered_json {
		return nlohmann::ordered_json::object();
		};
	engineEntry.fromJSON = [](GameObject& gameObject, nlohmann::ordered_json) -> Component* { return new EmptyComponent(gameObject); };
	engineEntries[index++] = engineEntry;
}

// Getters
std::vector<IT::EntityRegistry::EngineEntry> IT::EntityRegistry::getEngineEntries() const {
	return engineEntries;
}
std::vector<IT::EntityRegistry::Entry> IT::EntityRegistry::getEntries() const {
	return entries;
}

// Functions
bool IT::EntityRegistry::registerComponent(const Entry& entry) {
	return true;
}
nlohmann::ordered_json IT::EntityRegistry::serialize(Component* component) {
	const type_info* typeInfo = &component->getTypeInfo();
	for (const EngineEntry& engineEntry : engineEntries)
		if (engineEntry.typeInfo == typeInfo)
			return engineEntry.toJSON(component);
	return nlohmann::ordered_json::object();
}
IT::Component* IT::EntityRegistry::deserialize(GameObject& gameObject, const nlohmann::ordered_json& json) {
	return nullptr;
}
