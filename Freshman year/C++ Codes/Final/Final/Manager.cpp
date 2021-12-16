/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Manager.cpp
   *
   * Description:
   *    Code all functionality of the Champlain bookstore
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


#include "Manager.h"


//constructor

/*
* Pre: none
* Post: none
* Purpose: define the manager with the default variables
*/
Manager::Manager()
{
	reloadCashiers();
}

//class specific functions

/*
* Pre: string
* Post: bool
* Purpose: check to see if a cashier exists
*/
bool Manager::isCashierExists(string name)
{
	reloadCashiers();
	for (int i = 0; i < mSize; i++)
	{
		if (mCashiers[i] == name)
			return true;
	}
	return false;
}

/*
* Pre: none
* Post: none
* Purpose: redefine the manager with the variables defined in the cashier files
*/
void Manager::reloadCashiers()
{
	mCashiers = new Cashier[MAX_SIZE];
	int count = 0;
	ifstream fin;

	fin.open(FILE_CASHIERS);
	if (fin.fail());
	else
	{
		while (!fin.eof() && count < MAX_SIZE)
		{
			fin >> mCashiers[count++];
		}
	}
	fin.close();
	mSize = count;
}

//manager operations

/*
* Pre: none
* Post: none
* Purpose: add a cashier to the array
*/
void Manager::hireCashier()
{
	reloadCashiers();
	string name, email, phone;
	cout << "Enter cashier name" << endl;
	getline(cin, name);
	getline(cin, name);
	if (isCashierExists(name))
	{
		cout << "Cashier already exists" << endl;
	}
	else
	{
		cout << "Enter cashier email" << endl;
		cin >> email;
		cout << "Enter cashier phone number" << endl;
		cin >> phone;
		ofstream fout;
		fout.open(FILE_CASHIERS, ios::app);
		if (fout.fail());
		else
		{
			Cashier temp(name, email, phone);
			fout << temp;
			reloadCashiers();
		}
		fout.close();
	}
}

/*
* Pre: none
* Post: none
* Purpose: remove a cashier from the array
*/
void Manager::fireCashier()
{
	reloadCashiers();
	string name;
	cout << "Enter the name of the cashier you want to fire" << endl;
	getline(cin, name);
	getline(cin, name);
	if (!isCashierExists(name))
	{
		cout << "That cashier does not exist" << endl;
	}
	else
	{
		ofstream fout;
		fout.open(FILE_CASHIERS);
		if (fout.fail());
		else
		{
			for (int i = 0; i < mSize; i++)
			{
				if (mCashiers[i] == name);
				else
					fout << mCashiers[i];
			}
		}
		fout.close();
		reloadCashiers();
	}
}

/*
* Pre: none
* Post: none
* Purpose: write the end of day report to the file
*/
void Manager::generateReport()
{
	ofstream fout;
	fout.open(DAILY_REPORTS, ios::app);
	if (fout.fail());
	else
	{
		fout << mDay << endl;
	}

}

/*
* Pre: none
* Post: none
* Purpose: search for and print out the given cashier
*/
void Manager::searchCashierInfo()
{
	reloadCashiers();
	string name, email, phone;
	cout << "Enter the name of the cashier you want to search for" << endl;
	getline(cin, name);
	getline(cin, name);
	if (!isCashierExists(name))
	{
		cout << "That cashier does not exist" << endl;
	}
	else
	{
		for (int i = 0; i < mSize; i++)
		{
			if (mCashiers[i] == name)
			{
				cout << mCashiers[i].getName() << endl << mCashiers[i].getEmail() << endl << mCashiers[i].getPhone() << endl << endl;
			}
		}
	}
}

/*
* Pre: none
* Post: none
* Purpose: shut down the system
*/
void Manager::shutDown()
{
	exit(1);
}

/*
* Pre: none
* Post: none
* Purpose: update the given cashier with a new email and phone number
*/
void Manager::updateCashierInfo()
{
	reloadCashiers();
	string name, email, phone;
	cout << "Enter the name of the cashier you want to update the information for" << endl;
	getline(cin, name);
	getline(cin, name);
	if (!isCashierExists(name))
	{
		cout << "That cashier does not exist" << endl;
	}
	else
	{
		cout << "Enter the new email of the cashier" << endl;
		cin >> email;
		cout << "Enter the new phone number of the cashier" << endl;
		cin >> phone;
		ofstream fout;
		fout.open(FILE_CASHIERS);
		if (fout.fail());
		else
		{
			for (int i = 0; i < mSize; i++)
			{
				if (mCashiers[i] == name)
				{
					mCashiers[i].setEmail(email);
					mCashiers[i].setPhone(phone);
				}
				fout << mCashiers[i];
			}
		}
		reloadCashiers();
	}
}
