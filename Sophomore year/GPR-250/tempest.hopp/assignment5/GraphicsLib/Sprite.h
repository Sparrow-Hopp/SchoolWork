#pragma once

#include <Trackable.h>
#include <Vector2D.h>

class GraphicsBuffer;

class Sprite : public Trackable
{
public:
	Sprite(GraphicsBuffer* pBuffer, const Vector2D& srcLoc, int width, int height);
	Sprite() {};

	GraphicsBuffer* getBuffer() const { return mpBuffer; };
	const Vector2D& getSourceLoc() const { return mSrcLoc; };
	int getWidth() const { return mWidth; };
	int getHeight() const { return mHeight; };
private:
	GraphicsBuffer* mpBuffer = NULL;
	Vector2D mSrcLoc = ZERO_VECTOR2D;
	int mWidth = 0;
	int mHeight = 0;
};