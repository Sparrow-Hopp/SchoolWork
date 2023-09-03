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
        double mFramesPerSecond;
        double mTimeUntilNextFrame;
        double msPerFrame;
        int mCurrentSprite;
        bool mShouldLoop;
    public:
        Animation();
        Animation(Sprite sprites[], int count);
        ~Animation();
        void Update(double deltaTime);
        Sprite getCurrentSprite();
        void changeSpeed(int speedModifier);
        void stopAnimating() { mShouldLoop = !mShouldLoop; };
};

