#pragma once
#include <Trackable.h>
#include "GraphicsBuffer.h"
#include "GraphicsSystem.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <Vector2D.h>

using namespace std;

class Button :
    public Trackable
{
    private:
        Font* mpSmallFont;
        GraphicsBuffer* mpBackground;
        string mLocalText[3];
        int mCurrentLanguage;
        const int NUM_LANGUAGES = 3;
        Vector2D mLocation;
        bool mShouldDraw = false;
    public:
        Button(GraphicsBuffer* background, string texts[3], Vector2D loc, Font* font);
        ~Button();
        void Draw();
        void swapLanguage();
        Vector2D getLocation() { return mLocation; };
        bool isPressed(Vector2D pressLoc);
        void setDrawState() { mShouldDraw = !mShouldDraw; };
};

