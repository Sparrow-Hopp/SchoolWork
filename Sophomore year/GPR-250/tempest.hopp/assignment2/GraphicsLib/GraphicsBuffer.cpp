#include "GraphicsBuffer.h"

GraphicsBuffer::GraphicsBuffer()
{
	mpBitmap = NULL;
}

GraphicsBuffer::GraphicsBuffer(ALLEGRO_BITMAP* bitmap)
{
	mpBitmap = bitmap;
	assert(mpBitmap);
}

GraphicsBuffer::GraphicsBuffer(Color color, int w, int h)
{
	mOwnsMap = true;
	mpBitmap = al_create_bitmap(w, h);
	setBufferToColor(color);
	assert(mpBitmap);
}

GraphicsBuffer::GraphicsBuffer(string fileName)
{
	mpBitmap = al_load_bitmap(fileName.c_str());
	assert(mpBitmap);
}

GraphicsBuffer::~GraphicsBuffer()
{
	al_destroy_bitmap(mpBitmap);
	mpBitmap = NULL;
}

int GraphicsBuffer::getHeight()
{
	return al_get_bitmap_height(mpBitmap);
}

int GraphicsBuffer::getWidth()
{
	return al_get_bitmap_width(mpBitmap);
}

void GraphicsBuffer::setBufferToColor(Color theColor)
{
	ALLEGRO_BITMAP* oldMap = al_get_target_bitmap();
	al_set_target_bitmap(mpBitmap);
	al_clear_to_color(al_map_rgba(theColor.getRed(), theColor.getGreen(), theColor.getBlue(), theColor.getAlpha()));
	al_set_target_bitmap(oldMap);
}
