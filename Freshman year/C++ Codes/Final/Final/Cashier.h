
#ifndef CASHIER_H
#define CASHIER_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Reports.h"
#include "Cart.h"

/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Cashier.h
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
using namespace std;

const string FILE_CASHIERS = "cashiers.txt";

class Cashier
{
	protected: 
		string mName;
		string mEmail;
		string mPhone;
		Day mDay;
		Cart mCart;

	public:
		//constructor
		Cashier();
		Cashier(string name, string email, string phone);

		//accessors and modifiers
		string getEmail();
		string getName();
		string getPhone();
		void setEmail(string email);
		void setName(string name);
		void setPhone(string phone);


		//operator overloads
		friend ifstream &operator>> (ifstream &in, Cashier &obj);
		friend ofstream &operator<< (ofstream &out, Cashier &obj);
		friend bool operator== (Cashier &lhs, string name);

		//cashier operations
		void addItem();
		void removeItem();
		void completeTransaction();
		void voidTransaction();
		void searchItem();
};

#endif