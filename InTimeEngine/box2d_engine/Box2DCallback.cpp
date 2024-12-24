#include "Box2DCallback.h"

// class IContactUpdate

// Static | private

// Properties
std::list<IContactUpdate*> IContactUpdate::iContactList = std::list<IContactUpdate*>();

// Object | public

// Constructor / Destructor
IContactUpdate::IContactUpdate() {
	// Add this to the list
	iContactList.push_back(this);
	iContactListNode = std::prev(iContactList.end());
}
IContactUpdate::~IContactUpdate() {
	// Remove this from the list
	iContactList.erase(iContactListNode);
}

// Functions
void IContactUpdate::onBeginContact(b2Contact* contact) {
	// To be implemented in child classes
}
void IContactUpdate::onEndContact(b2Contact* contact) {
	// To be implemented in child classes
}

// class ISolveUpdate

// Static | private

// Properties
std::list<ISolveUpdate*> ISolveUpdate::iSolveUpdateList = std::list<ISolveUpdate*>();

// Object | public

// Constructor / Destructor
ISolveUpdate::ISolveUpdate() {
	// Add this to the list
	iSolveUpdateList.push_back(this);
	iSolveUpdateNode = std::prev(iSolveUpdateList.end());
}
ISolveUpdate::~ISolveUpdate() {
	// Remove this from the list
	iSolveUpdateList.erase(iSolveUpdateNode);
}

// Functions
void ISolveUpdate::onPresolve(b2Contact* contact, const b2Manifold* oldManifold) {
	// To be implemented in child classes
}
void ISolveUpdate::onPostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
	// To be implemented in child classes
}
