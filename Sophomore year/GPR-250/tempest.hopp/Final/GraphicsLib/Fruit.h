#pragma once
#include <Trackable.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_ttf.h>
#include "GraphicsBuffer.h"
#include <Vector2D.h>
#include "GraphicsSystem.h"

using namespace std;

class Fruit :
    public Trackable
{
    private:
        GraphicsBuffer* mpBuffer;
        Vector2D mLocation;
        ALLEGRO_SAMPLE* mpSample;
        int mWidth = 128;
        int mHeight = 128;
        double mFramesPerSecond, mTimeUntilNextFrame, msPerFrame;
    public:
        Fruit(GraphicsBuffer* buffer, Vector2D location);
        ~Fruit();
        void init(string file_location);
        void Draw();
        void Update(double deltaTime);
        Vector2D getLocation() { return mLocation; };
        int getWidth() { return mWidth; };
        int getHeight() { return mHeight; };
        void playAudio() { al_play_sample(mpSample, 0.25f, 0, 1, ALLEGRO_PLAYMODE_ONCE, nullptr); };
};

