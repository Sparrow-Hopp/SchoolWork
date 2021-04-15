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

//main menu

/*
* Pre: none
* Post:
* Purpose: Display a menu with all update-able options
*/
void updateMenu()
{
	string selection, junk;
	int iSelection;
	cout << "1.\tSSN\n2.\tName\n3.\tAddress\n4.\tPhone number\n\nPlease make a selection: " << endl;
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
		{
			updateSSN();
			break;
		}
		case 2:
		{
			updateName();
			break;
		}
		case 3:
		{
			updateAddress();
			break;
		}
		case 4:
		{
			updatePhoneNumber();
			break;
		}
	}
}

//core update functions

/*
* Pre: none
* Post: none
* Purpose: update the address of the given account
*/
void updateAddress()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNumber = inputHub(), address;
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(2);
		string accountNumber = inputHub();
	}
	cout << "Please input your new address: " << endl;
	getline(cin, address);
	checkTerminationCode(address);
	checkLogOutCode(address);
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setAddress(address);//update the address if the account numbers match
	}
	customers.storeData();//overwrite the data in accounts.dat
}

/*
* Pre: none
* Post: none
* Purpose: update the name of the given account
*/
void updateName()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNumber = inputHub(), name;
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(2);
		string accountNumber = inputHub();
	}
	cout << "Please input your new name: " << endl;
	getline(cin, name);
	checkTerminationCode(name);
	checkLogOutCode(name);
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setName(name);//update the name if the account numbers match
	}
	customers.storeData();//overwrite the data in accounts.dat
}

/*
* Pre: none
* Post: none
* Purpose: update the phone number of the given account
*/
void updatePhoneNumber()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNumber = inputHub(), phoneNumber;
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(2);
		string accountNumber = inputHub();
	}
	cout << "Please input your new phone number: " << endl;
	getline(cin, phoneNumber);
	checkTerminationCode(phoneNumber);
	checkLogOutCode(phoneNumber);
	while (!validPhoneNumber(phoneNumber))//make sure the new phone number is valid
	{
		displayMessage(5);
		cout << "Please input your new phone number: " << endl;
		getline(cin, phoneNumber);
		checkTerminationCode(phoneNumber);
		checkLogOutCode(phoneNumber);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setPhoneNumber(phoneNumber);//update the phoneNumber if the account numbers match
	}
	customers.storeData();//overwrite the data in accounts.dat
}

/*
* Pre: none
* Post: none
* Purpose: update the ssn of the given account
*/
void updateSSN()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNumber = inputHub(), ssn;
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(2);
		string accountNumber = inputHub();
	}
	cout << "Please input your new ssn: " << endl;
	getline(cin, ssn);
	checkTerminationCode(ssn);
	checkLogOutCode(ssn);
	while (!validSSN(ssn))//make sure the new phone number is valid
	{
		displayMessage(5);
		cout << "Please input your new ssn: " << endl;
		getline(cin, ssn);
		checkTerminationCode(ssn);
		checkLogOutCode(ssn);
	}
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setSSN(ssn);//update the phoneNumber if the account numbers match
	}
	customers.storeData();//overwrite the data in accounts.dat
}

