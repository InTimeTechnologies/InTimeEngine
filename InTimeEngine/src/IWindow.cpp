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
