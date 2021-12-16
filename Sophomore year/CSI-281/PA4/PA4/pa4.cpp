/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA4
* Date Assigned:  11/4/21
*      Due Date:  11/5/21
*      Filename:  pa4.cpp
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

#include "Header.h"

int main()
{
	string equation = getEquation();
	string postFix = printPost(equation);
	evaulate(postFix);
	return 0;
}