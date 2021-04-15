/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  account.cpp
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

#include "account.h"

using namespace std;

/*
* Pre: none
* Post: none
* Purpose: define the variables within the account with the default variables
*/
Account::Account()
{
	mAccountNum = "00000";
	mSSN = "000-00-0000";
	mName = "John Doe";
	mAddress = "123 Bird Ln., Burlington, VT 05401";
	mPhoneNumber = "000 000 0000";
	mSaving = 0.00;
	mChecking = 0.00;
	mTotal = 0.00;
}

/*
* Pre: none
* Post: none
* Purpose: define the variables within the account with the provided variables
*/
Account::Account(string accountNum, string ssn, string name, string address, string phoneNumber, double saving, double checking)
{
	mAccountNum = accountNum;
	mSSN = ssn;
	mName = name;
	mAddress = address;
	mPhoneNumber = phoneNumber;
	mSaving = saving;
	mChecking = checking;
	mTotal = mChecking + mSaving;
}

/*
* Pre: none
* Post: none
* Purpose: destroy all data for the account at the end of run time
*/
Account::~Account()
{
	
}

//accessors

/*
* Pre: none
* Post: the contents of accountNum
* Purpose: show the contents of accountNum
*/
string Account::getAccountNumber()
{
	return mAccountNum;
}

/*
* Pre: none
* Post: the contents of address
* Purpose: show the contents of address
*/
string Account::getAddress()
{
	return mAddress;
}

/*
* Pre: none
* Post: the contents of checking
* Purpose: show the contents of checking
*/
double Account::getChecking()
{
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
* Post: the contents of phoneNumber
* Purpose: show the contents of phoneNumber
*/
string Account::getPhoneNumber()
{
	return mPhoneNumber;
}

/*
* Pre: none
* Post: the contents of saving
* Purpose: show the contents of saving
*/
double Account::getSaving()
{
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
	return mTotal;
}

//mutators

/*
* Pre: new contents of accountNum
* Post: none
* Purpose: reassign the contents of accountNum
*/
void Account::setAccountNumber(string accountNum)
{
	mAccountNum = accountNum;
}

/*
* Pre: new contents of address
* Post: none
* Purpose: reassign the contents of address
*/
void Account::setAddress(string address)
{
	mAddress = address;
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
* Pre: new contents of phoneNumber
* Post: none
* Purpose: reassign the contents of phoneNumber
*/
void Account::setPhoneNumber(string phoneNumber)
{
	mPhoneNumber = phoneNumber;
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
* Purpose: see if the accountNumber of the current account is the same as the accountNumber of the provided account
*/
bool Account::operator==(const Account &rhs)
{
	return mAccountNum == rhs.mAccountNum;
}

/*
* Pre: a string
* Post: a boolean
* Purpose: see if the accountNumber of the current account is the same as the accountNumber of the provided string
*/
bool Account::operator==(const string &rhs)
{
	return mAccountNum == rhs;
}

/*
* Pre: an account
* Post: a boolean
* Purpose: see if the accountNumber of the current account isn't the same as the accountNumber of the provided account
*/
bool Account::operator!=(const Account &rhs)
{
	return mAccountNum != rhs.mAccountNum;
}

/*
* Pre: a string
* Post: a boolean
* Purpose: see if the accountNumber of the current account isn't the same as the accountNumber of the provided string
*/
bool Account::operator!=(const string &rhs)
{
	return mAccountNum == rhs;
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
	output << "Account Number: " << obj.mAccountNum << endl << "SSN: " << obj.mSSN << endl << "Name: " << obj.mName << endl 
		<< "Address: " << obj.mAddress << endl << "Phone Number: " << obj.mPhoneNumber << endl << "Saving Amount: $" << obj.mSaving << endl << "Checking Amount: $" << obj.mChecking << endl;
	return output;
}

/*
* Pre: an account and an output stream
* Post: the output stream
* Purpose: print all of the contents of the account as formatted
*/
ofstream &operator<<(ofstream &output, const Account &obj)
{
	//declare output streams and names of output files for savings and checking
	ofstream foutSave, foutCheck;
	string savingsFile = obj.mAccountNum + SAVINGS_SUFFIX;
	string checkingFile = obj.mAccountNum + CHECKING_SUFFIX;

	//open output files
	foutSave.open(savingsFile);
	foutCheck.open(checkingFile);

	//check to see if they all opened properly
	foutSave << obj.mSaving;
	foutCheck << obj.mChecking;
	output << obj.mAccountNum << endl << obj.mSSN << endl << obj.mName << endl << obj.mAddress << endl << obj.mPhoneNumber << endl;

	//close all files
	foutSave.close();
	foutCheck.close();

	return output;
}

/*
* Pre: an account and an input stream
* Post: the input stream
* Purpose: define all of the contents of the account as formatted
*/
istream &operator>>(istream &input, Account &obj)
{
	string savings, checking;

	cout << "Account Number: " << endl;
	getline(input, obj.mAccountNum);
	cout << "SSN: " << endl;
	getline(input, obj.mSSN);
	cout << "Name: " << endl;
	getline(input, obj.mName);
	cout << "Address (one line): " << endl;
	getline(input, obj.mAddress);
	cout << "Phone Number: " << endl;
	getline(input, obj.mPhoneNumber);
	cout << "Savings Amount: $" << endl;
	getline(input, savings);
	obj.mSaving = stod(savings);
	cout << "Checking Amount: $" << endl;
	getline(input, checking);
	obj.mChecking = stod(checking);
	obj.mTotal = obj.mSaving + obj.mChecking;

	return input;
}

/*
* Pre: an account and an input file stream
* Post: the input file stream
* Purpose: define all of the contents of the account as formatted
*/
ifstream& operator>>(ifstream& input, Account& obj)
{
	ifstream finSave, finCheck;
	string savings, checking, test;

	//get all data from inside input
	getline(input, obj.mAccountNum);
	getline(input, obj.mSSN);
	getline(input, obj.mName);
	getline(input, obj.mAddress);
	getline(input, obj.mPhoneNumber);

	string saveFile = obj.mAccountNum + SAVINGS_SUFFIX;
	string checkFile = obj.mAccountNum + CHECKING_SUFFIX;

	finSave.open(saveFile);
	finCheck.open(checkFile);

	//check to see if files opened properly
	if (finSave.fail() || finCheck.fail())
		cout << "Error opening savings and checking files" << endl;
	else
	{
		getline(finSave, savings);
		obj.mSaving = stod(savings);
		getline(finCheck, checking);
		obj.mChecking = stod(checking);
	}

	return input;
}


/*
* Pre: an account and a string
* Post: a boolean
* Purpose: see if the contents of the string are the same as the SSN of the account
*/
bool operator==(const string &lhs, const Account &rhs)
{
	return lhs == rhs.mAccountNum;
}

/*
* Pre: an account and a string
* Post: a boolean
* Purpose: see if the contents of the string aren't the same as the SSN of the account
*/
bool operator!=(const string &lhs, const Account &rhs)
{
	return lhs != rhs.mAccountNum;
}
