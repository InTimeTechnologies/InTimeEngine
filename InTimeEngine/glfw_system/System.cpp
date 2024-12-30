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
 * File: System.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Serves as the interface to the GLFW code. Use this to init and deinit GLFW.
 *  This is the class that overrides IInputSystem.
 *  In Time Engine will call processInput and resetInput to manage mouse,
 *  keayboard and joystick input. Note that this is through glfwPollEvents.
 *  This causes to process all user interfaces events too.
 *****************************************************************************/

#include "System.h"

// Dependencies | GLFW
#include <GLFW/glfw3.h>

// class GLFWSystem

// Static | private

// Properties
GLFW::System* GLFW::System::singleton = nullptr;

// Static | public

// Getters
GLFW::System* GLFW::System::getSingleton() {
	return singleton;
}

// Object | public

// Constructor / Destructor
GLFW::System::System() {
	glfwInit();
}
GLFW::System::~System() {
	glfwTerminate();
}

// Functions
void GLFW::System::init() {
	glfwInit();
}
void GLFW::System::processInput() {
	// Process window events, joystick, mouse and keyboard input
	glfwPollEvents();

	// Note: glfwPollEvents process joystick input, but the GLFW interface
	//       copies each joystick input for user ease of access and
	//       implements justPressed, pressed and justReleased features.
	//       This is done through iJoysticInput->processInput

	// Further process joystic input
	std::list<IT::IJoystickInput*> iJoysticInputList = IT::IJoystickInput::getIInputList();
	for (IT::IJoystickInput* iJoystickInput : iJoysticInputList)
		iJoystickInput->processInput();
}
void GLFW::System::resetInput() {
	// Reset mouse and keyboard input
	std::list<IT::IInput*> iInputList = IT::IInput::getIInputList();
	for (IT::IInput* iInput : iInputList)
		iInput->reset();

	// Reset joystic input
	std::list<IT::IJoystickInput*> iJoystickInputList = IT::IJoystickInput::getIInputList();
	for (IT::IJoystickInput* iJoysticInput : iJoystickInputList)
		iJoysticInput->reset();
}
