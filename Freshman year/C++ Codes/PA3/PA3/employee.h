/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  employee.h
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
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>


using namespace std;

struct Employee
{
	//variables
	string mID, mPW;

	//method overloading
	friend istream& operator>>(istream& input, Employee& obj);
	friend ostream& operator<<(ostream& output, const Employee& obj);
};

#endif
