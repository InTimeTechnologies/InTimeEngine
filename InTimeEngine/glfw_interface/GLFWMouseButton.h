#pragma once

// Dependencies | std
#include <string>

// Dependencies | OpenGLEngine
#include "GLFWMouseButtonCode.h"

struct GLFWMouseButton {
	// Properties
	GLFWMouseButtonCode buttonCode = GLFWMouseButtonCode::UNKNOWN;
	bool pressed = false;
	bool justPressed = false;
	bool justReleased = false;
	std::string description = "none";

	// Constructor / Destructor
	GLFWMouseButton() {

	}
	GLFWMouseButton(GLFWMouseButtonCode buttonCode, const std::string& description) : buttonCode(buttonCode), description(description) {

	}
	~GLFWMouseButton() {

	}
};
