#include "account.h"

using namespace std;

/*
* Pre: none
* Post: none
* Purpose: define the variables within the account with the default variables
*/
Account::Account()
{
	mSSN = "000-00-0000";
	mName = "John Doe";
	mSaving = 0.00;
	mChecking = 0.00;
	mTotal = 0.00;
}

/*
* Pre: none
* Post: none
* Purpose: define the variables within the account with the provided variables
*/
Account::Account(string ssn, string name, double saving, double checking)
{
	mSSN = ssn;
	mName = name;
	mSaving = saving;
	mChecking = checking;
	mTotal = mChecking + mSaving;
}

/*
* Pre: none
* Post: none
* Purpose: deconstruct the account at the end of run time
*/
Account::~Account()
{
}

//accessors and mutators

/*
* Pre: none
* Post: the contents of checking
* Purpose: show the contents of checking
*/
double Account::getChecking()
{
	setprecision(2);
	return mChecking;
}

/*
* Pre: none
* Post: the contents of name
* Purpose: show the contents of name
*/
string Account::getName()
{
	return mName;
}

/*
* Pre: none
* Post: the contents of saving
* Purpose: show the contents of saving
*/
double Account::getSaving()
{
	setprecision(2);
	return mSaving;
}

/*
* Pre: none
* Post: the contents of SSN
* Purpose: show the contents of SSN
*/
string Account::getSSN()
{
	return mSSN;
}

/*
* Pre: none
* Post: the contents of total
* Purpose: show the contents of total
*/
double Account::getTotal()
{
	setprecision(2);
	return mTotal;
}


/*
* Pre: new contents of checking
* Post: none
* Purpose: reassign the contents of checking
*/
void Account::setChecking(double checking)
{
	mChecking = checking;
	mTotal = mSaving + mChecking;
}

/*
* Pre: new contents of name
* Post: none
* Purpose: reassign the contents of name
*/
void Account::setName(string name)
{
	mName = name;
}

/*
* Pre: new contents of saving
* Post: none
* Purpose: reassign the contents of saving
*/
void Account::setSaving(double saving)
{
	mSaving = saving;
	mTotal = mSaving + mChecking;
}

/*
* Pre: new contents of SSN
* Post: none
* Purpose: reassign the contents of SSN
*/
void Account::setSSN(string ssn)
{
	mSSN = ssn;
}



//member operator overloading

/*
* Pre: an account
* Post: a boolean
* Purpose: see if the SSN of the current account is the same as the SSN of the provided account
*/
bool Account::operator==(const Account &rhs)
{
	return mSSN == rhs.mSSN;
}

/*
* Pre: a string
* Post: a boolean
* Purpose: see if the SSN of the current account is the same as the SSN of the provided string
*/
bool Account::operator==(const string &rhs)
{
	return getSSN() == rhs;
}

/*
* Pre: an account
* Post: a boolean
* Purpose: see if the SSN of the current account isn't the same as the SSN of the provided account
*/
bool Account::operator!=(const Account &rhs)
{
	return mSSN != rhs.mSSN;
}

/*
* Pre: a string
* Post: a boolean
* Purpose: see if the SSN of the current account isn't the same as the SSN of the provided string
*/
bool Account::operator!=(const string &rhs)
{
	return mSSN == rhs;
}

/*
* Pre: an account
* Post: a boolean
* Purpose: see if the total value of the current account is greater than the total value of the provided account
*/
bool Account::operator>(const Account &rhs)
{
	return mTotal > rhs.mTotal;
}

/*
* Pre: an account
* Post: a boolean
* Purpose: see if the total value of the current account is less than the total value of the provided account
*/
bool Account::operator<(const Account &rhs)
{
	return mTotal < rhs.mTotal;
}

//friend operator overloading

/*
* Pre: an account and an output stream
* Post: the output stream
* Purpose: print all of the contents of the account as formatted
*/
ostream &operator<<(ostream &output, const Account &obj)
{
	output << fixed << showpoint << setprecision(2);
	output << obj.mSSN << endl << obj.mName << endl << obj.mSaving << " " << obj.mChecking << endl << obj.mTotal << endl;
	return output;
}

/*
* Pre: an account and an output stream
* Post: the output stream
* Purpose: print all of the contents of the account as formatted
*/
ofstream &operator<<(ofstream &output, const Account &obj)
{
	output << fixed << showpoint << setprecision(2);
	output << obj.mSSN << endl << obj.mName << endl << obj.mSaving << " " << obj.mChecking << endl << obj.mTotal << endl;
	return output;
}

/*
* Pre: an account and an input stream
* Post: the input stream
* Purpose: define all of the contents of the account as formatted
*/
istream &operator>>(istream &input, Account &obj)
{
	string junk;
	cout << "\n\nEnter your SSN" << endl;
	input >> obj.mSSN;
	cout << "Enter your first and last name" << endl;
	getline(input, junk);
	getline(input, obj.mName);
	cout << "Enter the amount of money in your savings account, then the amount of money in your checking account" << endl;
	input >> obj.mSaving >> obj.mChecking;
	obj.mTotal = obj.mSaving + obj.mChecking;
	getline(input, junk);
	return input;
}

/*
* Pre: an account and an input stream
* Post: the input stream
* Purpose: define all of the contents of the account as formatted
*/
ifstream &operator>>(ifstream &input, Account &obj)
{
	string junk;
	cout << "\n\nEnter your SSN" << endl;
	input >> obj.mSSN;
	cout << "Enter your first and last name" << endl;
	getline(input, junk);
	getline(input, obj.mName);
	cout << "Enter the amount of money in your savings account, then the amount of money in your checking account" << endl;
	input >> obj.mSaving >> obj.mChecking;
	obj.mTotal = obj.mSaving + obj.mChecking;
	getline(input, junk);
	return input;
}

/*
* Pre: an account and a string
* Post: a boolean
* Purpose: see if the contents of the string are the same as the SSN of the account
*/
bool operator==(const string &lhs, const Account &rhs)
{
	return lhs == rhs.mSSN;
}

/*
* Pre: an account and a string
* Post: a boolean
* Purpose: see if the contents of the string aren't the same as the SSN of the account
*/
bool operator!=(const string &lhs, const Account &rhs)
{
	return lhs != rhs.mSSN;
}
