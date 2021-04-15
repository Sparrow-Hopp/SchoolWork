/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  tellerOperations.cpp
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
* Pre: the address of two strings
* Post: none
* Purpose: Get the ID and password from the teller
*/
void getIdPassword(string& id, string& password)
{
	cout << "Enter your id: " << endl;
	cin >> id;
	checkTerminationCode(id);

	cout << "Enter your password" << endl;

	//CODE TAKEN FROM http://www.cplusplus.com/forum/general/91313/
	char c;
	// loop condition: get a character, while it isn't a newline (end of password), then...
	while ((c = _getch()) != '\n')
	{
		if (c == '\r')
			break;
		// put it onto the back of the password
		password.push_back(c);
		// output a '*' character
		_putch('*');
	}
	checkTerminationCode(password);
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
	bool valid;
	do
	{
		getIdPassword(id, password);
		valid = validateLogin(id, password);
		if (valid)
			break;
		displayMessage(6);
	} while (!valid);
	hub();
}

/*
* Pre: two strings
* Post: a boolean
* Purpose: Validate the ID and password pair is correct according to the data in "tellers.dat"
			The function returns true if the pair is correct; otherwise false
*/
bool validateLogin(string id, string password)
{
	tellers.loadData(TELLERS_DATA);
	return tellers.verifyTeller(id, password);
}