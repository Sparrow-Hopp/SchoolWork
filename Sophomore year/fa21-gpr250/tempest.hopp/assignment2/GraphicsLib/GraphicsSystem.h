#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

#include <iostream>
#include <cassert>
#include <string>

#include <PerformanceTracker.h>
#include <MemoryTracker.h>
#include "GraphicsBuffer.h"
#include "Sprite.h"
#include "Font.h"

using namespace std;

class GraphicsSystem : public Trackable
{
	private:
		ALLEGRO_DISPLAY* mpDisplay;
		GraphicsBuffer* mpBuffer;
	public:
		GraphicsSystem(int w, int h);
		~GraphicsSystem();
		void Init(int w, int h);
		void Cleanup();
		GraphicsBuffer* getBuffer();
		int getWidth();
		int getHeight();
		void Flip();
		void Draw(int locX, int locY, GraphicsBuffer* image, double scale);
		void Draw(GraphicsBuffer* targetbuffer, int locX, int locY, GraphicsBuffer* image, double scale);
		void Draw(int locX, int locY, Sprite image, double scale);
		void saveBuffer(GraphicsBuffer* savedBuffer, string fileName);
		void writeText(int locX, int locY, Font* font, Color color, string text);
		void writeText(GraphicsBuffer* targetBuffer, int locX, int locY, Font* font, Color color, string text);
};

