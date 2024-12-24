#pragma once

// Dependencies | std
#include <string>

// Dependencies | GLFW
#include <GLFW/glfw3.h>

// Dependencies | OpenGLEngine
#include "GLFWJoystickAxisCode.h"

struct GLFWJoystickAxis {
	GLFWJoystickAxisCode axisCode = GLFWJoystickAxisCode::UNKNOWN;
	float value = 0.0f;
	std::string description = "none";

	GLFWJoystickAxis() {

	}
	GLFWJoystickAxis(GLFWJoystickAxisCode axisCode, const std::string& description) : axisCode(axisCode), description(description) {

	}
	~GLFWJoystickAxis() {

	}
};
