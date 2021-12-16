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

using namespace std;
class Font
{
	friend class GraphicsSystem;
	private:
		ALLEGRO_FONT* mFont;
		int mFontSize;
	public:
		Font(string fileName, int size);
		~Font();
		int getSize();
};

