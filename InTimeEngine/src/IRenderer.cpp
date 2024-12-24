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
