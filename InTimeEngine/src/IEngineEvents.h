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

#pragma once

// Dependencies | std
#include <list>

namespace IT {
	class ILogicInitialization {
		// Friends
		friend class InTimeEngine;
 
		// Static
		private:
			// Properties
			static std::list<ILogicInitialization*> iComponentInitList;

		// Object
		private:
			// Properties
			std::list<ILogicInitialization*>::iterator eventListenerNode;

		public:
			// Constructor / Destructor
			ILogicInitialization();
			virtual ~ILogicInitialization();

			// Events
			virtual void onInit();
	};

	class ICoreUpdate {
		// Friends
		friend class InTimeEngine;

		// Static
		private:
			// Properties
			static std::list<ICoreUpdate*> iCoreUpdateList;

		// Object
		private:
			// Properties
			std::list<ICoreUpdate*>::iterator iCoreUpdateNode;

		public:
			// Constructor / Destructor
			ICoreUpdate();
			virtual ~ICoreUpdate();

			// Events
			virtual void onPreCoreUpdate();
			virtual void onPostCoreUpdate();
	};

	class IPhysicsUpdate {
		// Friends
		friend class InTimeEngine;

		// Static
		private:
			// Properties
			static std::list<IPhysicsUpdate*> iPhysicsUpdateList;

		// Object
		private:
			// Properties
			std::list<IPhysicsUpdate*>::iterator iPhysicsUpdateNode;

		public:
			// Constructor / Destructor
			IPhysicsUpdate();
			virtual ~IPhysicsUpdate();

			// Events
			virtual void onPrePhysicsUpdate();
			virtual void onPostPhysicsUpdate();
	};

	class IRender {
		// Friends
		friend class InTimeEngine;

		// Static
		private:
			// Properties
			static std::list<IRender*> iRenderList;

		// Object
		private:
			// Properties
			std::list<IRender*>::iterator iRenderNode;

		public:
			// Constructor / Destructor
			IRender();
			virtual ~IRender();

			// Events
			virtual void onPreRender();
			virtual void render();
			virtual void onPostRender();
	};

	class IRenderUI {
		// Friends
		friend class InTimeEngine;

		// Static
		private:
			// Properties
			static std::list<IRenderUI*> iRenderUIList;

		// Object
		private:
			// Properties
			std::list<IRenderUI*>::iterator iRenderUINode;

		public:
			// Constructor / Destrctor
			IRenderUI();
			virtual ~IRenderUI();

			// Events
			virtual void renderUI();
	};
}