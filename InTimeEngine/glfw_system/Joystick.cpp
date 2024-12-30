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
 * File: Joystick.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  Sructure that represent the state of every joystick button and axis.
 *   buttons:
 *   - pressed
 *   - just pressed
 *   - just released
 *   each axis:
 *   - value [-1, 1]
 *****************************************************************************/

#include "Joystick.h"

// struct GLFWJoystick

// Static | public

// Properties
std::array<GLFW::Joystick, 16> GLFW::Joystick::joysticks{
	Joystick(JoystickCode::CONTROLLER_0),
	Joystick(JoystickCode::CONTROLLER_1),
	Joystick(JoystickCode::CONTROLLER_2),
	Joystick(JoystickCode::CONTROLLER_3),
	Joystick(JoystickCode::CONTROLLER_4),
	Joystick(JoystickCode::CONTROLLER_5),
	Joystick(JoystickCode::CONTROLLER_6),
	Joystick(JoystickCode::CONTROLLER_7),
	Joystick(JoystickCode::CONTROLLER_8),
	Joystick(JoystickCode::CONTROLLER_9),
	Joystick(JoystickCode::CONTROLLER_10),
	Joystick(JoystickCode::CONTROLLER_11),
	Joystick(JoystickCode::CONTROLLER_12),
	Joystick(JoystickCode::CONTROLLER_13),
	Joystick(JoystickCode::CONTROLLER_14),
	Joystick(JoystickCode::CONTROLLER_15)
};
