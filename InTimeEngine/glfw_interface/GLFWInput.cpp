#include "GLFWInput.h"

// class GLFWInput

// Object | public

// Constructor / Destructor
GLFWInput::GLFWInput() {
	// Register all the keys
	{
		int i = 0;
		keys[i++] = GLFWKey(GLFWKeyCode::UNKNOWN, "unknown");
		keys[i++] = GLFWKey(GLFWKeyCode::SPACE, " ");
		keys[i++] = GLFWKey(GLFWKeyCode::APOSTROPHE, "\'");
		keys[i++] = GLFWKey(GLFWKeyCode::COMMA, ",");
		keys[i++] = GLFWKey(GLFWKeyCode::MINUS, "-");
		keys[i++] = GLFWKey(GLFWKeyCode::PERIOD, ".");
		keys[i++] = GLFWKey(GLFWKeyCode::SLASH, "/");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_0, "0");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_1, "1");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_2, "2");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_3, "3");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_4, "4");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_5, "5");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_6, "6");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_7, "7");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_8, "8");
		keys[i++] = GLFWKey(GLFWKeyCode::ALPHA_9, "9");
		keys[i++] = GLFWKey(GLFWKeyCode::SEMICOLON, ";");
		keys[i++] = GLFWKey(GLFWKeyCode::EQUAL, "=");
		keys[i++] = GLFWKey(GLFWKeyCode::A, "a");
		keys[i++] = GLFWKey(GLFWKeyCode::B, "b");
		keys[i++] = GLFWKey(GLFWKeyCode::C, "c");
		keys[i++] = GLFWKey(GLFWKeyCode::D, "d");
		keys[i++] = GLFWKey(GLFWKeyCode::E, "e");
		keys[i++] = GLFWKey(GLFWKeyCode::F, "f");
		keys[i++] = GLFWKey(GLFWKeyCode::G, "g");
		keys[i++] = GLFWKey(GLFWKeyCode::H, "h");
		keys[i++] = GLFWKey(GLFWKeyCode::I, "i");
		keys[i++] = GLFWKey(GLFWKeyCode::J, "j");
		keys[i++] = GLFWKey(GLFWKeyCode::K, "k");
		keys[i++] = GLFWKey(GLFWKeyCode::L, "l");
		keys[i++] = GLFWKey(GLFWKeyCode::M, "m");
		keys[i++] = GLFWKey(GLFWKeyCode::N, "n");
		keys[i++] = GLFWKey(GLFWKeyCode::O, "o");
		keys[i++] = GLFWKey(GLFWKeyCode::P, "p");
		keys[i++] = GLFWKey(GLFWKeyCode::Q, "q");
		keys[i++] = GLFWKey(GLFWKeyCode::R, "r");
		keys[i++] = GLFWKey(GLFWKeyCode::S, "s");
		keys[i++] = GLFWKey(GLFWKeyCode::T, "t");
		keys[i++] = GLFWKey(GLFWKeyCode::U, "u");
		keys[i++] = GLFWKey(GLFWKeyCode::V, "v");
		keys[i++] = GLFWKey(GLFWKeyCode::W, "w");
		keys[i++] = GLFWKey(GLFWKeyCode::X, "x");
		keys[i++] = GLFWKey(GLFWKeyCode::Y, "y");
		keys[i++] = GLFWKey(GLFWKeyCode::Z, "z");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_BRACKET, "[");
		keys[i++] = GLFWKey(GLFWKeyCode::BACKSLASH, "\\");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_BRACKET, "]");
		keys[i++] = GLFWKey(GLFWKeyCode::GRAVE_ACCENT, "`");
		keys[i++] = GLFWKey(GLFWKeyCode::WORLD_1, "world 1");
		keys[i++] = GLFWKey(GLFWKeyCode::WORLD_2, "world 2");
		keys[i++] = GLFWKey(GLFWKeyCode::ESCAPE, "\e");
		keys[i++] = GLFWKey(GLFWKeyCode::ENTER, "\n");
		keys[i++] = GLFWKey(GLFWKeyCode::TAB, "\t");
		keys[i++] = GLFWKey(GLFWKeyCode::BACKSPACE, "\b");
		keys[i++] = GLFWKey(GLFWKeyCode::INSERT, "insert");
		keys[i++] = GLFWKey(GLFWKeyCode::_DELETE, "delete");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_ARROW, "right arrow");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_ARROW, "left arrow");
		keys[i++] = GLFWKey(GLFWKeyCode::DOWN_ARROW, "down arrow");
		keys[i++] = GLFWKey(GLFWKeyCode::UP_ARROW, "up arrow");
		keys[i++] = GLFWKey(GLFWKeyCode::PAGE_UP, "page up");
		keys[i++] = GLFWKey(GLFWKeyCode::PAGE_DOWN, "page down");
		keys[i++] = GLFWKey(GLFWKeyCode::HOME, "home");
		keys[i++] = GLFWKey(GLFWKeyCode::END, "end");
		keys[i++] = GLFWKey(GLFWKeyCode::CAPS_LOCK, "caps lock");
		keys[i++] = GLFWKey(GLFWKeyCode::SCROLL_LOCK, "scroll lock");
		keys[i++] = GLFWKey(GLFWKeyCode::NUM_LOCK, "num lock");
		keys[i++] = GLFWKey(GLFWKeyCode::PRINT_SCREEN, "print screen");
		keys[i++] = GLFWKey(GLFWKeyCode::PAUSE, "pause");
		keys[i++] = GLFWKey(GLFWKeyCode::F1, "f1");
		keys[i++] = GLFWKey(GLFWKeyCode::F2, "f2");
		keys[i++] = GLFWKey(GLFWKeyCode::F3, "f3");
		keys[i++] = GLFWKey(GLFWKeyCode::F4, "f4");
		keys[i++] = GLFWKey(GLFWKeyCode::F5, "f5");
		keys[i++] = GLFWKey(GLFWKeyCode::F6, "f6");
		keys[i++] = GLFWKey(GLFWKeyCode::F7, "f7");
		keys[i++] = GLFWKey(GLFWKeyCode::F8, "f8");
		keys[i++] = GLFWKey(GLFWKeyCode::F9, "f9");
		keys[i++] = GLFWKey(GLFWKeyCode::F10, "f10");
		keys[i++] = GLFWKey(GLFWKeyCode::F11, "f11");
		keys[i++] = GLFWKey(GLFWKeyCode::F12, "f12");
		keys[i++] = GLFWKey(GLFWKeyCode::F13, "f13");
		keys[i++] = GLFWKey(GLFWKeyCode::F14, "f14");
		keys[i++] = GLFWKey(GLFWKeyCode::F15, "f15");
		keys[i++] = GLFWKey(GLFWKeyCode::F16, "f16");
		keys[i++] = GLFWKey(GLFWKeyCode::F17, "f17");
		keys[i++] = GLFWKey(GLFWKeyCode::F18, "f18");
		keys[i++] = GLFWKey(GLFWKeyCode::F19, "f19");
		keys[i++] = GLFWKey(GLFWKeyCode::F20, "f20");
		keys[i++] = GLFWKey(GLFWKeyCode::F21, "f21");
		keys[i++] = GLFWKey(GLFWKeyCode::F22, "f22");
		keys[i++] = GLFWKey(GLFWKeyCode::F23, "f23");
		keys[i++] = GLFWKey(GLFWKeyCode::F24, "f24");
		keys[i++] = GLFWKey(GLFWKeyCode::F25, "f25");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_0, "numpad 0");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_1, "numpad 1");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_2, "numpad 2");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_3, "numpad 3");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_4, "numpad 4");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_5, "numpad 5");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_6, "numpad 6");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_7, "numpad 7");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_8, "numpad 8");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_9, "numpad 9");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_DECIMAL, "numpad .");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_DIVIDE, "numpad /");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_MULTIPLY, "numpad *");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_SUBTRACT, "numpad -");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_ADD, "numpad +");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_ENTER, "numpad enter");
		keys[i++] = GLFWKey(GLFWKeyCode::NUMPAD_EQUAL, "numpad =");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_SHIFT, "left shift");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_CONTROL, "left control");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_ALT, "left alt");
		keys[i++] = GLFWKey(GLFWKeyCode::LEFT_SUPER, "left super");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_SHIFT, "left shift");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_CONTROL, "right control");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_ALT, "right alt");
		keys[i++] = GLFWKey(GLFWKeyCode::RIGHT_SUPER, "right super");
		keys[i++] = GLFWKey(GLFWKeyCode::MENU, "menu");
	}
}
GLFWInput::~GLFWInput() {

}

