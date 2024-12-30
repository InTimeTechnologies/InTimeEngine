/******************************************************************************
 * Copyright (c) 2024 Christopher Barrios Agosto. All Rights Reserved.
 *
 * Licensing Information:
 *  This software and associated documentation files (the "Software") may not
 *  be used, copied, modified, merged, published, distributed, sublicensed,
 *  or sold without the prior written permission of the copyright owner.
 *
 *  Unauthorized use of this file, via any medium, is strictly prohibited.
 *****************************************************************************/

/******************************************************************************
 * Project: In Time Engine
 * File: IInputSystem.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  IInputSystem:
 *   It is the system in charge of updating IInput and IJoysticInput through
 *   the processInput and resetInput functions.
 *  IInput:
 *   Mouse and keyboard input system interface that must be overriden so
 *   In Time Engine can use it as its internal input system.
 *   It mainly provides the means to reset the moust & keyboard input.
 *  IJoysticInput:
 *   Joystic input system interface that must be overriden so
 *   In Time Engine can use it as its internal input system.
 *   It mainly provides the means to rese the joystic input.
 *****************************************************************************/

#include "IInput.h"

// class IInputSystem

// Static | private

// Properties
IT::IInputSystem* IT::IInputSystem::singleton = nullptr;


// Static | public

// Getters
IT::IInputSystem* IT::IInputSystem::getSingleton() {
	return singleton;
}

// Object | public

// Constructor / Destructor
IT::IInputSystem::IInputSystem() {
	if (singleton == nullptr)
		singleton = this;
}
IT::IInputSystem::~IInputSystem() {
	if (singleton == this)
		singleton = nullptr;
}

// Functions
void IT::IInputSystem::init() {
	// To be implemented in child class
}
void IT::IInputSystem::processInput() {
	// To be implemented in child class
}
void IT::IInputSystem::resetInput() {
	// To be implemented in child class
}

// class IInput

// Static | private

// Properties
std::list<IT::IInput*> IT::IInput::iInputList = std::list<IT::IInput*>();

// Static | public

// Getters
std::list<IT::IInput*> IT::IInput::getIInputList() {
	return iInputList;
}

// Object | public

// Constructor / Destructor
IT::IInput::IInput() {
	iInputList.push_back(this);
	node = std::prev(iInputList.end());
}
IT::IInput::~IInput() {
	iInputList.erase(node);
}

// Functions
void IT::IInput::reset() {
	// To be implemented in child class
}

// class IJoystickInput

// Static | private

// Properties
std::list<IT::IJoystickInput*> IT::IJoystickInput::iJoystickInputList = std::list<IT::IJoystickInput*>();

// Static | public

// Getters
std::list<IT::IJoystickInput*> IT::IJoystickInput::getIInputList() {
	return iJoystickInputList;
}

// Object

// Constructor | Destructor
IT::IJoystickInput::IJoystickInput() {
	iJoystickInputList.push_back(this);
	node = std::prev(iJoystickInputList.end());
}
IT::IJoystickInput::~IJoystickInput() {
	iJoystickInputList.erase(node);
}

// Functions
void IT::IJoystickInput::processInput() {
	// To be implemented in child class
}
void IT::IJoystickInput::reset() {
	// To be implemented in child class
}
