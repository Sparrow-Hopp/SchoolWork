#pragma once
#include <Event.h>
#include <iostream>
#include "Vector2D.h"
#include "System.h"
#include "InputEvent.h"

class MouseMoveEvent :
    public Event
{
    private:
        Vector2D mLocation;
    public:
        MouseMoveEvent(Vector2D location);
        Vector2D getLocation() const { return mLocation; };
};

