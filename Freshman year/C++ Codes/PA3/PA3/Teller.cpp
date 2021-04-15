/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  teller.cpp
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

#include "Teller.h"

//constructor and destructor

/*
* Pre: none
* Post: none
* Purpose: Set the values inside teller to the default
*/
Teller::Teller()
{
	mCount = 0;
	mTellers = NULL;
}

/*
* Pre: none
* Post: none
* Purpose: Reset the values inside teller to the default
*/
Teller::~Teller()
{
	if (mTellers != NULL)
		delete[] mTellers;

	mCount = 0;
	mTellers = NULL;
}

//accessors

/*
* Pre: none
* Post: an int
* Purpose: get the value of mCount
*/
int Teller::getCount()
{
	return mCount;
}

/*
* Pre: none
* Post: a pointer of type Employee
* Purpose: get the value of mTellers
*/
Employee* Teller::getTeller()
{
	return mTellers;
}

//other methods

/*
* Pre: a filename
* Post: a boolean indicating if the file opened properly
* Purpose: Set the values inside teller to the values specified in fileName
*/
bool Teller::loadData(string fileName)
{
	ifstream fin;
	bool loaded = false;
	fin.open(fileName);

	if (!fin.fail())
	{
		int i = 0;
		fin >> mCount;

		mTellers = new Employee[mCount];

		for (i = 0; i < mCount; i++)
		{
			fin >> mTellers[i];
		}
		loaded = true;
		fin.close();
	}

	return loaded;
}

/*
* Pre: a filename
* Post: none
* Purpose: Store the values inside teller to fileName
*/
void Teller::storeData(string fileName)
{
	int i = 0;
	ofstream fout;
	fout.open(fileName);
	if (fout.fail())//check to see if the file opens
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		fout << mCount << endl;
		while (i < mCount)
		{
			fout << mTellers[i++];//use the overloaded operator in employee to store all the values inside teller
		}
		fout.close();
	}
}

/*
* Pre: an ID and a password
* Post: a boolean indicating if the ID and password combo exists
* Purpose: check to see if the provided ID and password is valid
*/
bool Teller::verifyTeller(const string& id, const string& password)
{
	int i = 0;
	while (i < mCount)
	{
		if (mTellers[i].mID == id && mTellers[i].mPW == password)//check to see if they match an existing ID and password combo
			return true;
		i++;
	}
	return false;
}
