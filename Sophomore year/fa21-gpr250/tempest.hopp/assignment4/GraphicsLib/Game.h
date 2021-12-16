#pragma once
#include <Trackable.h>
#include <iostream>
#include <ctime>
#include <PerformanceTracker.h>

#include "Timer.h"
#include "System.h"
#include "GraphicsSystem.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"
#include "Unit.h"
using namespace std;
class Game :
    public Trackable
{

    const string ASSET_PATH = "..\\..\\shared\\assets\\";
    const string SMURF_FILENAME = "smurf_sprites.png";
    const string DEAN_FILENAME = "dean_sprites.png";
    const string WOODS_FILENAME = "Woods.png";
    private:
        System* mpSystem;
        Unit* mpUnit;
        GraphicsBuffer* mpDeanBuffer;
        GraphicsBuffer* mpSmurfBuffer;
        GraphicsBuffer* mpWoodsBuffer;
        double mTimePerFrame;
        bool mIsRunning;

    public:
        Game();
        ~Game();
        void Init(int width, int height, double fps);
        void defineUnit();
        void Cleanup();
        void DoLoop();
        void getInput();
        void Update(double fps);
        void Render();
};

