#include "IInput.h"

// class IInput

// Static | public

// Properties
std::function<void()> IT::IInput::resetJoystickInputFunction = IT::IInput::emptyVoidFunction;
std::function<void()> IT::IInput::processInput = IT::IInput::emptyVoidFunction;

// Functions
void IT::IInput::emptyVoidFunction() {
	// Left empty intentionally. This is the default function of initFunction
}