// Functinos
void GLFWInput::resetKeys() {
	for (GLFWKey* key : keysToReset) {
		key->justPressed = false;
		key->justReleased = false;
		key->repeat = false;
	}
	keysToReset.clear();
}
GLFWKey GLFWInput::getKey(GLFWKeyCode keyCode) {
	// Key index
	int i = getKeyIndex(keyCode);

	// Error check
	if (i < 0)
		return GLFWKey();

	// Return key using index
	return keys[i];
}
int GLFWInput::getKeyIndex(GLFWKeyCode keyCode) {
	// Search for index associated with key in the list
	int i = 0;
	switch (keyCode) {
		case GLFWKeyCode::UNKNOWN:         i = 0;   break;
		case GLFWKeyCode::SPACE:           i = 1;   break;
		case GLFWKeyCode::APOSTROPHE:      i = 2;   break;
		case GLFWKeyCode::COMMA:           i = 3;   break;
		case GLFWKeyCode::MINUS:           i = 4;   break;
		case GLFWKeyCode::PERIOD:          i = 5;   break;
		case GLFWKeyCode::SLASH:           i = 6;   break;
		case GLFWKeyCode::ALPHA_0:         i = 7;   break;
		case GLFWKeyCode::ALPHA_1:         i = 8;   break;
		case GLFWKeyCode::ALPHA_2:         i = 9;   break;
		case GLFWKeyCode::ALPHA_3:         i = 10;  break;
		case GLFWKeyCode::ALPHA_4:         i = 11;  break;
		case GLFWKeyCode::ALPHA_5:         i = 12;  break;
		case GLFWKeyCode::ALPHA_6:         i = 13;  break;
		case GLFWKeyCode::ALPHA_7:         i = 14;  break;
		case GLFWKeyCode::ALPHA_8:         i = 15;  break;
		case GLFWKeyCode::ALPHA_9:         i = 16;  break;
		case GLFWKeyCode::SEMICOLON:       i = 17;  break;
		case GLFWKeyCode::EQUAL:           i = 18;  break;
		case GLFWKeyCode::A:               i = 19;  break;
		case GLFWKeyCode::B:               i = 20;  break;
		case GLFWKeyCode::C:               i = 21;  break;
		case GLFWKeyCode::D:               i = 22;  break;
		case GLFWKeyCode::E:               i = 23;  break;
		case GLFWKeyCode::F:               i = 24;  break;
		case GLFWKeyCode::G:               i = 25;  break;
		case GLFWKeyCode::H:               i = 26;  break;
		case GLFWKeyCode::I:               i = 27;  break;
		case GLFWKeyCode::J:               i = 28;  break;
		case GLFWKeyCode::K:               i = 29;  break;
		case GLFWKeyCode::L:               i = 30;  break;
		case GLFWKeyCode::M:               i = 31;  break;
		case GLFWKeyCode::N:               i = 32;  break;
		case GLFWKeyCode::O:               i = 33;  break;
		case GLFWKeyCode::P:               i = 34;  break;
		case GLFWKeyCode::Q:               i = 35;  break;
		case GLFWKeyCode::R:               i = 36;  break;
		case GLFWKeyCode::S:               i = 37;  break;
		case GLFWKeyCode::T:               i = 38;  break;
		case GLFWKeyCode::U:               i = 39;  break;
		case GLFWKeyCode::V:               i = 40;  break;
		case GLFWKeyCode::W:               i = 41;  break;
		case GLFWKeyCode::X:               i = 42;  break;
		case GLFWKeyCode::Y:               i = 43;  break;
		case GLFWKeyCode::Z:               i = 44;  break;
		case GLFWKeyCode::LEFT_BRACKET:    i = 45;  break;
		case GLFWKeyCode::BACKSLASH:       i = 46;  break;
		case GLFWKeyCode::RIGHT_BRACKET:   i = 47;  break;
		case GLFWKeyCode::GRAVE_ACCENT:    i = 48;  break;
		case GLFWKeyCode::WORLD_1:         i = 49;  break;
		case GLFWKeyCode::WORLD_2:         i = 50;  break;
		case GLFWKeyCode::ESCAPE:          i = 51;  break;
		case GLFWKeyCode::ENTER:           i = 52;  break;
		case GLFWKeyCode::TAB:             i = 53;  break;
		case GLFWKeyCode::BACKSPACE:       i = 54;  break;
		case GLFWKeyCode::INSERT:          i = 55;  break;
		case GLFWKeyCode::_DELETE:         i = 56;  break;
		case GLFWKeyCode::RIGHT_ARROW:     i = 57;  break;
		case GLFWKeyCode::LEFT_ARROW:      i = 58;  break;
		case GLFWKeyCode::DOWN_ARROW:      i = 59;  break;
		case GLFWKeyCode::UP_ARROW:        i = 60;  break;
		case GLFWKeyCode::PAGE_UP:         i = 61;  break;
		case GLFWKeyCode::PAGE_DOWN:       i = 62;  break;
		case GLFWKeyCode::HOME:            i = 63;  break;
		case GLFWKeyCode::END:             i = 64;  break;
		case GLFWKeyCode::CAPS_LOCK:       i = 65;  break;
		case GLFWKeyCode::SCROLL_LOCK:     i = 66;  break;
		case GLFWKeyCode::NUM_LOCK:        i = 67;  break;
		case GLFWKeyCode::PRINT_SCREEN:    i = 68;  break;
		case GLFWKeyCode::PAUSE:           i = 69;  break;
		case GLFWKeyCode::F1:              i = 70;  break;
		case GLFWKeyCode::F2:              i = 71;  break;
		case GLFWKeyCode::F3:              i = 72;  break;
		case GLFWKeyCode::F4:              i = 73;  break;
		case GLFWKeyCode::F5:              i = 74;  break;
		case GLFWKeyCode::F6:              i = 75;  break;
		case GLFWKeyCode::F7:              i = 76;  break;
		case GLFWKeyCode::F8:              i = 77;  break;
		case GLFWKeyCode::F9:              i = 78;  break;
		case GLFWKeyCode::F10:             i = 79;  break;
		case GLFWKeyCode::F11:             i = 80;  break;
		case GLFWKeyCode::F12:             i = 81;  break;
		case GLFWKeyCode::F13:             i = 82;  break;
		case GLFWKeyCode::F14:             i = 83;  break;
		case GLFWKeyCode::F15:             i = 84;  break;
		case GLFWKeyCode::F16:             i = 85;  break;
		case GLFWKeyCode::F17:             i = 86;  break;
		case GLFWKeyCode::F18:             i = 87;  break;
		case GLFWKeyCode::F19:             i = 88;  break;
		case GLFWKeyCode::F20:             i = 89;  break;
		case GLFWKeyCode::F21:             i = 90;  break;
		case GLFWKeyCode::F22:             i = 91;  break;
		case GLFWKeyCode::F23:             i = 92;  break;
		case GLFWKeyCode::F24:             i = 93;  break;
		case GLFWKeyCode::F25:             i = 94;  break;
		case GLFWKeyCode::NUMPAD_0:        i = 95;  break;
		case GLFWKeyCode::NUMPAD_1:        i = 96;  break;
		case GLFWKeyCode::NUMPAD_2:        i = 97;  break;
		case GLFWKeyCode::NUMPAD_3:        i = 98;  break;
		case GLFWKeyCode::NUMPAD_4:        i = 99;  break;
		case GLFWKeyCode::NUMPAD_5:        i = 100; break;
		case GLFWKeyCode::NUMPAD_6:        i = 101; break;
		case GLFWKeyCode::NUMPAD_7:        i = 102; break;
		case GLFWKeyCode::NUMPAD_8:        i = 103; break;
		case GLFWKeyCode::NUMPAD_9:        i = 104; break;
		case GLFWKeyCode::NUMPAD_DECIMAL:  i = 105; break;
		case GLFWKeyCode::NUMPAD_DIVIDE:   i = 106; break;
		case GLFWKeyCode::NUMPAD_MULTIPLY: i = 107; break;
		case GLFWKeyCode::NUMPAD_SUBTRACT: i = 108; break;
		case GLFWKeyCode::NUMPAD_ADD:      i = 109; break;
		case GLFWKeyCode::NUMPAD_ENTER:    i = 110; break;
		case GLFWKeyCode::NUMPAD_EQUAL:    i = 111; break;
		case GLFWKeyCode::LEFT_SHIFT:      i = 112; break;
		case GLFWKeyCode::LEFT_CONTROL:    i = 113; break;
		case GLFWKeyCode::LEFT_ALT:        i = 114; break;
		case GLFWKeyCode::LEFT_SUPER:      i = 115; break;
		case GLFWKeyCode::RIGHT_SHIFT:     i = 116; break;
		case GLFWKeyCode::RIGHT_CONTROL:   i = 117; break;
		case GLFWKeyCode::RIGHT_ALT:       i = 118; break;
		case GLFWKeyCode::RIGHT_SUPER:     i = 119; break;
		case GLFWKeyCode::MENU:            i = 120; break;
		default:                           i = 0;   break;
	}

	// Return index
	return i;
}

