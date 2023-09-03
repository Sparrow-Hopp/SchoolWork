#include "Sprite.h"

Sprite::Sprite()
{
	mpBuffer = NULL;
	mHeight = 0;
	mWidth = 0;
	mSourceX = 0;
	mSourceY = 0;
}

Sprite::Sprite(string fileName, int locX, int locY, int height, int width)
{
	mpBuffer = new GraphicsBuffer(fileName);
	mHeight = height;
	mWidth = width;
	mSourceX = locX;
	mSourceY = locY;
}

Sprite::Sprite(GraphicsBuffer* pBuffer, int locX, int locY, int height, int width)
{
	mpBuffer = pBuffer;
	mSourceX = locX;
	mSourceY = locY;
	mHeight = height;
	mWidth = width;
}

Sprite::~Sprite()
{
}

GraphicsBuffer* Sprite::getBuffer()
{
	return mpBuffer;
}

int Sprite::getSouceX()
{
	return mSourceX;
}

int Sprite::getSourceY()
{
	return mSourceY;
}

int Sprite::getHeight()
{
	return mHeight;
}

int Sprite::getWidth()
{
	return mWidth;
}
