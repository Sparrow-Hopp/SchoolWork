/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  employee.cpp
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
#include "employee.h"


/*
* Pre: an input stream and an employee
* Post: the input stream
* Purpose: read from the input stream and populate the values inside the obj
*/
istream& operator>>(istream& input, Employee& obj)
{
	input >> obj.mID >> obj.mPW;
	return input;
}

/*
* Pre: an output stream and an employee
* Post: the output stream
* Purpose: read from the obj and print the values inside the obj to the output stream
*/
ostream& operator<<(ostream& output, const Employee& obj)
{
	output << obj.mID << " " << obj.mPW << endl;
	return output;
}