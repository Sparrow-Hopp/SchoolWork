#pragma once
#include "Event.h"
#include "EventListener.h"
#include "EventSystem.h"
//#include "keycodes.h"



enum InputEvent {
    NONE = EventType::NUM_BASE_EVENT_TYPES,
    KEY_PRESSED,
	MOUSE_MOVE,
    MOUSE_PRESSED,
	NUM_EVENT_TYPES
};


namespace Input
{
	enum MouseButton
	{
		LEFT = 1,
		RIGHT = 2,
		CENTER = 3,
	};
	enum Key
	{
		ENTER = 67,
		SPACE = 75,
		ESCAPE = 59,
		F = 6,
		S = 19
	};
	enum PressState {
		PRESSED,
		RELEASED
	};
}
