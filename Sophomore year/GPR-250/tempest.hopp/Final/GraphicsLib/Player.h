#pragma once
#include <Trackable.h>
#include "GraphicsBuffer.h"
#include <Vector2D.h>
#include "GraphicsSystem.h"

using namespace std;

class Player :
    public Trackable
{
    const int MAX_LIVES = 3;
    private:
        GraphicsBuffer* mpSprite;
        Vector2D mLocation;
        int mTime, mLives = MAX_LIVES, mSecondInFrames = 20, mTimeUntilSecond, mMaxTime;
        Font* mpSmallFont;
    public:
        Player(GraphicsBuffer* sprite, Vector2D location, Font* font);
        Vector2D getLocation() { return mLocation; };
        void Draw();
        void setLocation(Vector2D location) { mLocation.setX(location.getX()); };
        void Update();
        int getTime() { return mTime; };
        int getLives() { return mLives; };
        void dockLife() { mLives--; };
        void restart();
        void levelUp();
        void loadDataFromFile(int level) { mMaxTime = 5 + 5 * level; };
};

