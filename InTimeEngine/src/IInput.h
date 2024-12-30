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
 * File: IInputSystem.h
 * Author: Christopher Barrios Agosto
 * Created on: 29DEC2024
 *
 * Description:
 *  IInputSystem:
 *   It is the system in charge of updating IInput and IJoysticInput through
 *   the processInput and resetInput functions.
 *  IInput:
 *   Mouse and keyboard input system interface that must be overriden so
 *   In Time Engine can use it as its internal input system.
 *   It mainly provides the means to reset the moust & keyboard input.
 *  IJoysticInput:
 *   Joystic input system interface that must be overriden so
 *   In Time Engine can use it as its internal input system.
 *   It mainly provides the means to rese the joystic input.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <list>

namespace IT {
	class IInputSystem {
		// Static
		private:
			// Properties
			static IInputSystem* singleton;

		public:
			// Getters
			static IInputSystem* getSingleton();

		// Object
		public:
			// Constructor / Destructor
			IInputSystem();
			virtual ~IInputSystem();

			// Functions
			virtual void init();
			virtual void processInput();
			virtual void resetInput();
	};

	class IInput {
		// Static
		private:
			// Properties
			static std::list<IInput*> iInputList;

		public:
			// Getters
			static std::list<IInput*> getIInputList();

		// Object
		public:
			// Properties
			std::list<IInput*>::iterator node;

			// Constructor / Destructor
			IInput();
			virtual ~IInput();

			// Functions
			virtual void reset();
	};

	class IJoystickInput {
		// Static
		private:
			// Properties
			static std::list<IJoystickInput*> iJoystickInputList;

		public:
			// Getters
			static std::list<IJoystickInput*> getIInputList();

		// Object
		public:
			// Properties
			std::list<IJoystickInput*>::iterator node;

			// Constructor / Destructor
			IJoystickInput();
			virtual ~IJoystickInput();

			// Functions
			virtual void processInput();
			virtual void reset();
	};
}