void GLFWInput::resetMouseButtons() {
	for (GLFWMouseButton* mouseButton : mouseButtonsToReset) {
		mouseButton->justPressed = false;
		mouseButton->justReleased = false;
	}
}
GLFWMouseButton GLFWInput::getMouseButton(GLFWMouseButtonCode mouseButtonCode) {
	// Mouse button index
	int i = getMouseButtonIndex(mouseButtonCode);

	// Error check
	if (i < 0)
		return GLFWMouseButton();

	// Return mouse button code using index
	return mouseButtons[i];

}
int GLFWInput::getMouseButtonIndex(GLFWMouseButtonCode mouseButtonCode) {
	int i = 0;

	switch (mouseButtonCode) {
		case GLFWMouseButtonCode::BUTTON_CODE_1: i = 0; break;
		case GLFWMouseButtonCode::BUTTON_CODE_2: i = 1; break;
		case GLFWMouseButtonCode::BUTTON_CODE_3: i = 2; break;
		case GLFWMouseButtonCode::BUTTON_CODE_4: i = 3; break;
		case GLFWMouseButtonCode::BUTTON_CODE_5: i = 4; break;
		case GLFWMouseButtonCode::BUTTON_CODE_6: i = 5; break;
		case GLFWMouseButtonCode::BUTTON_CODE_7: i = 6; break;
		case GLFWMouseButtonCode::BUTTON_CODE_8: i = 7; break;
		default:
			return -1;
	}
	
	return i;
}
