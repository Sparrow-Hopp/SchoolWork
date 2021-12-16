#include "GraphicsBuffer.h"
#include "GraphicsLib\GraphicsBuffer.h"

GraphicsBuffer::GraphicsBuffer()
{
	mpBitmap = NULL;
	mHeight = 0;
	mWidth = 0;
}

GraphicsBuffer::GraphicsBuffer(ALLEGRO_BITMAP* bitmap, int h, int w)
{
	mpBitmap = bitmap;
	mHeight = h;
	mWidth = w;
}

GraphicsBuffer::GraphicsBuffer(string fileName, int h, int w)
{
	mpBitmap = al_load_bitmap(fileName.c_str());
	mHeight = h;
	mWidth = w;
}

GraphicsBuffer::~GraphicsBuffer()
{
	al_destroy_bitmap(mpBitmap);
}

int GraphicsBuffer::getHeight()
{
	return mHeight;
}

int GraphicsBuffer::getWidth()
{
	return mWidth;
}
