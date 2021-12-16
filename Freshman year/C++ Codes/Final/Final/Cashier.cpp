/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Cashier.cpp
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

#include "Cashier.h"



//constructors

Cashier::Cashier()
{
	mName = "";
	mEmail = "";
	mPhone = "";
	mCart.fillAllItems();
}

Cashier::Cashier(string name, string email, string phone)
{
	mName = name;
	mEmail = email;
	mPhone = phone;
}

//accessors and modifiers

/*
* Pre: none
* Post: string
* Purpose: get the email of the cashier
*/
string Cashier::getEmail()
{
	return mEmail;
}

/*
* Pre: none
* Post: string
* Purpose: get the name of the cashier
*/
string Cashier::getName()
{
	return mName;
}

/*
* Pre: none
* Post: string
* Purpose: get the phone of the cashier
*/
string Cashier::getPhone()
{
	return mPhone;
}

/*
* Pre: string
* Post: none
* Purpose: set the email of the cashier
*/
void Cashier::setEmail(string email)
{
	mEmail = email;
}

/*
* Pre: string
* Post: none
* Purpose: set the name of the cashier
*/
void Cashier::setName(string name)
{
	mName = name;
}

/*
* Pre: string
* Post: none
* Purpose: set the phone of the cashier
*/
void Cashier::setPhone(string phone)
{
	mPhone = phone;
}

//operator overloads

/*
* Pre: ifstream and Cashier
* Post: ifstream
* Purpose: populate the variables of the cashier using data from an input file
*/
ifstream &operator>> (ifstream &in, Cashier &obj)
{
	string name, email, phone;
	getline(in, name);
	getline(in, email);
	getline(in, phone);
	obj.setEmail(email);
	obj.setName(name);
	obj.setPhone(phone);
	return in;
}

/*
* Pre: ofstream and Cashier
* Post: ofstream
* Purpose: write the data of the cashier to an output file
*/
ofstream &operator<< (ofstream &out, Cashier &obj)
{
	out << obj.getName() << endl << obj.getEmail() << endl << obj.getPhone() << endl;
	return out;
}

bool operator== (Cashier &lhs, string name)
{
	return (lhs.getName() == name);
}

//cashier operations

/*
* Pre: none
* Post: none
* Purpose: add an item to the cart
*/
void Cashier::addItem()
{
	int selection;
	mCart.mAllItems.display();
	cout << "Please make a selection " << endl;
	cin >> selection;
	while (--selection < 0 || selection > mCart.mAllItems.getCount())
	{
		cout << "Invalid selection. Make a new selection." << endl;
		cin >> selection;
	}
	string name = mCart.mAllItems.getName(selection);
	double price = mCart.mAllItems.getPrice(selection);
	//cout << name << endl << price << endl;
	mCart.mCurrentCart.insert(price, name);
	mCart.mCost += price;
}

/*
* Pre: none
* Post: none
* Purpose: complete the transaction
*/
void Cashier::completeTransaction()
{
	string junk;
	double cash;
	cout << "Your amount owed is $" << mCart.mCost << ". Please give your change now." << endl;
	getline(cin, junk);
	cin >> cash;
	if (cash < mCart.mCost)
	{
		cout << "Insufficient funds" << endl;
	}
	else
	{
		cout << "Your change is $" << cash - mCart.mCost << ". Have a nice day." << endl;
		mDay.mTotalItems += mCart.mCurrentCart.getCount();
		mDay.mTotalOrders++;
		mDay.mTotalSales += mCart.mCost;
		mDay.mAverageItemsPerOrder = mDay.mTotalItems / mDay.mTotalOrders;
		mCart.mCurrentCart.clear();
		mCart.mCost  = 0;
	}
}

/*
* Pre: none
* Post: none
* Purpose: remove an item from the cart
*/
void Cashier::removeItem()
{
	int selection;
	mCart.mCurrentCart.display();
	cout << "Please make a selection " << endl;
	cin >> selection;
	while (--selection < 1 || selection > mCart.mCurrentCart.getCount())
	{
		cout << "Invalid selection. Make a new selection." << endl;
		cin >> selection;
	}
	string name = mCart.mCurrentCart.getName(selection);
	double price = mCart.mCurrentCart.getPrice(selection);
	mCart.mCurrentCart.remove(price, name);
	mCart.mCost -= price;
}

/*
* Pre: none
* Post: none
* Purpose: search for an item, and if it exists, ask if you want to add it to the cart
*/
void Cashier::searchItem()
{
	string name;
	double price;
	cout << "Please enter the name of the item you're looking for" << endl;
	getline(cin, name);
	getline(cin, name);
	cout << "Please enter the price of the item you're looking for" << endl;
	cin >> price;
	if (mCart.mAllItems.isExist(price, name))
	{
		string selection;
		cout << "The item does exist. Add it to your cart? y/n" << endl;
		cin >> selection;
		if (selection == "y")
		{
			mCart.mCurrentCart.insert(price, name);
			mCart.mCost += price;
		}
	}
	else
		cout << "This item does not exist" << endl;
}

/*
* Pre: none
* Post: none
* Purpose: void the current transaction and clear the cart
*/
void Cashier::voidTransaction()
{
	cout << "Cart has been cleared." << endl;
	mCart.mCurrentCart.clear();
	mCart.mCost = 0;
}