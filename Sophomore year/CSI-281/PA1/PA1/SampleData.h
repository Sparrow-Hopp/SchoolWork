/***        Author:  Legolas
   *         Class:  CSI-281-01
   *    Assignment:  PA1
   * Date Assigned:  8/31/21
   *      Due Date:  9/7/21
   *      Filename:  SampleData.h
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
#ifndef SAMPLEDATA_H
#define SAMPLEDATA_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include "Mushroom.h"

using namespace std;

class SampleData
{
	private:
		Mushroom* pMushrooms;
		int mNumMushrooms;
		Direction* mpDirections;
	public:


		//constructor and destructor
		SampleData();
		SampleData(string fileName);
		~SampleData();

		//accessor
		int getNumMushrooms();
		Mushroom* getMushrooms();
		Direction* getDirection();

		//distance methods

		void calcDirection(Mushroom mysteryMushroom, Mushroom sampleMushroom, Direction& dir);
		bool isEdible(Direction closestMushrooms[]);
		void selectionSort(int size);
};

#endif