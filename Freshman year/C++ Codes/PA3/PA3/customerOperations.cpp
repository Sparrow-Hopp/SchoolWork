/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  customerOperations.cpp
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

/*
* Pre: none
* Post: none
* Purpose: add a new account to the registry
*/
void addAccount()
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	string accountNum, address, name, phoneNumber, SSN;
	string sStartingAmount;
	double startingAmount;
	int count = customers.getCount() + 1;
	accountNum = inputHub();

	while (isExistsAccountNumber(accountNum))
	{
		displayMessage(1);
		accountNum = inputHub();
	}

	//get all necessary account info
	cout << "Please enter your address: " << endl;
	getline(cin, address);
	checkTerminationCode(address);
	checkLogOutCode(address);
	cout << "Please enter your name: " << endl;
	getline(cin, name);
	checkTerminationCode(name);
	checkLogOutCode(name);

	//phone number input with validity check
	cout << "Please enter your phone number: " << endl;
	getline(cin, phoneNumber);
	checkTerminationCode(phoneNumber);
	checkLogOutCode(phoneNumber);
	while (!validPhoneNumber(phoneNumber))
	{
		displayMessage(5);
		cout << "Please enter your phone number: " << endl;
		getline(cin, phoneNumber);
		checkTerminationCode(phoneNumber);
		checkLogOutCode(phoneNumber);
	}

	//ssn input with validity check
	cout << "Please enter your SSN: " << endl;
	getline(cin, SSN);
	checkTerminationCode(SSN);
	checkLogOutCode(SSN);
	while (!validSSN(SSN))
	{
		displayMessage(5);
		cout << "Please enter your SSN: " << endl;
		getline(cin, SSN);
		checkTerminationCode(SSN);
		checkLogOutCode(SSN);
	}

	//starting amount input with validity check
	cout << "Please input your starting balance: " << endl;
	getline(cin, sStartingAmount);
	checkTerminationCode(sStartingAmount);
	checkLogOutCode(sStartingAmount);
	while (!convertStr2Double(sStartingAmount, startingAmount))
	{
		displayMessage(4);
		cout << "Please input your starting balance: " << endl;
		getline(cin, sStartingAmount);
		checkTerminationCode(sStartingAmount);
		checkLogOutCode(sStartingAmount);
	}

	//create a temp Account
	Account temp(accountNum, SSN, name, address, phoneNumber, 0, startingAmount);

	//open the accounts file to override the account num at top
	ofstream fout;
	fout.open(ACCOUNTS_DATA);
	fout << count << endl;

	//go through each customer in customers and write their data to the file
	Account* accounts = customers.getAccounts();
	for (int i = 0; i < count - 1; i++)
	{
		fout << accounts[i];
	}
	fout << temp;
	fout.close();
}

/*
* Pre: a string
* Post: a double
* Purpose: display the current balance of the given account number
*/
void checkBalance(string accountNumber)
{
	cout << getCurrentBalance(accountNumber) << endl;
}

void deleteAccount()
{
	string verify;

	//get the account number
	string accountNumber = inputHub();
	while (!isExistsAccountNumber(accountNumber))
	{
		displayMessage(2);
		accountNumber = inputHub();
	}

	//make sure the user wants to delete the account
	cout << "Are you sure you want to delete this account? y/n" << endl;
	getline(cin, verify);
	checkTerminationCode(verify);
	checkLogOutCode(verify);
	while (!(verify == "y" || verify == "n"))
	{
		displayMessage(7);
		cout << "Are you sure you want to delete this account? y/n" << endl;
		getline(cin, verify);
		checkTerminationCode(verify);
		checkLogOutCode(verify);
	}
	if (verify == "n")
		hub();

	//pull up the array of accounts to more easily search and write to the output file
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	ofstream fout;
	fout.open(ACCOUNTS_DATA);
	fout << customers.getCount() - 1 << endl;//decrement the count variable by 1
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber);//don't write the account to be deleted to the file
		else
			fout << accounts[i];
	}
	fout.close();
}

/*
* Pre: a string
* Post: none
* Purpose: deposit money into the given account
*/
void deposit(string accountNumber)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	double deposit = getAmount(DEPOSIT_KEY);

	//change the balance within the given account's file
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setChecking(accounts[i].getChecking() + deposit);
	}
	customers.storeData();
}

