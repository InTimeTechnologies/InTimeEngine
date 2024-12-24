#include "GLFWWindow.h"

// class GLFWWindow

// Static | private

// Properties
bool GLFWWindow::initialized = false;

// Functions
bool GLFWWindow::init() {
	if (initialized)
		return true;

	if (!glfwInit())
		return false;

	IT::IWindow::pollEventsFunction = glfwPollEvents;
	IT::IInput::processInput = GLFWJoystick::updateJoysticks;

	IT::IWindow::resetKeyboardInputFunction = resetKeyboardInputs;
	IT::IInput::resetJoystickInputFunction = GLFWJoystick::resetJoystickButtons;

	initialized = true;
	
	return true; // Return success
}
void GLFWWindow::resetKeyboardInputs() {
	for (IWindow* window : IT::IWindow::windowList) {
		GLFWWindow* glfwWindow = (GLFWWindow*)window;
		glfwWindow->input.resetKeys();
		glfwWindow->input.resetMouseButtons();
	}

}

// Static | public

// Properties
int GLFWWindow::defaultWidth = 800;
int GLFWWindow::defaultHeight = 600;
std::string GLFWWindow::defaultName = "GLFW Window";

// Callbacks
void GLFWWindow::keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	GLFWWindow* glfwWindow = (GLFWWindow*)glfwGetWindowUserPointer(window);
	if (glfwWindow == nullptr)
		return;

	int keyIndex = glfwWindow->input.getKeyIndex((GLFWKeyCode)key);

	if (action == GLFW_PRESS) {
		glfwWindow->input.keys[keyIndex].justPressed = true;
		glfwWindow->input.keys[keyIndex].pressed = true;
	}
	if (action == GLFW_REPEAT) {
		glfwWindow->input.keys[keyIndex].repeat = true;
	}
	if (action == GLFW_RELEASE) {
		glfwWindow->input.keys[keyIndex].justReleased = true;
		glfwWindow->input.keys[keyIndex].pressed = false;
	}

	glfwWindow->input.keysToReset.push_front(&glfwWindow->input.keys[keyIndex]);
}
void GLFWWindow::mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	GLFWWindow* glfwWindow = (GLFWWindow*)glfwGetWindowUserPointer(window);
	if (glfwWindow == nullptr)
		return;

	int mouseButtonIndex = glfwWindow->input.getMouseButtonIndex((GLFWMouseButtonCode)button);
	if (action == GLFW_PRESS) {
		glfwWindow->input.mouseButtons[mouseButtonIndex].justPressed = true;
		glfwWindow->input.mouseButtons[mouseButtonIndex].pressed = true;
	}
	if (action == GLFW_RELEASE) {
		glfwWindow->input.mouseButtons[mouseButtonIndex].justReleased = true;
		glfwWindow->input.mouseButtons[mouseButtonIndex].pressed = false;
	}

	glfwWindow->input.mouseButtonsToReset.push_front(&glfwWindow->input.mouseButtons[mouseButtonIndex]);
}

// Object | public

// Constructor / Destructor
GLFWWindow::GLFWWindow() : GLFWWindow(defaultWidth, defaultHeight, defaultName, nullptr, nullptr) {

}
GLFWWindow::GLFWWindow(int width, int height, const std::string& title, GLFWmonitor* monitor, GLFWwindow* share) {
	// Initialize GLFW
	if (!init())
		return;

	// Set window hints prior to creation (remove this in production. This needs to be set outside of this class)
	//glfwWindowHint(GLFW_MAXIMIZED, true);
	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

	// Create and set window user pointer
	window = glfwCreateWindow(width, height, title.c_str(), monitor, share);
	glfwSetWindowUserPointer(window, this);

	// Set callbacks
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseButtonCallback);
}
GLFWWindow::~GLFWWindow() {
	glfwDestroyWindow(window);
}

// Getters
GLFWwindow* GLFWWindow::getWindow() const {
	return window;
}

// Functions
void GLFWWindow::swapBuffers() {
	glfwSwapBuffers(window);
}
