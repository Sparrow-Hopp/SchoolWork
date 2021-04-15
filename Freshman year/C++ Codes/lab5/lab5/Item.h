/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  Item.h
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
#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <iomanip>
#include <string>

#pragma once

using namespace std;

class Item
{
	protected:
		//define variables
		string mCode;
		double mPrice;
		int mQuantity;
	public:
		//constructors and deconstructor
		Item();
		Item(string code, double price, int quantity);
		~Item();

		//accessors
		string getCode();
		double getPrice();
		int getQuantity();

		//mutators
		void setCode(string code);
		void setPrice(double price);
		void setQuantity(int quantity);

		//operator overloads
		friend istream& operator>>(istream& input, Item& item);
		friend ostream& operator<<(ostream& output, Item& item);
};

#endif // !ITEM_H
