#include "MouseMoveEvent.h"

MouseMoveEvent::MouseMoveEvent(Vector2D location)
	: Event((EventType)InputEvent::MOUSE_MOVE)
{
	mLocation = location;
}
