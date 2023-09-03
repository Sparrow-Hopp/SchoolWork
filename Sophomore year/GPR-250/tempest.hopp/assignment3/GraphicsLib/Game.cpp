#include "Game.h"

Game::Game()
{
	mpSystem = new System();
	mIsRunning = false;
	mTimePerFrame = 0;
}

Game::~Game()
{
	Cleanup();
}

void Game::Init(int width, int height, int fps)
{
	mpSystem->init(width, height);
	mpDeanBuffer = new GraphicsBuffer(ASSET_PATH + DEAN_FILENAME);
	mpSmurfBuffer = new GraphicsBuffer(ASSET_PATH + SMURF_FILENAME);
	mpWoodsBuffer = new GraphicsBuffer(ASSET_PATH + WOODS_FILENAME);
	mTimePerFrame = fps;
	mIsRunning = true;
	defineUnit();
}

void Game::defineUnit()
{
	const unsigned int PIXEL_WIDTH = 60;
	const unsigned int PIXEL_HEIGHT = 60;
	const unsigned int SPRITES_ACROSS = 4;
	const unsigned int SPRITES_DOWN = 4;
	Sprite smurfSprites[SPRITES_ACROSS * SPRITES_DOWN];
	Sprite deanSprites[SPRITES_ACROSS * SPRITES_DOWN];
	unsigned int spriteNum = 0;

	for (unsigned int x = 0; x < SPRITES_ACROSS; x++)
	{
		for (unsigned int y = 0; y < SPRITES_DOWN; y++)
		{
			Sprite sprite(mpSmurfBuffer, Vector2D((int)(x * PIXEL_WIDTH), (int)(y * PIXEL_HEIGHT)), PIXEL_WIDTH, PIXEL_HEIGHT);
			smurfSprites[spriteNum] = sprite;
			spriteNum++;
		}
	}
	spriteNum = 0;

	for (unsigned int x = 0; x < SPRITES_ACROSS; x++)
	{
		for (unsigned int y = 0; y < SPRITES_DOWN; y++)
		{
			Sprite sprite(mpDeanBuffer, Vector2D((int)(x * PIXEL_WIDTH), (int)(y * PIXEL_HEIGHT)), PIXEL_WIDTH, PIXEL_HEIGHT);
			deanSprites[spriteNum] = sprite;
			spriteNum++;
		}
	}

	Vector2D unitLocation(390, 290);
	mpUnit = new Unit(deanSprites, smurfSprites, unitLocation);
}

void Game::Cleanup()
{
	delete mpSystem;
	delete mpUnit;
	delete mpDeanBuffer;
	delete mpSmurfBuffer;
	delete mpWoodsBuffer;
}

void Game::DoLoop()
{
	Timer timer;
	while (mIsRunning)
	{
		timer.start();
		getInput();
		Update(mTimePerFrame);
		Render();
		timer.sleepUntilElapsed(mTimePerFrame);
	}
}

void Game::getInput()
{
	if (mpSystem->isKeyPressed(Input::F))
		mpUnit->changeSpeed(-50);
	if (mpSystem->isKeyPressed(Input::S))
		mpUnit->changeSpeed(50);
	if (mpSystem->isKeyPressed(Input::ESCAPE))
		mIsRunning = false;
	if (mpSystem->isKeyPressed(Input::ENTER))
		mpUnit->setAnimation();
	if (mpSystem->isMouseButtonPressed(Input::LEFT))
		mpUnit->setLocation(mpSystem->getMousePos());
}

void Game::Update(int fps)
{
	mpUnit->Update(fps);
}

void Game::Render()
{
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;//leave this alone
	const string DRAW_TRACKER_NAME = "draw";

	pPerformanceTracker->startTracking(DRAW_TRACKER_NAME);//leave this alone

	mpSystem->getGraphicsSystem()->draw(Vector2D(0, 0), *mpWoodsBuffer, 0.5);
	mpUnit->Draw();
	mpSystem->getGraphicsSystem()->flip();

	pPerformanceTracker->stopTracking(DRAW_TRACKER_NAME);//leave this alone
	cout << endl << "Time to Draw:" << pPerformanceTracker->getElapsedTime(DRAW_TRACKER_NAME) << " ms" << endl;

	delete pPerformanceTracker;
}
