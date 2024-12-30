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
 * File: Window.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Wrapper class around GLFW window pointer.
 *****************************************************************************/

#include "Window.h"

// class Window

// Static | public

// Properties
int GLFW::Window::defaultWidth = 800;
int GLFW::Window::defaultHeight = 600;
std::string GLFW::Window::defaultName = "GLFW Window";

// Callbacks
void GLFW::Window::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	Window* glfwWindow = (Window*)glfwGetWindowUserPointer(window);
	if (glfwWindow == nullptr)
		return;

	int keyIndex = glfwWindow->input.getKeyIndex((KeyCode)key);

	if (action == GLFW_PRESS) {
		glfwWindow->input.keys[keyIndex].justPressed = true;
		glfwWindow->input.keys[keyIndex].pressed = true;
	}
	if (action == GLFW_REPEAT) {
		glfwWindow->input.keys[keyIndex].repeat = true;
	}
	if (action == GLFW_RELEASE) {
		glfwWindow->input.keys[keyIndex].justReleased = true;
		glfwWindow->input.keys[keyIndex].pressed = false;
	}

	glfwWindow->input.keysToReset.push_front(&glfwWindow->input.keys[keyIndex]);
}
void GLFW::Window::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	Window* glfwWindow = (Window*)glfwGetWindowUserPointer(window);
	if (glfwWindow == nullptr)
		return;

	int mouseButtonIndex = glfwWindow->input.getMouseButtonIndex((MouseButtonCode)button);
	if (action == GLFW_PRESS) {
		glfwWindow->input.mouseButtons[mouseButtonIndex].justPressed = true;
		glfwWindow->input.mouseButtons[mouseButtonIndex].pressed = true;
	}
	if (action == GLFW_RELEASE) {
		glfwWindow->input.mouseButtons[mouseButtonIndex].justReleased = true;
		glfwWindow->input.mouseButtons[mouseButtonIndex].pressed = false;
	}

	glfwWindow->input.mouseButtonsToReset.push_front(&glfwWindow->input.mouseButtons[mouseButtonIndex]);
}

// Object | public

// Constructor / Destructor
GLFW::Window::Window() : GLFW::Window(defaultWidth, defaultHeight, defaultName, nullptr, nullptr) {

}
GLFW::Window::Window(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share) {
	// Set window hints prior to creation (remove this in production. This needs to be set outside of this class)
	//glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// Create and set window user pointer
	window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
	glfwSetWindowUserPointer(window, this);

	// Set callbacks
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
}
GLFW::Window::~Window() {
	glfwDestroyWindow(window);
}

// Getters
GLFWwindow* GLFW::Window::getWindow() const {
	return window;
}
