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
 * File: Joystick.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Sructure that represent the state of every joystick button and axis.
 *   buttons: 
 *   - pressed
 *   - just pressed
 *   - just released
 *   each axis:
 *   - value [-1, 1] 
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <array>

// Dependencies | OpenGLEngine
#include "JoystickButton.h"
#include "JoystickAxis.h"
#include "JoystickCode.h"

namespace GLFW {
	struct Joystick {
		// Static

		// Properties
		static std::array<Joystick, 16> joysticks; // Initialized at the bottom of header files

		// Functions
		static void resetJoystickButtons() {
			for (int joystickIndex = 0; joystickIndex < joysticks.size(); joystickIndex++) {
				if (!joysticks[joystickIndex].connected)
					continue;

				joysticks[joystickIndex].buttonA.justPressed = false;
				joysticks[joystickIndex].buttonA.justReleased = false;
				joysticks[joystickIndex].buttonB.justPressed = false;
				joysticks[joystickIndex].buttonB.justReleased = false;
				joysticks[joystickIndex].buttonX.justPressed = false;
				joysticks[joystickIndex].buttonX.justReleased = false;
				joysticks[joystickIndex].buttonY.justPressed = false;
				joysticks[joystickIndex].buttonY.justReleased = false;

				joysticks[joystickIndex].buttonLeftBumper.justPressed = false;
				joysticks[joystickIndex].buttonLeftBumper.justReleased = false;
				joysticks[joystickIndex].buttonRightBumper.justPressed = false;
				joysticks[joystickIndex].buttonRightBumper.justReleased = false;

				joysticks[joystickIndex].buttonBack.justPressed = false;
				joysticks[joystickIndex].buttonBack.justReleased = false;
				joysticks[joystickIndex].buttonStart.justPressed = false;
				joysticks[joystickIndex].buttonStart.justReleased = false;

				joysticks[joystickIndex].buttonLeftThumb.justPressed = false;
				joysticks[joystickIndex].buttonLeftThumb.justReleased = false;
				joysticks[joystickIndex].buttonRightThumb.justPressed = false;
				joysticks[joystickIndex].buttonRightThumb.justReleased = false;

				joysticks[joystickIndex].buttonDpadDown.justPressed = false;
				joysticks[joystickIndex].buttonDpadDown.justReleased = false;
				joysticks[joystickIndex].buttonDpadUp.justPressed = false;
				joysticks[joystickIndex].buttonDpadUp.justReleased = false;
				joysticks[joystickIndex].buttonDpadLeft.justPressed = false;
				joysticks[joystickIndex].buttonDpadLeft.justReleased = false;
				joysticks[joystickIndex].buttonDpadRight.justPressed = false;
				joysticks[joystickIndex].buttonDpadRight.justReleased = false;
			}
		}
		static void updateJoysticks() {
			for (int controllerIndex = 0; controllerIndex < 12; controllerIndex++) {
				bool controllerConnected = glfwJoystickPresent(controllerIndex);
				joysticks[controllerIndex].connected = controllerConnected;
				if (controllerConnected) {
					// Get button values for current controller
					int buttonCount = 0;
					const unsigned char* buttonValues = glfwGetJoystickButtons((int)joysticks[controllerIndex].code, &buttonCount);
					if (buttonValues == nullptr)
						continue;
					for (int buttonIndex = 0; buttonIndex <= buttonCount; buttonIndex++) {
						switch ((JoystickButtonCode)buttonIndex) {
						case JoystickButtonCode::A:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonA;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonA.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::B:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonB;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonB.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::X:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonX;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonX.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::Y:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonY;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonY.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::LEFT_BUMPER:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonLeftBumper;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonLeftBumper.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::RIGHT_BUMPER:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonRightBumper;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonRightBumper.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::BACK:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonBack;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonBack.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::START:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonStart;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonStart.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::RIGHT_THUMB:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonRightThumb;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonRightThumb.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::LEFT_THUMB:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonLeftThumb;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonLeftThumb.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::DPAD_UP:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadUp;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonDpadUp.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::DPAD_RIGHT:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadRight;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonDpadRight.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::DPAD_DOWN:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadDown;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonDpadDown.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						case JoystickButtonCode::DPAD_LEFT:
						{
							JoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadLeft;
							bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
							if (pressed && !joystickButton.pressed)
								joystickButton.justPressed = true;
							else if (!pressed && joysticks[controllerIndex].buttonDpadLeft.pressed)
								joystickButton.justReleased = true;
							joystickButton.pressed = pressed;
						}
						break;
						default:
							break;
						}
					}

					// Get the thumb axis values for current controller
					int axisCount = 0;
					const float* axisValues = glfwGetJoystickAxes((int)joysticks[controllerIndex].code, &axisCount);
					for (int axisIndex = 0; axisIndex < axisCount; axisIndex++) {
						switch ((JoystickAxisCode)axisIndex) {
						case JoystickAxisCode::LEFT_X:
							joysticks[controllerIndex].axisLeftX.value = axisValues[axisIndex];
							break;
						case JoystickAxisCode::LEFT_Y:
							joysticks[controllerIndex].axisLeftY.value = axisValues[axisIndex];
							break;
						case JoystickAxisCode::RIGHT_X:
							joysticks[controllerIndex].axisRightX.value = axisValues[axisIndex];
							break;
						case JoystickAxisCode::RIGHT_Y:
							joysticks[controllerIndex].axisRightY.value = axisValues[axisIndex];
							break;
						case JoystickAxisCode::LEFT_TRIGGER:
							joysticks[controllerIndex].axisLeftTrigger.value = axisValues[axisIndex];
							break;
						case JoystickAxisCode::RIGHT_TRIGGER:
							joysticks[controllerIndex].axisRightTrigger.value = axisValues[axisIndex];
							break;
						}
					}
				}
			}
		}

