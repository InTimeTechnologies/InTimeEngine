#pragma once

// Dependencies | std
#include <vector>

// Dependencies | OpenGLEngine
#include "GLFWJoystickButton.h"
#include "GLFWJoystickAxis.h"
#include "GLFWJoystickCode.h"

struct GLFWJoystick {
	// Static

	// Properties
	static std::vector<GLFWJoystick> joysticks; // Initialized at the bottom of header files

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
					switch ((GLFWJoystickButtonCode)buttonIndex) {
					case GLFWJoystickButtonCode::A:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonA;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonA.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::B:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonB;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonB.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::X:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonX;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonX.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::Y:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonY;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonY.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::LEFT_BUMPER:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonLeftBumper;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonLeftBumper.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::RIGHT_BUMPER:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonRightBumper;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonRightBumper.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::BACK:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonBack;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonBack.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::START:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonStart;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonStart.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::RIGHT_THUMB:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonRightThumb;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonRightThumb.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::LEFT_THUMB:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonLeftThumb;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonLeftThumb.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::DPAD_UP:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadUp;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonDpadUp.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::DPAD_RIGHT:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadRight;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonDpadRight.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::DPAD_DOWN:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadDown;
						bool pressed = buttonValues[buttonIndex] == GLFW_PRESS ? true : false;
						if (pressed && !joystickButton.pressed)
							joystickButton.justPressed = true;
						else if (!pressed && joysticks[controllerIndex].buttonDpadDown.pressed)
							joystickButton.justReleased = true;
						joystickButton.pressed = pressed;
					}
					break;
					case GLFWJoystickButtonCode::DPAD_LEFT:
					{
						GLFWJoystickButton& joystickButton = joysticks[controllerIndex].buttonDpadLeft;
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
					switch ((GLFWJoystickAxisCode)axisIndex) {
					case GLFWJoystickAxisCode::LEFT_X:
						joysticks[controllerIndex].axisLeftX.value = axisValues[axisIndex];
						break;
					case GLFWJoystickAxisCode::LEFT_Y:
						joysticks[controllerIndex].axisLeftY.value = axisValues[axisIndex];
						break;
					case GLFWJoystickAxisCode::RIGHT_X:
						joysticks[controllerIndex].axisRightX.value = axisValues[axisIndex];
						break;
					case GLFWJoystickAxisCode::RIGHT_Y:
						joysticks[controllerIndex].axisRightY.value = axisValues[axisIndex];
						break;
					case GLFWJoystickAxisCode::LEFT_TRIGGER:
						joysticks[controllerIndex].axisLeftTrigger.value = axisValues[axisIndex];
						break;
					case GLFWJoystickAxisCode::RIGHT_TRIGGER:
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

	GLFWJoystickCode code = GLFWJoystickCode::UNKOWN;

	GLFWJoystickButton buttonA = GLFWJoystickButton(GLFWJoystickButtonCode::A, "A");
	GLFWJoystickButton buttonB = GLFWJoystickButton(GLFWJoystickButtonCode::B, "B");
	GLFWJoystickButton buttonX = GLFWJoystickButton(GLFWJoystickButtonCode::X, "X");
	GLFWJoystickButton buttonY = GLFWJoystickButton(GLFWJoystickButtonCode::Y, "Y");

	GLFWJoystickButton buttonLeftBumper = GLFWJoystickButton(GLFWJoystickButtonCode::LEFT_BUMPER, "left bumper");
	GLFWJoystickButton buttonRightBumper = GLFWJoystickButton(GLFWJoystickButtonCode::RIGHT_BUMPER, "right bumper");

	GLFWJoystickButton buttonBack = GLFWJoystickButton(GLFWJoystickButtonCode::BACK, "back");
	GLFWJoystickButton buttonStart = GLFWJoystickButton(GLFWJoystickButtonCode::START, "start");

	GLFWJoystickButton buttonLeftThumb = GLFWJoystickButton(GLFWJoystickButtonCode::LEFT_THUMB, "left thumb");
	GLFWJoystickButton buttonRightThumb = GLFWJoystickButton(GLFWJoystickButtonCode::RIGHT_THUMB, "right thumb");

	GLFWJoystickButton buttonDpadUp = GLFWJoystickButton(GLFWJoystickButtonCode::DPAD_UP, "dpad up");
	GLFWJoystickButton buttonDpadRight = GLFWJoystickButton(GLFWJoystickButtonCode::DPAD_RIGHT, "dpad right");
	GLFWJoystickButton buttonDpadLeft = GLFWJoystickButton(GLFWJoystickButtonCode::DPAD_LEFT, "dpad left");
	GLFWJoystickButton buttonDpadDown = GLFWJoystickButton(GLFWJoystickButtonCode::DPAD_DOWN, "dpad down");

	GLFWJoystickAxis axisLeftX = GLFWJoystickAxis(GLFWJoystickAxisCode::LEFT_X, "left x");
	GLFWJoystickAxis axisLeftY = GLFWJoystickAxis(GLFWJoystickAxisCode::LEFT_Y, "left y");
	GLFWJoystickAxis axisRightX = GLFWJoystickAxis(GLFWJoystickAxisCode::RIGHT_X, "right x");
	GLFWJoystickAxis axisRightY = GLFWJoystickAxis(GLFWJoystickAxisCode::RIGHT_Y, "right y");
	GLFWJoystickAxis axisLeftTrigger = GLFWJoystickAxis(GLFWJoystickAxisCode::LEFT_TRIGGER, "left trigger");
	GLFWJoystickAxis axisRightTrigger = GLFWJoystickAxis(GLFWJoystickAxisCode::RIGHT_TRIGGER, "right trigger");

	// Contructor / Destructor
	GLFWJoystick() {

	}
	GLFWJoystick(GLFWJoystickCode code) : code(code) {

	}
	~GLFWJoystick() {

	}
};
