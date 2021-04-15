/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Book.h
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
#ifndef BOOK_H
#define BOOK_H

#pragma once
#include "Item.h"
class Book :    public Item
{
	protected:
		//declare variables
		string mAuthor, mTitle;
	public:
		//constructors and deconstructor
		Book();
		Book(string code, string title, string author, double price, int quantity);
		~Book();

		//accessors
		string getAuthor();
		string getTitle();

		//mutators
		void setAuthor(string author);
		void setTitle(string title);

		//operator overloads
		friend istream& operator>> (istream& input, Book& book);
		friend ostream& operator<< (ostream& output, Book& book);

};

#endif