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
 * File: Window.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Wrapper class around GLFW window pointer.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <string>
#include <list>

// Dependencies | GLFWInterface
#include "Input.h"

// Dependencies | InTimeEngine
#include "src/IRenderer.h"

namespace GLFW {
	class Window {
		// Static
		private:
			// Properties
			static std::list<Window*> windowList;

		public:
			// Properties
			static int defaultWidth;
			static int defaultHeight;
			static std::string defaultName;

			// Getters
			static std::list<Window*> getWindowList();

			// Callbacks
			static void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);
			static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);
			static void onWindowResizeCallback(GLFWwindow* glfwWindow, int width, int height);

		// Object
		private:
			// Properties
			GLFWwindow* window = nullptr;
			std::list<GLFW::Window*>::iterator node;

		public:
			// Properties
			IT::IRenderer* renderer = nullptr;
			GLFW::Input input;

			// Constructor / Destructor
			Window();
			Window(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share);
			~Window();

			// Getters
			GLFWwindow* getWindow() const;
	};
}
