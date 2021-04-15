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
#include "PA3-Header.h"

ifstream fin;


/*
* Pre: none
* Post: a string
* Purpose: return the given accountNumber, if it exists
*/
string getAccountNumber()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNumber;
	cout << "Please enter the account number you are looking for: " << endl;
	getline(cin, accountNumber);
	checkTerminationCode(accountNumber);
	checkLogOutCode(accountNumber);
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(5);
		cout << "Please enter the account number you are looking for: " << endl;
		getline(cin, accountNumber);
		checkTerminationCode(accountNumber);
		checkLogOutCode(accountNumber);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getAccountNumber() == accountNumber)
			return v.getAccountNumber();
	}
	return "";
}

/*
* Pre: none
* Post: a string
* Purpose: return the given address, if it exists
*/
string getAddress()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string address;
	cout << "Please enter the account number you are looking for: " << endl;
	getline(cin, address);
	checkTerminationCode(address);
	checkLogOutCode(address);
	while (!isExistsAccountNumber(address))
	{
		displayMessage(5);
		cout << "Please enter the account number you are looking for: " << endl;
		getline(cin, address);
		checkTerminationCode(address);
		checkLogOutCode(address);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getAddress() == address)
			return v.getAddress();
	}
	return "";
}

/*
* Pre: none
* Post: a string
* Purpose: return the given name, if it exists
*/
string getName()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string name;
	cout << "Please enter the account number you are looking for: " << endl;
	getline(cin, name);
	checkTerminationCode(name);
	checkLogOutCode(name);
	while (!isExistsAccountNumber(name))
	{
		displayMessage(5);
		cout << "Please enter the account number you are looking for: " << endl;
		getline(cin, name);
		checkTerminationCode(name);
		checkLogOutCode(name);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getName() == name)
			return v.getName();
	}
	return "";
}

/*
* Pre: none
* Post: a string
* Purpose: return the given phoneNumber, if it exists
*/
string getPhoneNumber()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string phoneNumber;
	cout << "Please enter the account number you are looking for: " << endl;
	getline(cin, phoneNumber);
	checkTerminationCode(phoneNumber);
	checkLogOutCode(phoneNumber);
	while (!isExistsAccountNumber(phoneNumber))
	{
		displayMessage(5);
		cout << "Please enter the account number you are looking for: " << endl;
		getline(cin, phoneNumber);
		checkTerminationCode(phoneNumber);
		checkLogOutCode(phoneNumber);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getPhoneNumber() == phoneNumber)
			return v.getPhoneNumber();
	}
	return "";
}

/*
* Pre: none
* Post: a string
* Purpose: return the given SSN, if it exists
*/
string getSSN()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string ssn;
	cout << "Please enter the account number you are looking for: " << endl;
	getline(cin, ssn);
	checkTerminationCode(ssn);//check to see if the special "code words" were entered
	checkLogOutCode(ssn);
	while (!isExistsAccountNumber(ssn))
	{
		displayMessage(5);
		cout << "Please enter the account number you are looking for: " << endl;
		getline(cin, ssn);
		checkTerminationCode(ssn);
		checkLogOutCode(ssn);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getSSN() == ssn)
			return v.getSSN();
	}
	return "";
}

/*
* Pre: a string
* Post: a bool
* Purpose: Determine if a given accountNumber exists in the database (accounts.dat). If the account does exist, returns true; otherwise returns false
*/
bool isExistsAccountNumber(string accountNumber)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	bool exists = false;
	Account* accounts = customers.getAccounts();
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getAccountNumber() == accountNumber)
			exists = true;
	}
	return exists;
}

/*
* Pre: a string
* Post: a bool
* Purpose: Determine if a given address exists in the database (accounts.dat). If the account does exist, returns true; otherwise returns false
*/
bool isExistsAddress(string address)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	bool exists = false;
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getAddress() == address)
			exists = true;
	}
	return exists;
}

/*
* Pre: a string
* Post: a bool
* Purpose: Determine if a given name exists in the database (accounts.dat). If the account does exist, returns true; otherwise returns false
*/
bool isExistsName(string name)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	bool exists = false;
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getName() == name)
			exists = true;
	}
	return exists;
}

/*
* Pre: a string
* Post: a bool
* Purpose: Determine if a given phoneNumber exists in the database (accounts.dat). If the account does exist, returns true; otherwise returns false
*/
bool isExistsPhoneNumber(string phoneNumber)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	bool exists = false;
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getPhoneNumber() == phoneNumber)
			exists = true;
	}
	return exists;
}

/*
* Pre: a string
* Post: a bool
* Purpose: Determine if a given ssn exists in the database (accounts.dat). If the account does exist, returns true; otherwise returns false
*/
bool isExistsSSN(string ssn)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	bool exists = false;
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		Account v = accounts[i];
		if (v.getSSN() == ssn)
			exists = true;
	}
	return exists;
}

/*
* Pre: none
* Post: a string
* Purpose: display a menu of things to search for, and return the value for the found item, if it exists
*/
string searchMenu()
{
	string selection, junk;
	int iSelection;
	cout << "1.\tAccount number\n2.\tSSN\n3.\tName\n4.\tAddress\n5.\tPhone number\n\nPlease make a selection: " << endl;
	cin >> selection;
	getline(cin, junk);
	checkTerminationCode(selection);
	checkLogOutCode(selection);
	if (NUMBERS.find(selection) == -1)
	{
		displayMessage(7);
		searchMenu();
	}
	iSelection = stoi(selection);
	if (!(iSelection > 0 && iSelection < 9))
	{
		displayMessage(7);
		searchMenu();
	}
	switch (iSelection)
	{
		case 1:
			return getAccountNumber();
		case 2:
			return getSSN();
		case 3:
			return getName();
		case 4:
			return getAddress();
		case 5:
			return getPhoneNumber();
	}
	return "";
}