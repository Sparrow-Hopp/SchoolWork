#include "KeyPressedEvent.h"

KeyPressedEvent::KeyPressedEvent(Input::Key key, Input::PressState pressState)
	: Event((EventType)InputEvent::KEY_PRESSED)
{
	mKey = key;
	mPressState = pressState;
}
