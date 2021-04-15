/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Book.cpp
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

#include "Book.h"

//constructors and deconstructor

/*
* Pre: none
* Post: none
* Purpose: define book using the default values
*/
Book::Book() : Item()//reuse code from item
{
	mAuthor = "";
	mTitle = "";
}

/*
* Pre: none
* Post: three strings, a double and an int
* Purpose: define book using the given values
*/
Book::Book(string code, string title, string author, double price, int quantity) : Item(code, price, quantity)//reuse code from item
{
	mTitle = title;
	mAuthor = author;
}

/*
* Pre: none
* Post: none
* Purpose: destroy the book at the end of runtime
*/
Book::~Book()
{
}

//accessors

/*
* Pre: none
* Post: string
* Purpose: get the value inside mAuthor
*/
string Book::getAuthor()
{
	return mAuthor;
}

/*
* Pre: none
* Post: string
* Purpose: get the value inside mTitle
*/
string Book::getTitle()
{
	return mTitle;
}

//mutators

/*
* Pre: string
* Post: none
* Purpose: change the value inside mAuthor
*/
void Book::setAuthor(string author)
{
	mAuthor = author;
}

/*
* Pre: string
* Post: none
* Purpose: change the value inside mTitle
*/
void Book::setTitle(string title)
{
	mTitle = title;
}

//operator overloads

/*
* Pre: the input stream and a book
* Post: the input stream
* Purpose: define all the values in book from the input stream
*/
istream& operator>>(istream& input, Book& book)
{
	cout << "Enter the code: " << endl;
	getline(input, book.mCode);
	cout << "Enter the title: " << endl;
	getline(input, book.mTitle);
	cout << "Enter the author: " << endl;
	getline(input, book.mAuthor);
	cout << "Enter the price: " << endl;
	input >> book.mPrice;
	cout << "Enter the quantity: " << endl;
	input >> book.mQuantity;

	return input;
}

/*
* Pre: the output stream and a book
* Post: the output stream
* Purpose: display all the values in book
*/
ostream& operator<<(ostream& output, Book& book)
{
	output << fixed << showpoint << setprecision(2);
	output << "Code: " << book.mCode << "\nTitle: " << book.mTitle << "\nAuthor: " << book.mAuthor << "\nPrice: " << book.mPrice << "\nQuantity: " << book.mQuantity << "\n\n\n";
	return output;
}
