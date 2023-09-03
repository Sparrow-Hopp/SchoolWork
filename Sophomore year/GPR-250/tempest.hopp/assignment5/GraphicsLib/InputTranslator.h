#pragma once
#include "Event.h"
#include "EventListener.h"
#include "EventSystem.h"
#include "InputEvent.h"
#include "MouseMoveEvent.h"
#include "MousePressedEvent.h"
#include "KeyPressedEvent.h"
#include "GameEvents.h"

class InputTranslator :
    public EventListener
{
    public:
        InputTranslator();
        ~InputTranslator();
        virtual void handleEvent(const Event& theEvent) override;
        void cleanup();
};

