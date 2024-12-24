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
 * File: IEngineEvents.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 * Updated on: 13DEC2024
 *
 * Description:
 *  This file containes all engine Javalike interface classes.
 *****************************************************************************/

#include "IEngineEvents.h"

// class IComponentInit

// Static | private

// Properties
std::list<IT::ILogicInitialization*> IT::ILogicInitialization::iComponentInitList = std::list<IT::ILogicInitialization*>();

// Object | public

// Constructor / Destructor
IT::ILogicInitialization::ILogicInitialization() {
	eventListenerNode = std::prev(iComponentInitList.end());
}
IT::ILogicInitialization::~ILogicInitialization() {
	iComponentInitList.erase(eventListenerNode);
}

// Events
void IT::ILogicInitialization::onInit() {
	// To be implemented in child classes
}

// ICoreUpdate

// Static | private

// Properties
std::list<IT::ICoreUpdate*> IT::ICoreUpdate::iCoreUpdateList = std::list<IT::ICoreUpdate*>();

// Object | public

// Constructor / Destructor
IT::ICoreUpdate::ICoreUpdate() {
	iCoreUpdateList.push_back(this);
	iCoreUpdateNode = std::prev(iCoreUpdateList.end());
}
IT::ICoreUpdate::~ICoreUpdate() {
	iCoreUpdateList.erase(iCoreUpdateNode);
}

// Events
void IT::ICoreUpdate::onPreCoreUpdate() {
	// To be implemented in child classes
}
void IT::ICoreUpdate::onPostCoreUpdate() {
	// To be implemented in child classes
}

// IPhysicsUpdate

// Static | private

// Properties
std::list<IT::IPhysicsUpdate*> IT::IPhysicsUpdate::iPhysicsUpdateList = std::list<IT::IPhysicsUpdate*>();

// Object | public

// Constructor / Destructor
IT::IPhysicsUpdate::IPhysicsUpdate() {
	// Add this to the list
	iPhysicsUpdateList.push_back(this);
	iPhysicsUpdateNode = std::prev(iPhysicsUpdateList.end());
}
IT::IPhysicsUpdate::~IPhysicsUpdate() {
	// Remove this from the list
	iPhysicsUpdateList.erase(iPhysicsUpdateNode);
}

// Events
void IT::IPhysicsUpdate::onPrePhysicsUpdate() {
	// To be implemented in child classes
}
void IT::IPhysicsUpdate::onPostPhysicsUpdate() {
	// To be implemented in child classes
}

// class IRender

// Static | private

// Properties
std::list<IT::IRender*> IT::IRender::iRenderList = std::list<IT::IRender*>();

// Object | public

// Constructor / Destructor
IT::IRender::IRender() {
	iRenderList.push_back(this);
	iRenderNode = std::prev(iRenderList.end());
}
IT::IRender::~IRender() {
	iRenderList.erase(iRenderNode);
}

// Events
void IT::IRender::onPreRender() {
	// To be implemented in child classes
}
void IT::IRender::render() {
	// To be implemented in child classes
}
void IT::IRender::onPostRender() {
	// To be implemented in child classes
}

// class IRenderUI

// Static | private

// Properties
std::list<IT::IRenderUI*> IT::IRenderUI::iRenderUIList = std::list<IT::IRenderUI*>();

// Object | public

// Constructor / Destructor
IT::IRenderUI::IRenderUI() {
	iRenderUIList.push_back(this);
	iRenderUINode = std::prev(iRenderUIList.end());
}
IT::IRenderUI::~IRenderUI() {
	iRenderUIList.erase(iRenderUINode);
}

// Events
void IT::IRenderUI::renderUI() {
	// To be implemented in child classes
}
