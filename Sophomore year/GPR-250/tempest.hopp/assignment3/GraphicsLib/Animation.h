#pragma once
#include <Trackable.h>
#include <iostream>
#include <ctime>

#include "Sprite.h"
class Animation :
    public Trackable

{
    private:
        const unsigned int SPRITE_LIST_LENGTH = 16;
        Sprite *mpSprites;
        int mFramesPerSecond;
        int mTimeUntilNextFrame;
        int msPerFrame;
        int mCurrentSprite;
    public:
        Animation();
        Animation(Sprite sprites[], int count);
        ~Animation();
        void Update(int deltaTime);
        Sprite getCurrentSprite();
        void changeSpeed(int speedModifier);
};

