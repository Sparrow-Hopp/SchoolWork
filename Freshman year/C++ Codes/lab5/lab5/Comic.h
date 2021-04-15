/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Comic.h
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
#ifndef COMIC_H
#define COMIC_H

#pragma once
#include "Book.h"
class Comic :    public Book
{
	protected:
		//variable declarations
		int mVolume, mSeries;
	public:
		//constructors and deconstructor
		Comic();
		Comic(string code, string title, string author, double price, int quantity, int volume, int series);
		~Comic();

		//accessors
		int getVolume();
		int getSeries();

		//mutators
		void setVolume(int volume);
		void setSeries(int series);

		//operator overloads
		friend istream& operator>> (istream& input, Comic& comic);
		friend ostream& operator<< (ostream& output, Comic& comic);
};

#endif