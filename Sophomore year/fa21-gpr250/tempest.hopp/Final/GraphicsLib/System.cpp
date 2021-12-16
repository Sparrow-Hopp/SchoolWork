#include "System.h"
#include "GraphicsSystem.h"
#include "InputSystem.h"

#include <iostream>

using namespace std;

System::System()
{
	mpGraphicsSystem = new GraphicsSystem;
	mpInputSystem = new InputSystem;
}

System::~System()
{
	cleanup();
	delete mpInputSystem;
	delete mpGraphicsSystem;
}

bool System::init(unsigned int width, unsigned int height)
{
	if (!mIsInitted)
	{
		if (!al_init())
		{
			cout << "error initting Allegro\n";
			return false;
		}
		else
		{
			bool ret = mpGraphicsSystem->init(width, height);
			if (!ret)
			{
				cout << "error initting GraphicsSystem\n";
				return false;
			}
		}
		mpInputSystem->init();
		mIsInitted = true;
	}
	return true;
}

void System::cleanup()
{
	if (mIsInitted)
	{
		mpGraphicsSystem->cleanup();
		mIsInitted = false;
		mpInputSystem->cleanup();
		al_uninstall_keyboard();
		al_uninstall_mouse();
	}
}

bool System::isKeyPressed(Input::Key key)
{
	ALLEGRO_KEYBOARD_STATE state;
	al_get_keyboard_state(&state);
	return al_key_down(&state, key);
}

bool System::isMouseButtonPressed(Input::MouseButton mouse)
{
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	switch (mouse)
	{
		case Input::MouseButton::LEFT:
			return (state.buttons & 1);
		case Input::MouseButton::RIGHT:
			return (state.buttons & 2);
		case Input::MouseButton::CENTER:
			return (state.buttons & 4);
	}
	return false;
}

Vector2D System::getMousePos()
{
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);
	Vector2D pos(state.x, state.y);
	return pos;
}

