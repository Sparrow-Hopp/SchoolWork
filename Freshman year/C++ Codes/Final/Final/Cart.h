/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Cart.h
   *
   * Description:
   *    Code all functionality of the Champlain bookstore
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
#ifndef CART_H
#define CART_H

#pragma once
#include <iostream>
#include <fstream>
#include "LinkedList.h"

using namespace std;

const string ITEMS_FILE = "items.txt";

class Cart
{
	public:
		LinkedList mCurrentCart;
		LinkedList mAllItems;
		double mCost;
	public:
		void fillAllItems();
		LinkedList getAllItems();
		LinkedList getCart();
		double getCost();
		void setCost(double cost);
		friend ifstream &operator>>(ifstream &input, LinkedList &obj);
		friend ostream &operator<<(ostream &output, LinkedList &obj);
};

#endif