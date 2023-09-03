#pragma once
#include <Trackable.h>
#include <iostream>
#include <iterator>
#include <map>
#include "Button.h"

class ButtonManager :
    public Trackable
{
    private:
        map<string, Button*> mButtonMap;
    public:
        ButtonManager();
        ~ButtonManager();
        void addButton(string key, Button* buttonToAdd);
        void delButton(string key);
        Button* getButton(string key);
        void clear();
        void draw();
        void swapLanguage();
};

