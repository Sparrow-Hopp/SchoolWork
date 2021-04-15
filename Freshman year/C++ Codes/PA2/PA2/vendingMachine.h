/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA2
   * Date Assigned:  February 18, 2021
   *      Due Date:  March 1, 2021, 13:00
   *      Filename:  functions.cpp
   *
   * Description:
   *    Code all functionality of a vending machine
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
#ifndef VENDINGMACHINE_H
#define VENDINGMACHINE_H

#pragma once
#include "Item.h"
#include <iostream>
#include <string>

using namespace std;

const int MAX_QUANTITY = 20;
const double BASE_MONEY = 5.00;
const string BASE_PASSWORD = "password";
const int BASE_NUM_ITEMS = 4;
const int MAX_STOCK_SIZE = 30;
const string DATA_FILE_NAME = "data.txt";

class VendingMachine
{
	private:
		//list variables
		string mPassword;
		double mMoney;
		Item mStock [MAX_STOCK_SIZE];
		int mNumItems;
	public: 
		//constructors
		VendingMachine();

		//accessors and mutators
		double getMoney();
		int getNumItems();
		string getPassword();
		void setMoney(double m);
		void setNumItems(int n);
		void setPassword(string p);
	
		//other methods
		void addItem();
		void collectMoney();
		void ownerMenu();
		void removeItem();
		void restock();
		void shutDown();
		void userMenu();

		//deconstructor
		~VendingMachine();
};

#endif