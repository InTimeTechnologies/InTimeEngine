#pragma once

// Dependencies | std
#include <vector>
#include <forward_list>

// Dependencies | OpenGLEngine
#include "GLFWKeyCode.h"
#include "GLFWKey.h"
#include "GLFWMouseButtonCode.h"
#include "GLFWMouseButton.h"
#include "GLFWJoystickButtonCode.h"
#include "GLFWJoystickButton.h"
#include "GLFWJoystickAxisCode.h"
#include "GLFWJoystickAxis.h"
#include "GLFWJoystick.h"

class GLFWInput {
	// Friends
	friend class GLFWWindow;

	// Object
	private:
		// Properties
		std::forward_list<GLFWKey*> keysToReset = std::forward_list<GLFWKey*>();
		std::forward_list<GLFWMouseButton*> mouseButtonsToReset = std::forward_list<GLFWMouseButton*>();

	public:
		// Properties
		std::vector<GLFWKey> keys = std::vector<GLFWKey>(121);
		std::vector<GLFWMouseButton> mouseButtons = std::vector<GLFWMouseButton>(8);

	public:
		// Constructor / Destructor
		GLFWInput();
		~GLFWInput();

		// Functions
		void resetKeys();
		GLFWKey getKey(GLFWKeyCode keyCode);
		int getKeyIndex(GLFWKeyCode keyCode);

		void resetMouseButtons();
		GLFWMouseButton getMouseButton(GLFWMouseButtonCode mouseButtonCode);
		int getMouseButtonIndex(GLFWMouseButtonCode mouseButtonCode);
};
