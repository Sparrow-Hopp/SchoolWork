#pragma once
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

class GraphicsBuffer
{
	private:
		ALLEGRO_BITMAP* mpBitmap;
		int mHeight, mWidth;
	public:
		GraphicsBuffer();
		GraphicsBuffer(ALLEGRO_BITMAP* bitmap, int h, int w);
		~GraphicsBuffer();
		int getHeight();
		int getWidth();
};

