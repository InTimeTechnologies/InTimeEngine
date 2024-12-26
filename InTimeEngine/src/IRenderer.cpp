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
 * File: IRenderer.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that graphics engine must override so In Time
 *  Engine object can use it as its renderer.
 *****************************************************************************/

#include "IRenderer.h"

// class IRenderer

// Static | private

// Properties
IT::IRenderer* IT::IRenderer::singleton = nullptr;

// Static | public

// Getters
IT::IRenderer* IT::IRenderer::getSingleton() {
	return singleton;
}

// Object | public

// Constructor / Destructor
IT::IRenderer::IRenderer() {
	if (singleton == nullptr)
		singleton = this;
}
IT::IRenderer::~IRenderer() {
	if (singleton == this)
		singleton = nullptr;
}

// Functions
void IT::IRenderer::render() {
	// To be implemented in child class
}
