#pragma once

// Dependencies | std
#include <string>
#include <vector>

// Dependencies | GLFW
#include <GLFW/glfw3.h>

// Dependencies | GLFWInterface
#include "GLFWInput.h"

// Dependencies | InTimeEngine
#include <src/IWindow.h>
#include <src/IInput.h>

class GLFWWindow : public IT::IWindow {
	// Friends
	friend class InTimeEngine;

	// Static
	private:
		// Properties
		static bool initialized;

		// Functions
		static bool init();
		static void resetKeyboardInputs();

	public:
		// Properties
		static int defaultWidth;
		static int defaultHeight;
		static std::string defaultName;

		// Callbacks
		static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

	// Object
	private:
		// Properties
		GLFWwindow* window = nullptr;

	public:
		// Properties
		GLFWInput input;

		// Constructor / Destructor
		GLFWWindow();
		GLFWWindow(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share);
		~GLFWWindow();

		// Getters
		GLFWwindow* getWindow() const;

		// Functions
		void swapBuffers() override;
};
