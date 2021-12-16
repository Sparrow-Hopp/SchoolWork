#pragma once
#include <Event.h>
#include <iostream>
#include "System.h"
#include "InputEvent.h"

using namespace std;

class KeyPressedEvent :
    public Event
{
    private:
        Input::Key mKey;
        Input::PressState mPressState;
    public:
        KeyPressedEvent(Input::Key key, Input::PressState pressState);
        Input::Key getKey() const { return mKey; };
};

