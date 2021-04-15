/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Comic.cpp
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

#include "Comic.h"

//constructors and deconstructor

/*
* Pre: none
* Post: none
* Purpose: define comic using the default values
*/
Comic::Comic() : Book()//reuse code from book
{
	mVolume = 0;
	mSeries = 0;
}

/*
* Pre: three strings, a double, three ints
* Post: none
* Purpose: define comic using the given values
*/
Comic::Comic(string code, string title, string author, double price, int quantity, int volume, int series) : Book(code, title, author, price, quantity)//reuse code from book
{
	mVolume = volume;
	mSeries = series;
}

/*
* Pre: none
* Post: none
* Purpose: destroy the comic at the end of runtime
*/
Comic::~Comic()
{
}
//accessors

/*
* Pre: none
* Post: int
* Purpose: get the value inside mVolume
*/
int Comic::getVolume()
{
	return mVolume;
}

/*
* Pre: none
* Post: int
* Purpose: get the value inside mSeries
*/
int Comic::getSeries()
{
	return mSeries;
}

//mutators

/*
* Pre: int
* Post: none
* Purpose: change the value inside mVolume
*/
void Comic::setVolume(int volume)
{
	mVolume = volume;
}

/*
* Pre: int
* Post: none
* Purpose: change the value inside mSeries
*/
void Comic::setSeries(int series)
{
	mSeries = series;
}

//operator overloads

/*
* Pre: the input stream and a comic
* Post: the input stream
* Purpose: define all the values in book from the input comic
*/
istream& operator>>(istream& input, Comic& comic)
{
	cout << "Enter the code: " << endl;
	getline(input, comic.mCode);
	cout << "Enter the title: " << endl;
	getline(input, comic.mTitle);
	cout << "Enter the author: " << endl;
	getline(input, comic.mAuthor);
	cout << "Enter the price: " << endl;
	input >> comic.mPrice;
	cout << "Enter the quantity: " << endl;
	input >> comic.mQuantity;
	cout << "Enter the volume: " << endl;
	input >> comic.mVolume;
	cout << "Enter the series: " << endl;
	input >> comic.mSeries;

	return input;
}

/*
* Pre: the output stream and a comic
* Post: the output stream
* Purpose: display all the values in comic
*/
ostream& operator<<(ostream& output, Comic& comic)
{
	output << fixed << showpoint << setprecision(2);
	output << "Code: " << comic.mCode << "\nTitle: " << comic.mTitle << "\nAuthor: " << comic.mAuthor << "\nPrice: " << comic.mPrice << "\nQuantity: " << comic.mQuantity << "\nVolume: " << comic.mVolume
		<< "\nSeries: " << comic.mSeries << "\n\n\n";
	return output;
}
