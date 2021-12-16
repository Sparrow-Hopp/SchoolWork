/***        Author:  Legolas
   *         Class:  CSI-281-01
   *    Assignment:  PA1
   * Date Assigned:  8/31/21
   *      Due Date:  9/7/21
   *      Filename:  Mushroom.h
   *
   * Description:
   *    Implement machine learning to determine the edibility of some mushrooms
   *
   * Certification of Authenticity:
   *    I certify that this is entirely my own work, except where I have given
   * fully-documented references to the work of others.I understand the definition
   * and consequences of plagiarism and acknowledge that the assessor of this
   * assignment may, for the purpose of assessing this assignment:
   * - Reproduce this assignment and provide a copy to another member of academic
   *   staff; and/or
   * - Communicate a copy of this assignment to a plagiarism checking service
   *   (which may then retain a copy of this assignment on its database for the
   *   purpose of future plagiarism checking)
   *******************************************************************************/


#pragma once
#ifndef MUSHROOM_H
#define MUSHROOM_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <math.h>

using namespace std;

const int NUM_ATTRIBUTES = 22;
const int MAX_MUSHROOMS = 8124;

struct Mushroom
{
	int mAttributes[NUM_ATTRIBUTES];
	string mEdibility;
	friend ifstream& operator>> (ifstream& input, Mushroom& obj);
};

struct Direction
{
	int mSize;
	double mDirection;
	string mEdibility;
};

#endif