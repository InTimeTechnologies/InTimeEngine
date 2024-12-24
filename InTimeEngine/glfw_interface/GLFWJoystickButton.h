#pragma once

// Dependencies | std
#include <string>

// Dependencies | OpenGLEngine
#include "GLFWJoystickButtonCode.h"

struct GLFWJoystickButton {
	GLFWJoystickButtonCode buttonCode = GLFWJoystickButtonCode::UNKNOWN;
	bool justPressed = false;
	bool justReleased = false;
	bool pressed = false;
	std::string description = "none";

	GLFWJoystickButton(GLFWJoystickButtonCode buttonCode, const std::string& description) : buttonCode(buttonCode), description(description) {

	}
	~GLFWJoystickButton() {

	}
};
