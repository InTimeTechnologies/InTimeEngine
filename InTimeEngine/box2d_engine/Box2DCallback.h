#pragma once

// Dependencies | std
#include <list>

// Dependencies | Box2D
#include <box2d/box2d.h>

class IContactUpdate {
	// Friends
	friend class ContactListener;

	// Static
	private:
		// Properties
		static std::list<IContactUpdate*> iContactList;

	// Object
	private:
		// Properties
		std::list<IContactUpdate*>::iterator iContactListNode;

	public:
		// Constructor / Destructor
		IContactUpdate();
		~IContactUpdate();

		// Events
		virtual void onBeginContact(b2Contact* contact);
		virtual void onEndContact(b2Contact* contact);
};

class ISolveUpdate {
	// Friends
	friend class ContactListener;

	// Static
	private:
		static std::list<ISolveUpdate*> iSolveUpdateList;

	// Object
	private:
		// Properties
		std::list<ISolveUpdate*>::iterator iSolveUpdateNode;

	public:
		// Contructor / Destructor
		ISolveUpdate();
		~ISolveUpdate();

		// Events
		virtual void onPresolve(b2Contact* contact, const b2Manifold* oldManifold);
		virtual void onPostSolve(b2Contact* contact, const b2ContactImpulse* impulse);
};
