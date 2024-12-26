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
 * File: IInput.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that the input system must override so
 *  In Time Engine can use is as its input system.
 *****************************************************************************/

#include "IInput.h"

// class IInput

// Static | public

// Properties
std::function<void()> IT::IInput::resetJoystickInputFunction = IT::IInput::emptyVoidFunction;
std::function<void()> IT::IInput::processInput = IT::IInput::emptyVoidFunction;

// Functions
void IT::IInput::emptyVoidFunction() {
	// Left empty intentionally. This is the default function of initFunction
}
