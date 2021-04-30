
#ifndef CASHIER_H
#define CASHIER_H

#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Reports.h"
#include "Cart.h"

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