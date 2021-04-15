/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Item.cpp
   *
   * Description:
   *    Create a "family" of classes that define an item, book, and a comic
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

#include "Item.h"

//constructors and deconstructor

/*
* Pre: none
* Post: none
* Purpose: define item using the default values
*/
Item::Item()
{
	mCode = "";
	mPrice = 0.0;
	mQuantity = 0;
}

/*
* Pre: none
* Post: none
* Purpose: define item using the given values
*/
Item::Item(string code, double price, int quantity)
{
	mCode = code;
	mPrice = price;
	mQuantity = quantity;
}

/*
* Pre: none
* Post: none
* Purpose: destroy the item at the end of runtime
*/
Item::~Item()
{
}

//accessors

/*
* Pre: none
* Post: string
* Purpose: get the value inside mCode
*/
string Item::getCode()
{
	return mCode;
}

/*
* Pre: none
* Post: double
* Purpose: get the value inside mPrice
*/
double Item::getPrice()
{
	return mPrice;
}

/*
* Pre: none
* Post: int
* Purpose: get the value inside mQuantity
*/
int Item::getQuantity()
{
	return mQuantity;
}

/*
* Pre: string
* Post: none
* Purpose: change the value inside mCode
*/
void Item::setCode(string code)
{
	mCode = code;
}

/*
* Pre: double
* Post: none
* Purpose: change the value inside mPrice
*/
void Item::setPrice(double price)
{
	mPrice = price;
}

/*
* Pre: int
* Post: none
* Purpose: change the value inside mQuantity
*/
void Item::setQuantity(int quantity)
{
	mQuantity = quantity;
}

//operator overloads

/*
* Pre: the input stream and an item
* Post: the input stream
* Purpose: define all the values in item from the input stream
*/
istream& operator>>(istream& input, Item& item)
{
	string junk;
	cout << "Enter the code: " << endl;
	getline(input, item.mCode);
	cout << "Enter the price: " << endl;
	input >> item.mPrice >> junk;
	cout << "Enter the quantity: " << endl;
	input >> item.mQuantity >> junk;

	return input;
}

/*
* Pre: the output stream and an item
* Post: the output stream
* Purpose: display all the values in item
*/
ostream& operator<<(ostream& output, Item& item)
{
	output << fixed << showpoint << setprecision(2);
	output << "Code: " << item.mCode << "\nPrice: " << item.mPrice << "\nQuantity: " << item.mQuantity << "\n\n\n";
	return output;
}
