/*
References:
http://wiki.allegro.cc/index.php?title=Windows,_Visual_Studio_2010_and_Allegro_5
http://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Addons/Audio
http://wiki.allegro.cc/index.php?title=Allegro_5_Tutorial/Bitmaps
*/

/*  
	please note that the installation of Allegro we are using doesn't include the monolith libs described in the references.
	You must refer to the allegro.lib and each lib for each add-on separately!!
*/

/*
 Make sure your launch config is set to Debug x86! x64 will not work.
*/

#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

using namespace std;

int main()
{
	PerformanceTracker* pPerformanceTracker = new PerformanceTracker;//leave this alone

	const string INIT_TRACKER_NAME = "init";
	const string DRAW_TRACKER_NAME = "draw";
	const string WAIT_TRACKER_NAME = "wait";

	pPerformanceTracker->startTracking(INIT_TRACKER_NAME);//leave this alone

	if (!al_init())
	{
		cout << "error initting Allegro\n";
		system("pause");
		return 1;
	}

	//Example of how to init an addon
	if (!al_init_image_addon()) {
		cout << "error initting Allegro image addon";
		system("pause");
		return 1;
	}

	//TODO: init the various add-ons - you will need image (already provided), font, ttf, primitives, audio, and acodec

	if (!al_init_font_addon()) {
		cout << "error initting Allegro font addon";
		system("pause");
		return 1;
	}

	if (!al_init_primitives_addon())
	{
		cout << "error initting Allegro primitives addon";
		system("pause");
		return 1;
	}

	if (!al_install_audio())
	{
		cout << "error - audio add-on not initialised";
		system("pause");
		return 1;
	}

	if (!al_init_ttf_addon())
	{
		cout << "error initting ttf addon";
		system("pause");
		return 1;
	}

	if (!al_init_acodec_addon())
	{
		cout << "error initting Allegro audio codec addon";
		system("pause");
		return 1;
	}

	if (!al_reserve_samples(1))
	{
		cout << "error - samples not reserved";
		system("pause");
		return 1;
	}

	//various constants that you should use for asset loading and locating things to be drawn
	const int DISP_WIDTH = 800;
	const int DISP_HEIGHT = 600;

	const string ASSET_PATH = "..\\..\\shared\\assets\\";//may need to change this
	const string BACKGROUND_FILENAME = "axamer-lizum.png";
	const string QUIMBY_FILENAME = "mayor_quimby.png";
	const string FONT_FILENAME = "cour.ttf";
	const int FONT_SIZE = 24;
	const string SAMPLE_FILENAME = "clapping.wav";
	const double SLEEP_TIME_IN_SECONDS = 5.0;

	//create the display
	ALLEGRO_DISPLAY* display = al_create_display(DISP_WIDTH, DISP_HEIGHT);
	assert(display);

	//example of how to construct the path and pass it to allegro
	ALLEGRO_BITMAP* bitmap = al_load_bitmap((ASSET_PATH + BACKGROUND_FILENAME).c_str());
	assert(bitmap);

	//some colors
	const ALLEGRO_COLOR WHITE = al_map_rgb(255, 255, 255);
	const ALLEGRO_COLOR BLACK = al_map_rgb(0, 0, 0);
	const ALLEGRO_COLOR BLACK_TRANSPARENT = al_map_rgba(0, 0, 0, 200);
	const ALLEGRO_COLOR PURPLE = al_map_rgb(128, 64, 212);

	//TODO: Load all assets (bitmaps,fonts,sample)

	//loading background texture
	ALLEGRO_SAMPLE* sample = al_load_sample((ASSET_PATH + SAMPLE_FILENAME).c_str());
	assert(sample);

	//loading font asset
	ALLEGRO_FONT* cour_font = al_load_ttf_font((ASSET_PATH + FONT_FILENAME).c_str(), FONT_SIZE, 0);
	assert(cour_font);

	//TODO: Play audio sample (looping)
	al_play_sample(sample, 1.0f, 0, 1, ALLEGRO_PLAYMODE_LOOP, nullptr);

	pPerformanceTracker->stopTracking(INIT_TRACKER_NAME);//leave this alone
	pPerformanceTracker->startTracking(DRAW_TRACKER_NAME);//leave this alone

	const int CIRCLE_RADIUS = 150;
	const string MESSAGE_TEXT = "Welcome to Allegro!";

	//used for circle one - circle black and text white
	const int LOC1_X = 400;
	const int LOC1_Y = 300;

	//used for circle two - circle transparent black and text purple
	const int LOC2_X = 200;
	const int LOC2_Y = 500;

	//used for quimby
	const int LOC3_X = 500;
	const int LOC3_Y = 400;
	const float SCALE_FACTOR = 0.75f;

	/*
	PSEUDOCODE
		clear screen to WHITE
		draw the axamer-lizum background image
		draw circle 1 with message
		draw circle 2 with message
		draw quimby image scaled appropriately
		flip the display
	*/

	al_clear_to_color(WHITE);
	al_draw_bitmap(bitmap, 0, 0, 0);

	al_draw_filled_circle(LOC1_X, LOC1_Y, CIRCLE_RADIUS, BLACK);
	al_draw_text(cour_font, WHITE, LOC1_X, LOC1_Y, ALLEGRO_ALIGN_CENTER, MESSAGE_TEXT.c_str());

	al_draw_filled_circle(LOC2_X, LOC2_Y, CIRCLE_RADIUS, BLACK_TRANSPARENT);
	al_draw_text(cour_font, PURPLE, LOC2_X, LOC2_Y, ALLEGRO_ALIGN_CENTER, MESSAGE_TEXT.c_str());

	al_flip_display();

	pPerformanceTracker->stopTracking(DRAW_TRACKER_NAME);//leave this alone

	pPerformanceTracker->startTracking(WAIT_TRACKER_NAME);//leave this alone

	Timer* pTimer = new Timer;
	pTimer->start();
	pTimer->sleepUntilElapsed(SLEEP_TIME_IN_SECONDS*1000.0);

	pPerformanceTracker->stopTracking(WAIT_TRACKER_NAME);//leave this alone

	//TODO: Destroy loaded assets

	al_destroy_sample(sample);
	al_destroy_bitmap(bitmap);
	al_destroy_display(display);

	//report elapsed times - leave this alone
	cout << endl << "Time to Init:" << pPerformanceTracker->getElapsedTime(INIT_TRACKER_NAME) << " ms" << endl;
	cout << endl << "Time to Draw:" << pPerformanceTracker->getElapsedTime(DRAW_TRACKER_NAME) << " ms" << endl;
	cout << endl << "Time spent waiting:" << pPerformanceTracker->getElapsedTime(WAIT_TRACKER_NAME) << " ms" << endl;

	MemoryTracker::getInstance()->reportAllocations(cout);//leave this alone - will report memory leaks - don't worry about this for now

	system("pause");
	return 0;
}