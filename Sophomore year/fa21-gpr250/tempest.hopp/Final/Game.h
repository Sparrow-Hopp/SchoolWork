#pragma once
#include <Trackable.h>
#include <iostream>
#include <ctime>
#include <PerformanceTracker.h>
#include <fstream>

#include "Event.h"
#include "EventListener.h"
#include "EventSystem.h"
#include "GameEvents.h"
#include "Timer.h"
#include "System.h"
#include "GraphicsSystem.h"
#include "Sprite.h"
#include "GraphicsBuffer.h"
#include "Unit.h"
#include "UnitManager.h"
#include "GraphicsBufferManager.h"
#include "InputTranslator.h"
#include "Button.h"
#include "Player.h"
#include "FruitManager.h"
#include "ButtonManager.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

enum Scene {
    NEW_GAME_SCENE,
    OPTIONS_SCENE,
    GAME_SCENE,
    LOSE_SCENE,
    LEVEL_UP_SCENE
};

class Game :
    public Trackable, public EventListener
{

    const string SHARED_ASSET_PATH = "..\\..\\shared\\assets\\";
    const string SOLO_ASSET_PATH = "Files\\";
    const string SMURF_FILENAME = "smurf_sprites.png";
    const string FONT_FILENAME = "cour.ttf";
    const string ENG_FILENAME = "english.txt";
    const string DUT_FILENAME = "dutch.txt";
    const string ESP_FILENAME = "spanish.txt";
    const string GAME_FILENAME = "game.txt";

    const string BACKGROUND_FILENAME = "Background.png";
    const string BUTTON_BACKGROUND_FILENAME = "button_background.png";

    const string PLAYER_FILENAME = "player.png";
    const string FRUIT_FILENAME = "Apple.png";

    const string SAMPLE_FILENAME = "0024.wav";


    const int FONT_SIZE = 12;
private:
    static Game* mGame;

    System* mpSystem;

    UnitManager* mUnitManager;
    GraphicsBufferManager* mGraphicsBufferManager;
    FruitManager* mFruitManager;
    ButtonManager* mButtonManager;

    InputTranslator* mpInputTranslator;

    Font* mpSmallFont;
    Font* mpBigFont;

    Player* mpPlayer;

    double mTimePerFrame;
    bool mIsRunning;
    int mCurScene;
    int mTimeBetweenFruit;
    int mCurTime;
    int mLevel = 1;
    int mFruitSpeed;

    string mLevelUp[3];

public:
    Game();
    Game(const Game &other) = delete;
    ~Game();
    void Init(int width, int height, double fps);
    void makeButtons();
    void Cleanup();
    void StartLoop();
    void optionsLoop();
    void gameLoop();
    void endLoop();
    void levelUpLoop();
    void Update(double fps);
    void RenderStart();
    void renderOptions();
    void renderGame();
    void renderEnd();
    void renderLevelUp();
    void handleEvent(const Event& theEvent);
    void loadGameFromFile();
    void saveDataToFile();
    void fruitSpawning();


    UnitManager* getUnitManager() { return mUnitManager; };
    GraphicsBufferManager* getGraphicsBufferManager() { return mGraphicsBufferManager; };

    static Game* getInstance();
};

