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
 * File: IInput.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that the input system must override so
 *  In Time Engine can use is as its input system.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <functional>

namespace IT {
	class IInput {
		// Static
		public:
			// Properties
			static std::function<void()> resetJoystickInputFunction;
			static std::function<void()> processInput;

			// Functions
			static void emptyVoidFunction();
	};
}