#pragma once

#include <iostream>
#include <cassert>
#include <string>

using namespace std;
class Color : public Trackable
{
private:
	int mRed, mGreen, mBlue, mAlpha;
public:
	Color(int r, int g, int b, int a);
	~Color();
	int getRed();
	int getGreen();
	int getBlue();
	int getAlpha();

};

