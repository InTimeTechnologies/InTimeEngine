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
 * File: IPhysicsEngine2D.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that the physics engine must override so
 *  In Time Engine can use it as its physics engine.
 *****************************************************************************/

#include "IPhysicsEngine2D.h"

// Dependencies | InTimeEngine
#include "InTimeEngine.h"

// class IPhysicsEngine2D

// Object | public

// Constructor / Destructor
IT::IPhysicsEngine2D::IPhysicsEngine2D() {
	InTimeEngine* inTimeEngine = InTimeEngine::s_getSingleton();
	if (inTimeEngine == nullptr)
		return;

	// If no 2D physics engine has been registered to In Time Engine
	if (inTimeEngine->iPhysicsEngine2D == nullptr)
		inTimeEngine->iPhysicsEngine2D = this; // Register this as In Time Engine's 2D physics engine
}
IT::IPhysicsEngine2D::~IPhysicsEngine2D() {
	InTimeEngine* inTimeEngine = InTimeEngine::s_getSingleton();
	if (inTimeEngine == nullptr)
		return;

	// If this 2D physics engine has been registered to In Time Engine
	if (inTimeEngine->iPhysicsEngine2D == this)
		inTimeEngine->iPhysicsEngine2D = nullptr; // Unegister this as In Time Engine's 2D physics engine
}