/*
* Pre: a string
* Post: a double
* Purpose: get an amount from the user for deposit or withdrawal
*/
double getAmount(string message)
{
	string sAmount, accountNum;
	double amount;
	if (message == DEPOSIT_KEY)
	{
		cout << "Please enter the amount you would like to deposit: " << endl;
		cin >> sAmount;
		checkTerminationCode(sAmount);
		checkLogOutCode(sAmount);
		if (!convertStr2Double(sAmount, amount))//make sure the entered amount is a valid number
		{
			displayMessage(4);
			cout << "Please enter the amount you would like to deposit: " << endl;
			cin >> sAmount;
			checkTerminationCode(sAmount);
			checkLogOutCode(sAmount);
		}
	}
	else
	{
		cout << "Please enter the amount you would like to withdraw: " << endl;
		cin >> sAmount;
		checkTerminationCode(sAmount);
		checkLogOutCode(sAmount);
		while (!convertStr2Double(sAmount, amount))
		{
			displayMessage(4);
			cout << "Please enter the amount you would like to deposit: " << endl;
			cin >> sAmount;
			checkTerminationCode(sAmount);
			checkLogOutCode(sAmount);
		}
	}
	return amount;
}

/*
* Pre: a string
* Post: a double
* Purpose: return the current balance of the given account number
*/
double getCurrentBalance(string accountNumber)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	ifstream fin;
	string fileName = accountNumber + ACCOUNT_ENDING;
	double balance;
	fin.open(fileName);
	fin >> balance;//read the balance from the appropriate file
	fin.close();
	return balance;
}

/*
* Pre: none
* Post: a string
* Purpose: receive an account number from the user
*/
string inputHub()
{
	string accountNum, junk;
	cout << "Please input an account number: " << endl;
	cin >> accountNum;
	checkTerminationCode(accountNum);
	checkLogOutCode(accountNum);
	getline(cin, junk);
	if (!validAccountNumber(accountNum))//if the account isn't in a valid format
	{
		displayMessage(5);
		inputHub();
	}
	return accountNum;
}

/*
* Pre: a string
* Post: none
* Purpose: withdraw money from the given account
*/
void withdrawal(string accountNumber)
{
	customers.setFilename(ACCOUNTS_DATA);
	customers.loadData();
	double withdrawAmount = getAmount(WITHDRAWAL_KEY);

	//change the balance within the given account's file
	Account* accounts = customers.getAccounts();//search the entire registry of accounts
	for (int i = 0; i < customers.getCount(); i++)
	{
		if (accounts[i].getAccountNumber() == accountNumber)
			accounts[i].setChecking(accounts[i].getChecking() + withdrawAmount);
	}
	customers.storeData();
}

//validity checks

/*
* Pre: a string
* Post: a bool
* Purpose: see if the given accountNumber is valid
*/
bool validAccountNumber(string accountNumber)
{
	for (int i = 0; i < accountNumber.length(); i++)
	{
		if (NUMBERS.find(accountNumber[i]) == -1)//see if the current char isn't a number
			return false;
	}
	return true;
}

/*
* Pre: a string
* Post: a bool
* Purpose: see if the given phoneNumber is valid
*/
bool validPhoneNumber(string phoneNumber)
{
	if (PHONE_NUMBER_FORMAT.length() != phoneNumber.length())//check to see if the string is of the appropriate length
		return false;
	for (int i = 0; i < phoneNumber.length(); i++)
	{
		if (PHONE_NUMBER_FORMAT[i] == ' ')//check to see if the current char is a space
		{
			if (phoneNumber[i] != ' ')
				return false;
		}
		else if (NUMBERS.find(phoneNumber[i]) == -1)//see if the current char isn't a number
			return false;
	}
	return true;
}

/*
* Pre: a string
* Post: a bool
* Purpose: see if the given ssn is valid
*/
bool validSSN(string ssn)
{
	if (SSN_FORMAT.length() != ssn.length())//make sure the string is of the appropriate length
		return false;
	for (int i = 0; i < ssn.length(); i++)
	{
		if (SSN_FORMAT[i] == '-')//see if the current char is a hyphen
		{
			if (ssn[i] != '-')
				return false;
		}
		else if (NUMBERS.find(ssn[i]) == -1)//see if the current char isn't a number
			return false;
	}
	return true;
}