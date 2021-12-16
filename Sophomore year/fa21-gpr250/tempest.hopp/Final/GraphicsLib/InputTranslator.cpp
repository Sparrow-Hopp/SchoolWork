#include "InputTranslator.h"

InputTranslator::InputTranslator()
{
	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->addListener((EventType)MOUSE_PRESSED, this);
	pEventSystem->addListener((EventType)MOUSE_MOVE, this);
	pEventSystem->addListener((EventType)KEY_PRESSED, this);
}

InputTranslator::~InputTranslator()
{
	cleanup();
}

void InputTranslator::handleEvent(const Event& theEvent)
{
	if (theEvent.getType() == MOUSE_PRESSED)
	{
		const MousePressedEvent& mousePressedEvent = static_cast<const MousePressedEvent&>(theEvent);
		if (mousePressedEvent.getButton() == Input::MouseButton::LEFT)
		{
			PressButtonEvent pressEvent = PressButtonEvent(mousePressedEvent.getLocation());
			EventSystem::getInstance()->fireEvent(pressEvent);
		}
	}
	else if (theEvent.getType() == MOUSE_MOVE)
	{
		const MouseMoveEvent& mouseMoveEvent = static_cast<const MouseMoveEvent&>(theEvent);
		MoveGameEvent moveEvent = MoveGameEvent(mouseMoveEvent.getLocation());
		EventSystem::getInstance()->fireEvent(moveEvent);
	}
	else if (theEvent.getType() == KEY_PRESSED)
	{
		const KeyPressedEvent& keyPressedEvent = static_cast<const KeyPressedEvent&>(theEvent);
		if (keyPressedEvent.getKey() == Input::Key::SPACE)
		{
			FreezeUnitsEvent freezeEvent = FreezeUnitsEvent();
			EventSystem::getInstance()->fireEvent(freezeEvent);
		}
		else if (keyPressedEvent.getKey() == Input::Key::ESCAPE)
		{
			ExitGameEvent exitEvent = ExitGameEvent();
			EventSystem::getInstance()->fireEvent(exitEvent);
		}
	}
}

void InputTranslator::cleanup()
{
	EventSystem* pEventSystem = EventSystem::getInstance();
	pEventSystem->removeListener((EventType)MOUSE_PRESSED, this);
	pEventSystem->removeListener((EventType)MOUSE_MOVE, this);
	pEventSystem->removeListener((EventType)KEY_PRESSED, this);
}
