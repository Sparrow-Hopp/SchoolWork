#include "InputSystem.h"

InputSystem::InputSystem()
{
}

InputSystem::~InputSystem()
{
}

void InputSystem::init()
{
	if (!al_install_keyboard())
	{
		cout << "error installing keyboard" << endl;
		return;
	}
	if (!al_install_mouse())
	{
		cout << "error installing mouse" << endl;
		return;
	}
	mpQueue = al_create_event_queue();
	if (mpQueue == NULL);
	else
	{
		al_register_event_source(mpQueue, al_get_keyboard_event_source());
		al_register_event_source(mpQueue, al_get_mouse_event_source());
	}
}

void InputSystem::cleanup()
{
	al_unregister_event_source(mpQueue, al_get_keyboard_event_source());
	al_unregister_event_source(mpQueue, al_get_mouse_event_source());
	al_destroy_event_queue(mpQueue);
}

void InputSystem::update()
{
	if (mpQueue == NULL);
	else
	{
		ALLEGRO_EVENT theEvent;
		while (al_get_next_event(mpQueue, &theEvent))
		{
			switch (theEvent.type)
			{
				case ALLEGRO_EVENT_KEY_DOWN:
				case ALLEGRO_EVENT_KEY_UP:
					processAllegroKeyEvent(theEvent);
					break;
				case ALLEGRO_EVENT_MOUSE_AXES:
					processAllegroMouseEvent(theEvent);
					break;
				case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
				case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
					processAllegroMouseButtonEvent(theEvent);
					break;
			}
		}
	}

}

void InputSystem::processAllegroKeyEvent(const ALLEGRO_EVENT& theEvent)
{
	Input::PressState pressedState = Input::PressState::PRESSED;
	if (theEvent.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		pressedState = Input::PressState::RELEASED;
		KeyPressedEvent keyEvent = KeyPressedEvent((Input::Key)theEvent.keyboard.keycode, pressedState);
		EventSystem::getInstance()->fireEvent(keyEvent); 
	}
}

void InputSystem::processAllegroMouseEvent(const ALLEGRO_EVENT& theEvent)
{
	Input::PressState pressedState = Input::PressState::PRESSED;
	if (theEvent.type == ALLEGRO_EVENT_MOUSE_AXES)
	{
		pressedState = Input::PressState::RELEASED;
		MouseMoveEvent moveEvent = MouseMoveEvent(Vector2D(theEvent.mouse.x, theEvent.mouse.y));
		EventSystem::getInstance()->fireEvent(moveEvent);
	}
}

void InputSystem::processAllegroMouseButtonEvent(const ALLEGRO_EVENT& theEvent)
{
	Input::PressState pressedState = Input::PressState::PRESSED;
	if (theEvent.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
	{
		pressedState = Input::PressState::RELEASED;
		MousePressedEvent mouseEvent = MousePressedEvent((Input::MouseButton)theEvent.mouse.button, pressedState, Vector2D(theEvent.mouse.x, theEvent.mouse.y));
		EventSystem::getInstance()->fireEvent(mouseEvent);
	}
}
