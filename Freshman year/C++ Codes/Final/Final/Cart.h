
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