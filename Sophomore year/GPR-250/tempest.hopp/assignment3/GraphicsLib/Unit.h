#pragma once
#include <Trackable.h>

#include "Animation.h"
#include "System.h"
#include "GraphicsSystem.h"
class Unit :
    public Trackable
{
    private:
        Vector2D mLocation;
        Animation* mpDeanAnim;
        Animation* mpSmurfAnim;
        bool mSmurfRunning;
    public:
        Unit();
        Unit(Sprite deanSprites[], Sprite smurfSprites[], Vector2D loc);
        ~Unit();
        void Update(int deltaTime);
        void Draw();
        void setAnimation();
        void changeSpeed(int speedModifier);
        void setLocation(Vector2D newLoc);
};

