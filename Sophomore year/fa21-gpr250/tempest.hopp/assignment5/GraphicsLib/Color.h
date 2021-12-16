#pragma once

#include <allegro5/allegro.h>

#include <Trackable.h>

class GraphicsSystem;

class Color :public Trackable
{
public:
	Color() {};
	Color(int r, int g, int b, int a = 255);
	Color(float r, float g, float b, float a = 1.0f);

	int getR() const { return mR; };
	int getG() const { return mG; };
	int getB() const { return mB; };
	int getA() const { return mA; };

private:
	int mR = 255;
	int mG = 255;
	int mB = 255;
	int mA = 255;
};
