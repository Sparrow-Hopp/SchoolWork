/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  commonFunctions.cpp
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
* Pre: a string
* Post: a boolean
* Purpose: check to see if the termination code was entered, and exit the program if it was
*/
void checkTerminationCode(string input)
{
	if (input == TERMINATION_CODE)
		hub();
}

/*
* Pre: a string
* Post: a boolean
* Purpose: check to see if the log out code was entered, and call the login function if it was
*/
void checkLogOutCode(string input)
{
	if (input == LOGOUT_CODE)
		login();
}

/*
* Pre: none
* Post: none
* Purpose: clear the output screen
*/
void clearScreen()
{
	cout << "\n\n\n\n\n";
}

/*
* Pre: a string and the address of a value
* Post: a boolean
* Purpose: convert a string to a double, return if done successfully
*/
bool convertStr2Double(string stringValue, double& value)
{
	stringstream ss;
	ss << stringValue;
	ss >> value;
	if (ss.fail() || !ss.eof())
		return false;
	else
		return true;
}

/*
* Pre: none
* Post: none
* Purpose: display the name and logo of the bank
*/
void displayLogo()
{
	ifstream fin;
	string logoLine;

	fin.open(LOGO_FILE);
	while (!fin.eof())
	{
		getline(fin, logoLine);
		cout << logoLine << endl;
	}
}

/*
* Pre: an int
* Post: none
* Purpose: Display messages to the user where each of these messages is indicated by an error code (constant)
*/
void displayMessage(int errorCode)
{
	switch (errorCode)
	{
		case 1:
			cout << "Account already existed" << endl;
			break;
		case 2:
			cout << "Account not found" << endl;
			break;
		case 3:
			cout << "Insufficient funds for withdrawal" << endl;
			break;
		case 4:
			cout << "Invalid amount" << endl;
			break;
		case 5:
			cout << "Invalid data entry" << endl;
			break;
		case 6:
			cout << "Invalid ID/Password" << endl;
			break;
		case 7:
			cout << "Invalid selection" << endl;
			break;
		case 8:
			cout << "Accounts' database not available" << endl;
			break;
		case 9:
			cout << "Tellers' database not available" << endl;
			break;
	}
}

/*
* Pre: none
* Post: none
* Purpose: be the main "hub" for all activity in the system
*/
void hub()
{
	clearScreen();
	systemPause();
	string selection;
	int iSelection;
	selection = mainMenu();
	iSelection = stoi(selection);
	switch (iSelection)
	{
		case 1:
		{
			addAccount();
			hub();
		}
		case 2:
		{
			deleteAccount();
			hub();
		}
		case 3:
		{
			updateMenu();
			hub();
		}
		case 4:
		{
			string foundItem = searchMenu();
			cout << foundItem << endl;
			hub();
		}
		case 5:
		{
			string accountNum = inputHub();
			deposit(accountNum);
			hub();
		}
		case 6:
		{
			string accountNum = inputHub();
			withdrawal(accountNum);
			hub();
		}
		case 7:
		{
			string accountNum = inputHub();
			cout << "Here is your current balance: ";
			checkBalance(accountNum);
		}
		case 8:
		{
			login();
		}
		case 9:
		{
			exit(0);
		}
	}
}

/*
* Pre: none
* Post: a string
* Purpose: display the main menu screen
*/
string mainMenu()
{
	string selection;
	int iSelection;
	cout << "1.\tAdd a new account\n2.\tDelete an existing account\n3.\tUpdate information on an existing account\n4.\tSearch accountinformation\n5.\tDeposit money into an account";
	cout << "\n6.\tWithdraw money from an account\n7.\tCheck balance on an account\n8.\tLog out\n9.\tShut down" << endl;
	cout << "Please make a selection: " << endl;
	cin >> selection;
	checkTerminationCode(selection);
	checkLogOutCode(selection);
	if (NUMBERS.find(selection) == -1)
	{
		displayMessage(7);
		mainMenu();
	}
	iSelection = stoi(selection);
	if (!(iSelection > 0 && iSelection < 10))
	{
		displayMessage(7);
		mainMenu();
	}
	clearScreen();
	return selection;
}

/*
* Pre: a string
* Post: none
* Purpose: convert the string to all upper case
*/
void toUpper(string stringValue)
{
	string upperString = "";
	for (int i = 0; i < stringValue.length(); i++)
		upperString += toupper(stringValue[i]);
	stringValue = upperString;
}

/*
* Pre: none
* Post: none
* Purpose: pause the system until there is an input
*/
void systemPause()
{
	system("pause");
}