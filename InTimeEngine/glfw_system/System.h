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
 * File: System.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Serves as the interface to the GLFW code. Use this to init and deinit GLFW.
 *  This is the class that overrides IInputSystem.
 *  In Time Engine will call processInput and resetInput to manage mouse,
 *  keayboard and joystick input. Note that this is through glfwPollEvents.
 *  This causes to process all user interfaces events too.
 *****************************************************************************/

#pragma once

// Dependencies | InTimeEngine
#include <src/IInput.h>

// Dependencies | glfw_system
#include "Window.h"

namespace GLFW {
	class System : public IT::IInputSystem {
		// Static
		private:
			// Properties
			static System* singleton;

		public:
			// Getters
			static System* getSingleton();

		// Object
		public:
			// Constructor / Destructor
			System();
			~System();

			// Functions
			void init() override;
			void processInput() override;
			void resetInput() override;
	};
}
