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
 * File: IWindow.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that window systems must override so In Time
 *  Engine object can use it as its windowing system.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <functional>
#include <list>

namespace IT {
	class IWindow {
		// Friends
		friend class InTimeEngine;

		// Static
		protected:
			// Properties
			static std::list<IWindow*> windowList;

		public:
			// Properties
			static std::function<void()> pollEventsFunction;
			static std::function<void()> resetKeyboardInputFunction;

			// Functions
			static void emptyVoidFunction();

		// Object
		protected:
			// Properties
			std::list<IWindow*>::iterator node;

		public:
			// Constructor / Destructor
			IWindow();
			virtual ~IWindow();

			// Functions
			virtual void swapBuffers();
	};
}
