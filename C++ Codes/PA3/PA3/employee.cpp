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