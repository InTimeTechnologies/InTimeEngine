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
 * File: IRenderer.h
 * Author: Christopher Barrios Agosto
 * Created on: 13DEC2024
 *
 * Description:
 *  This class is the interface that graphics engine must override so In Time
 *  Engine object can use it as its renderer.
 *****************************************************************************/

#pragma once

namespace IT {
	class IRenderer {
		// Static
		private:
			// Properties
			static IRenderer* singleton;

		public:
			// Getters
			static IRenderer* getSingleton();

		// Object
		public:
			// Constructor / Destructor
			IRenderer();
			~IRenderer();

			// Functions
			virtual void render();
			virtual void onSurfaceResize(int width, int height);
	};
}
