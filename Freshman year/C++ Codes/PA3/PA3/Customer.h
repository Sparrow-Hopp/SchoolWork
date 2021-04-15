/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  Customer.h
   *
   * Description:
   *    Code all functionality of a bank teller
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

#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "account.h"

using namespace std;
class Customer
{
	private:
		int mCount;
		Account* mAccounts;
		string mFilename;
	public:
		//constructor and deconstructor
		Customer();
		~Customer();

		//accessors
		Account* getAccounts();
		int getCount();
		Account getCustomer(string accountNumber);
		string getFilename();

		//mutators
		void setFilename(string filename);

		//other methods
		bool loadData();
		void storeData();
};

#endif