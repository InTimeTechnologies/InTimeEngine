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
 * File: IPhysicsEngine2D.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that the physics engine must override so
 *  In Time Engine can use it as its physics engine.
 *****************************************************************************/

#pragma once

// Dependencies | std
#include <list>

namespace IT {
	class IPhysicsEngine2D {
		// Friends
		friend class InTimeEngine;

		// Object
		public:
			// Constructor / Destructor
			IPhysicsEngine2D();
			virtual ~IPhysicsEngine2D();

		private:
			// Functions
			virtual void update(float timeStep) {};
	};
}
