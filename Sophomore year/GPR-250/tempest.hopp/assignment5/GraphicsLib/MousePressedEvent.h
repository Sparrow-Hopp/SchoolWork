#pragma once
#include <Event.h>
#include <iostream>
#include "Vector2D.h"
#include "System.h"
#include "InputEvent.h"

class MousePressedEvent :
    public Event
{
    private:
        Input::MouseButton mButton;
        Input::PressState mPressState;
        Vector2D mLocation;
    public:
        MousePressedEvent(Input::MouseButton button, Input::PressState pressState, Vector2D location);
        Input::MouseButton getButton() const { return mButton; };
        Vector2D getLocation() const { return mLocation; };
};

