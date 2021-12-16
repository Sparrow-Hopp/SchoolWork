#pragma once
#include <Event.h>
#include "InputEvent.h"
#include "Vector2D.h"

enum GameEvents {
	ADD_UNIT = NUM_EVENT_TYPES,
	DEL_UNIT,
	FREEZE_UNITS,
	EXIT_GAME,
	MOVE_GAME,
	NUM_GAME_EVENTS
};

class AddUnitEvent : public Event
{
	private:
		Vector2D mLocation;
	public:
		AddUnitEvent(Vector2D location) : Event((EventType)GameEvents::ADD_UNIT)
		{
			mLocation = location;
		}
		~AddUnitEvent()
		{
		}
		Vector2D getLocation() const { return mLocation; };
};

class DelUnitEvent : public Event
{
	private:
		Vector2D mLocation;
	public:
		DelUnitEvent(Vector2D location) : Event((EventType)GameEvents::DEL_UNIT)
		{
			mLocation = location;
		}
		~DelUnitEvent()
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
