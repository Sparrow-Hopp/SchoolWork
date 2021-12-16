#include <iostream>
#include <cassert>
#include <string>
#include <random>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

#include <GraphicsLib.h>
#include "GraphicsSystem.h"

using namespace std;

int main()
{
	default_random_engine randomEngine;
	randomEngine.seed((unsigned int)time(NULL));
	uniform_int_distribution<> distribution(1, 100000);
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;

	const string INIT_TRACKER_NAME = "init";
	const string DRAW_TRACKER_NAME = "draw";
	const string WAIT_TRACKER_NAME = "wait";


	pPerformanceTracker->startTracking(INIT_TRACKER_NAME);

	const int DISP_WIDTH = 800;
	const int DISP_HEIGHT = 600;

	const string ASSET_PATH = "..\\..\\shared\\assets\\";
	const string BACKGROUND_FILENAME = "axamer-lizum.png";
	const string QUIMBY_FILENAME = "mayor_quimby.png";
	const string FONT_FILENAME = "cour.ttf";
	const string STEPS_FILENAME = "steps.png";
	const string SMURF_FILENAME = "smurf_sprites.png";
	const int FONT_SIZE = 24;
	const string SAMPLE_FILENAME = "clapping.wav";
	const double SLEEP_TIME = 5.0;

	Color red(255, 0, 0, 255);
	Color black(0, 0, 0, 255);

	GraphicsSystem* display = new GraphicsSystem(DISP_WIDTH, DISP_HEIGHT);
	GraphicsBuffer* steps = new GraphicsBuffer(ASSET_PATH + STEPS_FILENAME);
	GraphicsBuffer* redBuffer = new GraphicsBuffer(red, DISP_WIDTH, DISP_HEIGHT);
	GraphicsBuffer* pSmurfBuffer = new GraphicsBuffer(ASSET_PATH + SMURF_FILENAME);

	Font* pFont = new Font(ASSET_PATH + FONT_FILENAME, FONT_SIZE);

	display->writeText(redBuffer, 0, 0, pFont, black, "Curse you Papa Smurf!");

	display->Draw(0, 0, redBuffer, 1);
	display->Draw(150, 100, steps, 0.33);

	//make sprites 
	const int PIXEL_WIDTH = 60;
	const int PIXEL_HEIGHT = 60;
	const int SPRITES_ACROSS = 4;
	const int SPRITES_DOWN = 4;
	Sprite sprites[SPRITES_ACROSS * SPRITES_DOWN];
	int spriteNum = 0;

	for (int i = 0; i < SPRITES_ACROSS; i++)
	{
		for (int k = 0; k < SPRITES_DOWN; k++)
		{
			Sprite sprite(pSmurfBuffer, (int)(i * PIXEL_WIDTH), (int)(k * PIXEL_HEIGHT), PIXEL_WIDTH, PIXEL_HEIGHT);
			sprites[spriteNum] = sprite;
			spriteNum++;
		}
	}

	//draw sprites
	for (int i = 0; i < SPRITES_ACROSS * SPRITES_DOWN; i++)
	{
		int x = distribution(randomEngine) % (DISP_WIDTH - 60);
		int y = distribution(randomEngine) % (DISP_HEIGHT - 60);
		cout << "sprite:" << i + 1 << " at " << x << " " << y << endl;
		display->Draw(x, y, sprites[i], 1);
	}

	display->saveBuffer(display->getBuffer(), "backBuffer.jpg");
	display->saveBuffer(redBuffer, "redBuffer.jpg");

	display->Flip();



	Timer timer;
	timer.start();
	timer.sleepUntilElapsed(3000.0);

	delete steps;
	delete redBuffer;
	delete pSmurfBuffer;
	delete pFont;

	delete display;


	pPerformanceTracker->stopTracking(DRAW_TRACKER_NAME);
	pPerformanceTracker->startTracking(WAIT_TRACKER_NAME);
	pPerformanceTracker->stopTracking(WAIT_TRACKER_NAME);

	delete pPerformanceTracker;

	MemoryTracker::getInstance()->reportAllocations(cout);
	system("pause");

	return 0;

}