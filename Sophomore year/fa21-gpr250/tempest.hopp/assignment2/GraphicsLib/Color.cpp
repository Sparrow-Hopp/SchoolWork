#include "Color.h"

Color::Color(int r, int g, int b, int a)
{
	mRed = r;
	mGreen = g;
	mBlue = b;
	mAlpha = a;
}

Color::~Color()
{
}

int Color::getRed()
{
	return mRed;
}

int Color::getGreen()
{
	return mGreen;
}

int Color::getBlue()
{
	return mBlue;
}

int Color::getAlpha()
{
	return mAlpha;
}
