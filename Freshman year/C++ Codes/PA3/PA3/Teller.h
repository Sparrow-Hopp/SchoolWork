/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  teller.h
   *
   * Description:
   *    Code all functionality of a bank teller
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

#ifndef TELLER_H
#define TELLER_H

#pragma once

#include "employee.h"

class Teller
{
	private:
		//declare variables
		int mCount;
		Employee* mTellers;

	public:
		//constructor and destructor
		Teller();
		~Teller();

		//accessors
		int getCount();
		Employee* getTeller();

		//other methods
		bool loadData(string fileName);
		void storeData(string fileName);
		bool verifyTeller(const string& id, const string& password);
};

#endif