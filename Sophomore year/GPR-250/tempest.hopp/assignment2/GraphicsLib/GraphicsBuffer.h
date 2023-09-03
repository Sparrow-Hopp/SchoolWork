#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>

#include "Color.h"

using namespace std;

class GraphicsBuffer : public Trackable
{
	friend class GraphicsSystem;
	private:
		ALLEGRO_BITMAP* mpBitmap;
		GraphicsBuffer(ALLEGRO_DISPLAY* display)
		{
			mpBitmap = al_get_backbuffer(display);
		}
		bool mOwnsMap = false;
	public:
		GraphicsBuffer();
		GraphicsBuffer(ALLEGRO_BITMAP* bitmap);
		GraphicsBuffer(Color color, int w, int h);
		GraphicsBuffer(string fileName);
		~GraphicsBuffer();
		int getHeight();
		int getWidth();
		void setBufferToColor(Color theColor);
};

