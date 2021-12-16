/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA4
* Date Assigned:  11/4/21
*      Due Date:  11/5/21
*      Filename:  functions.cpp
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

/*
* Pre: a string
* Post: none
* Purpose: to evaluate a postfix equation
*/
void evaulate(string equation)
{
	Stack<string> eval;
	string temp;
	int i;
	for (i = 0; i < equation.length(); i++)
	{
		if (equation.at(i) == SPACE);
		else if (NUMS.find(equation.at(i), 0) != -1)
		{
			int k = i;
			temp = equation.at(k++);
			while (k < equation.length() && NUMS.find(equation.at(k), 0) != -1)
			{
				temp += equation.at(k);
				k++;
			}
			i = k;
			eval.push(temp);
		}
		else
		{
			int result;
			char operand = equation.at(i);
			int right = stoi(eval.pop());
			int left = stoi(eval.pop());

			switch (operand)
			{
				case PLUS:
					result = left + right;
					break;
				case MINUS:
					result = left - right;
					break;
				case TIMES:
					result = left * right;
					break;
				case DIVIDE:
					result = left / right;
					break;
				case POWER:
					result = pow(left, right);
					break;
			}
			eval.push(to_string(result));
		}
	}
	cout << "The evaluated equation is " << eval.pop();
	cout << endl;
}

/*
* Pre: none
* Post: a string
* Purpose: to get a valid equation to convert to postfix
*/
string getEquation()
{
	string equation;
	cout << "Please input your equation" << endl;
	getline(cin, equation);
	while (!isValidEquation(equation))
	{
		cout << "Invalid equation. Please input a new equation" << endl;
		getline(cin, equation);
	}
	return equation;
}

/*
* Pre: a string
* Post: a bool
* Purpose: check to see if the given equation is valid
*/
bool isValidEquation(string equation)
{
	for (int i = 0; i < equation.length(); i++)
	{
		if (VALID_CHARACTERS.find(equation[i], 0) == -1)
			return false;
	}
	return true;
}

/*
* Pre: a string, and a pointer to a string
* Post: an int
* Purpose: to take the equation and put it into an array
*/
int makeArray(string equation, string* theArray)
{
	string temp;
	int i, j = 0;
	for (i = 0; i < equation.length(); i++)
	{
		if (NUMS.find(equation.at(i), 0) != -1)
		{
			int k = i;
			temp = equation.at(k++);
			while (k < equation.length() && (NUMS.find(equation.at(k), 0) != -1 || equation.at(k) == ' '))
			{
				temp += equation.at(k);
				k++;
			}
			i = k - 1;
			theArray[j++] = temp;
		}
		else
			theArray[j++] = equation.at(i);
	}
	return j;
}

/*
* Pre: a string
* Post: a string
* Purpose: to convert the given equation to postfix notation and print it
*/
string printPost(string equation)
{
	string* assistance = new string[equation.length()];
	int length = makeArray(equation, assistance);
	Stack<string> eval;
	string postfix;
	for (int i = 0; i < length; i++)
	{
		if (OPERATORS.find(assistance[i], 0) != -1)
		{
			//pop all until next operator or open parentheses
			while (OPERATORS.find(eval.peek(), 0) && eval.peek() != OPEN_PARENTHESES)
				postfix += eval.pop();
			//push new operator
			eval.push(assistance[i]);
		}
		else if (assistance[i] == CLOSED_PARENTHESES)
		{
			while (eval.peek() != OPEN_PARENTHESES)
			{
				if (eval.isEmpty())
				{
					cout << "unbalanced equation. aborting." << endl;
					return "";
				}
				postfix += eval.pop();
			}
			eval.pop();
		}
		else
		{
			eval.push(assistance[i]);
		}
	}

	if (!eval.isEmpty())
	{
		cout << "unbalanced equation. aborting." << endl;
		return "";
	}
	cout << "your postfix equation is " << postfix << endl;
	delete[] assistance;
	return postfix;
}
