#pragma once
#include <Event.h>
#include "InputEvent.h"
#include "Vector2D.h"

enum GameEvents {
	PRESS_BUTTON = NUM_EVENT_TYPES,
	FREEZE_UNITS,
	EXIT_GAME,
	MOVE_GAME,
	NUM_GAME_EVENTS
};

class PressButtonEvent : public Event
{
	private:
		Vector2D mLocation;
	public:
		PressButtonEvent(Vector2D location) : Event((EventType)GameEvents::PRESS_BUTTON)
		{
			mLocation = location;
		}
		~PressButtonEvent()
		{
		}
		Vector2D getLocation() const { return mLocation; };
};

class FreezeUnitsEvent : public Event
{
	public:
		FreezeUnitsEvent() : Event((EventType)GameEvents::FREEZE_UNITS)
		{
		}
		~FreezeUnitsEvent()
		{
		}
};

class ExitGameEvent : public Event
{
	public:
		ExitGameEvent() : Event((EventType)GameEvents::EXIT_GAME)
		{
		}
		~ExitGameEvent()
		{
		}
};

class MoveGameEvent : public Event
{
	private:
		Vector2D mLocation;
	public:
		MoveGameEvent(Vector2D location) : Event((EventType)GameEvents::MOVE_GAME)
		{
			mLocation = location;
		}
		~MoveGameEvent()
		{
		}
		Vector2D getLocation() const { return mLocation; };
};
