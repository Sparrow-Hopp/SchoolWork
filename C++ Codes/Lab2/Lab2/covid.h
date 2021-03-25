#pragma once
#ifndef COVID_H
#define COVID_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm> 

using namespace std;

struct Covid
{
	string mCode, mCont, mName, mDate;
	int mPop, mTotD, mTotC;
	double mPerC, mPerD;
};

#endif
