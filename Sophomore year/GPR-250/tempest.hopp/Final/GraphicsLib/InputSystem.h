#pragma once
#include <allegro5/allegro.h>
#include <Trackable.h>
#include <iostream>
#include <Event.h>
#include "EventSystem.h"
#include "InputEvent.h"
#include "MouseMoveEvent.h"
#include "MousePressedEvent.h"
#include "KeyPressedEvent.h"

using namespace std;

class InputSystem :
    public Trackable
{
    private:
        ALLEGRO_EVENT_QUEUE* mpQueue;
    public:
        InputSystem();
        ~InputSystem();
        void init();
        void cleanup();
        void update();
        void processAllegroKeyEvent(const ALLEGRO_EVENT& theEvent);
        void processAllegroMouseEvent(const ALLEGRO_EVENT& theEvent);
        void processAllegroMouseButtonEvent(const ALLEGRO_EVENT& theEvent);
};


