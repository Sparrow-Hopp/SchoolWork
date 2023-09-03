#include "Font.h"

Font::Font(string fileName, int size)
{
	mFont = al_load_font(fileName.c_str(), size, 0);
	mFontSize = size;
	assert(mFont);
}

Font::~Font()
{
	al_destroy_font(mFont);
	mFont = NULL;
}

int Font::getSize()
{
	return mFontSize;
}