		// Object

		// Properties
		bool connected = false;

		JoystickCode code = JoystickCode::UNKOWN;

		JoystickButton buttonA = JoystickButton(JoystickButtonCode::A, "A");
		JoystickButton buttonB = JoystickButton(JoystickButtonCode::B, "B");
		JoystickButton buttonX = JoystickButton(JoystickButtonCode::X, "X");
		JoystickButton buttonY = JoystickButton(JoystickButtonCode::Y, "Y");

		JoystickButton buttonLeftBumper = JoystickButton(JoystickButtonCode::LEFT_BUMPER, "left bumper");
		JoystickButton buttonRightBumper = JoystickButton(JoystickButtonCode::RIGHT_BUMPER, "right bumper");

		JoystickButton buttonBack = JoystickButton(JoystickButtonCode::BACK, "back");
		JoystickButton buttonStart = JoystickButton(JoystickButtonCode::START, "start");

		JoystickButton buttonLeftThumb = JoystickButton(JoystickButtonCode::LEFT_THUMB, "left thumb");
		JoystickButton buttonRightThumb = JoystickButton(JoystickButtonCode::RIGHT_THUMB, "right thumb");

		JoystickButton buttonDpadUp = JoystickButton(JoystickButtonCode::DPAD_UP, "dpad up");
		JoystickButton buttonDpadRight = JoystickButton(JoystickButtonCode::DPAD_RIGHT, "dpad right");
		JoystickButton buttonDpadLeft = JoystickButton(JoystickButtonCode::DPAD_LEFT, "dpad left");
		JoystickButton buttonDpadDown = JoystickButton(JoystickButtonCode::DPAD_DOWN, "dpad down");

		GLFWJoystickAxis axisLeftX = GLFWJoystickAxis(JoystickAxisCode::LEFT_X, "left x");
		GLFWJoystickAxis axisLeftY = GLFWJoystickAxis(JoystickAxisCode::LEFT_Y, "left y");
		GLFWJoystickAxis axisRightX = GLFWJoystickAxis(JoystickAxisCode::RIGHT_X, "right x");
		GLFWJoystickAxis axisRightY = GLFWJoystickAxis(JoystickAxisCode::RIGHT_Y, "right y");
		GLFWJoystickAxis axisLeftTrigger = GLFWJoystickAxis(JoystickAxisCode::LEFT_TRIGGER, "left trigger");
		GLFWJoystickAxis axisRightTrigger = GLFWJoystickAxis(JoystickAxisCode::RIGHT_TRIGGER, "right trigger");

		// Contructor / Destructor
		Joystick() {

		}
		Joystick(JoystickCode code) : code(code) {

		}
		~Joystick() {

		}
	};
}
