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
 * File: IWindow.cpp
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that window systems must override so In Time
 *  Engine object can use it as its windowing system.
 *****************************************************************************/

#include "IWindow.h"

// class IWindow

// Static | public

// Properties
std::list<IT::IWindow*> IT::IWindow::windowList = std::list<IWindow*>();

// Static | public

// Properties
std::function<void()> IT::IWindow::pollEventsFunction = IT::IWindow::emptyVoidFunction;
std::function<void()> IT::IWindow::resetKeyboardInputFunction = IT::IWindow::emptyVoidFunction;

// Function
void IT::IWindow::emptyVoidFunction() {
	// Left empty intentionally. This is the default function of initFunction
}

// Object | public

// Constructor / Destructor
IT::IWindow::IWindow() {
	windowList.push_back(this);
	node = std::prev(windowList.end());
}
IT::IWindow::~IWindow() {
	windowList.erase(node);
}

// Functions
void IT::IWindow::swapBuffers() {
	// To be implemented in child class
}
