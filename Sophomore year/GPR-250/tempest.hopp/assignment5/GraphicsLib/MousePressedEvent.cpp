#include "MousePressedEvent.h"

MousePressedEvent::MousePressedEvent(Input::MouseButton button, Input::PressState pressState, Vector2D location)
	: Event((EventType)InputEvent::MOUSE_PRESSED)
{
	mButton = button;
	mPressState = pressState;
	mLocation = location;
}
