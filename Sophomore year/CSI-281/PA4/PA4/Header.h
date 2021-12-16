/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA4
* Date Assigned:  11/4/21
*      Due Date:  11/5/21
*      Filename:  Header.h
*
* Description:
*    Convert a valid inputted equation to postfix notation, and then evaluate it from postfix notation
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


#pragma once
#include "queue.h"
#include "stack.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

const string NUMS = "1234567890";
const string OPERATORS = "+-*/^";
const string OPEN_PARENTHESES = "(";
const string CLOSED_PARENTHESES = ")";
const string VALID_CHARACTERS = NUMS + OPERATORS + OPEN_PARENTHESES + CLOSED_PARENTHESES + " ";
const char PLUS = '+';
const char MINUS = '-';
const char TIMES = '*';
const char DIVIDE = '/';
const char POWER = '^';
const char SPACE = ' ';

void evaulate(string equation);
string getEquation();
bool isValidEquation(string equation);
int makeArray(string equation, string* theArray);
string printPost(string equation);
