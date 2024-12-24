#pragma once

// Dependencies | std
#include <string>

// Dependencies | OpenGLEngine
#include "GLFWKeyCode.h"

struct GLFWKey {
	// Properties
	GLFWKeyCode keyCode = GLFWKeyCode::UNKNOWN;
	bool justPressed = false;
	bool repeat = false;
	bool justReleased = false;
	bool pressed = false;
	std::string description = "none";

	// Contructor / Destructor
	GLFWKey() {

	}
	GLFWKey(GLFWKeyCode keyCode, const std::string& description) : keyCode(keyCode), description(description) {

	}
	~GLFWKey() {

	}
};
