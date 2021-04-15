/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  Customer.cpp
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

#include "Customer.h"

/*
* Pre: none
* Post: none
* Purpose: define the variables within Customer to their defaults
*/
Customer::Customer()
{
	mCount = 0;
	mAccounts = NULL;
	mFilename = "";
}

/*
* Pre: none
* Post: none
* Purpose: return the variables within Customer to their defaults
*/
Customer::~Customer()
{
	if (mAccounts != NULL)
		delete[] mAccounts;

	mCount = 0;
	mAccounts = NULL;
}

//accessors

/*
* Pre: none
* Post: the contents of mAccounts
* Purpose: show the contents of mAccounts
*/
Account* Customer::getAccounts()
{
	return mAccounts;
}

/*
* Pre: none
* Post: the contents of accountNum
* Purpose: show the contents of count
*/
int Customer::getCount()
{
	return mCount;
}

/*
* Pre: none
* Post: the contents of accountNum
* Purpose: show the contents of accounts
*/
Account Customer::getCustomer(string accountNumber)
{
	Account found;
	for (int i = 0; i < mCount; i++)
	{
		if (mAccounts[i] == accountNumber)
		{
			found = mAccounts[i];
			break;
		}
	}
	return found;
}

/*
* Pre: none
* Post: the contents of accountNum
* Purpose: show the contents of fileName
*/
string Customer::getFilename()
{
	return mFilename;
}

//mutators

/*
* Pre: new contents of fileName
* Post: none
* Purpose: reassign the contents of fileName
*/
void Customer::setFilename(string filename)
{
	mFilename = filename;
}

//other methods

/*
* Pre: a filename
* Post: a boolean indicating if the file opened properly
* Purpose: Set the values inside teller to the values specified in fileName
*/
bool Customer::loadData()
{
	ifstream fin;
	bool loaded = false;
	fin.open(mFilename);

	if (!fin.fail())
	{
		string count;
		int i;
		getline(fin, count);
		mCount = stoi(count);

		mAccounts = new Account[mCount];

		for (i = 0; i < mCount; i++)
		{
			fin >> mAccounts[i];
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
void Customer::storeData()
{
	int i;
	ofstream fout;
	fout.open(mFilename);
	if (fout.fail())//check to see if the file opens
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		fout << mCount << endl;
		for (i = 0; i < mCount; i++)
		{
			fout << mAccounts[i];//use the overloaded operator in Account to store all the values inside mAccounts
		}
	}
	fout.close();
}

