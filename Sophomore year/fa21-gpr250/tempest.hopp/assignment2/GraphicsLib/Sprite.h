#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_acodec.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include "GraphicsBuffer.h"

using namespace std;

class Sprite : public Trackable
{
	private:
		GraphicsBuffer* mpBuffer;
		int mSourceX, mSourceY, mHeight, mWidth;
	public:
		Sprite();
		Sprite(string fileName, int locX, int locY, int height, int width);
		Sprite(GraphicsBuffer* pBuffer, int locX, int locY, int height, int width);
		~Sprite();
		GraphicsBuffer* getBuffer();
		int getSouceX();
		int getSourceY();
		int getHeight();
		int getWidth();
};

