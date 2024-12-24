#include "ContactListener.h"

// class ContactListener

// Object | public

// Constructor
ContactListener::ContactListener() : b2ContactListener() {

}
ContactListener::~ContactListener() {

}

// Functions
void ContactListener::BeginContact(b2Contact* contact) {
	for (IContactUpdate* iContactUpdate : IContactUpdate::iContactList)
		iContactUpdate->onBeginContact(contact);
}
void ContactListener::EndContact(b2Contact* contact) {
	for (IContactUpdate* iContactUpdate : IContactUpdate::iContactList)
		iContactUpdate->onEndContact(contact);
}
void ContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold) {
	for (ISolveUpdate* iSolveUpdate : ISolveUpdate::iSolveUpdateList)
		iSolveUpdate->onPresolve(contact, oldManifold);
}
void ContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) {
	for (ISolveUpdate* iSolveUpdate : ISolveUpdate::iSolveUpdateList)
		iSolveUpdate->onPostSolve(contact, impulse);
}
