/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  functions.cpp
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

#include "masterHead.h"

//logins and logout

/*
* Pre: the address of two strings
* Post: none
* Purpose: Get the ID and password from the teller
*/
void getIdPassword(string& id, string& password)
{
	cout << "Enter your id: " << endl;
	cin >> id;

	cout << "Enter your password" << endl;
	cin >> password;
}

/*
* Pre: none
* Post: none
* Purpose: Get the ID and password from the teller
			If the  ID and  password pair is incorrect, then repeat prompting for the ID and  password until a correct pair is entered
*/
void login()
{
	string id, password;
	bool validCashier, validManager;
	do
	{
		getIdPassword(id, password);
		validCashier = validateCashierLogin(id, password);
		validManager = validateManagerLogin(id, password);
		if (validCashier)
		{
			cashierHub();
		}
		else if (validManager)
		{
			managerHub();
		}
	} while (!validCashier && !validManager);
}

/*
* Pre: two strings
* Post: a boolean
* Purpose: Validate the ID and password pair is correct according to the data in "cashier_login.txt"
			The function returns true if the pair is correct; otherwise false
*/
bool validateCashierLogin(string id, string password)
{
	string curID, curPW;
	ifstream fin;
	fin.open(CASHIER_LOGINS);
	if (fin.fail());
	else
	{
		while (!fin.eof())
		{
			fin >> curID >> curPW;
			if (curID == id && curPW == password)
			{ 
				return true;
			}
		}
	}
	return false;
}

/*
* Pre: two strings
* Post: a boolean
* Purpose: Validate the ID and password pair is correct according to the data in "manager_login.txt"
			The function returns true if the pair is correct; otherwise false
*/
bool validateManagerLogin(string id, string password)
{
	string curID, curPW;
	ifstream fin;
	fin.open(MANAGER_LOGINS);
	if (fin.fail());
	else
	{
		while (!fin.eof())
		{
			fin >> curID >> curPW;
			if (curID == id && curPW == password)
				return true;
		}
	}
	return false;
}

//hubs

void cashierHub()
{
	int selection;
	cout << "1.\tAdd an item to the cart\n2.\tRemove an item from the cart\n3.\tSearch for an item\n4.\tComplete Transaction\n5.\tVoid Transaction";
	cout << "\n6.\tLog out" << endl;
	cout << "Please make a selection: " << endl;
	cin >> selection;
	while (selection < 1 || selection > 6)
	{
		//cout << "Invalid selection. Please make a new selection" << endl;
		cin >> selection;
	}
	switch (selection)
	{
		case 1:
		{
			manager.addItem();
			cashierHub();
		}
		case 2:
		{
			manager.removeItem();
			cashierHub();
		}
		case 3:
		{
			manager.searchItem();
			cashierHub();
		}
		case 4:
		{
			manager.completeTransaction();
			cashierHub();
		}
		case 5:
		{
			manager.voidTransaction();
			cashierHub();
		}
		case 6:
		{
			login();
		}
	}
}

void managerHub()
{
	int selection;
	cout << "1.\tHire a new cashier\n2.\tFire a cashier\n3.\tUpdate information on an existing cashier\n4.\tSearch for cashier information\n5.\tGenerate end of day report";
	cout << "\n6.\tLog out\n7.\tShut down" << endl;
	cout << "Please make a selection: " << endl;
	cin >> selection;
	while (selection < 1 || selection > 7)
	{
		cout << "Invalid selection. Please make a new selection" << endl;
		cin >> selection;
	}
	switch (selection)
	{
		case 1:
		{
			manager.hireCashier();
			managerHub();
		}
		case 2:
		{
			manager.fireCashier();
			managerHub();
		}
		case 3:
		{
			manager.updateCashierInfo();
			managerHub();
		}
		case 4:
		{
			manager.searchCashierInfo();
			managerHub();
		}
		case 5:
		{
			manager.generateReport();
			managerHub();
		}
		case 6:
		{
			login();
		}
		case 7:
		{
			manager.shutDown();
		}
	}
}