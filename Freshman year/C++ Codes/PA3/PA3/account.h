/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  account.h
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
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

const string OUTPUT_FILE = "output.txt";
const string INPUT_FILE = "input.txt";
const string SAVINGS_SUFFIX = ".sav";
const string CHECKING_SUFFIX = ".chk";

class Account
{
	private:
		string mSSN, mName, mAccountNum, mAddress, mPhoneNumber;
		double mSaving, mChecking, mTotal;
	public:
		//constructors and deconstructors
		Account();
		Account(string accountNum, string ssn, string name, string address, string phoneNumber, double saving, double checking);
		~Account();

		//accessors
		string getAccountNumber();
		string getAddress();
		double getChecking();
		string getName();
		string getPhoneNumber();
		double getSaving();
		string getSSN();
		double getTotal();

		//mutators
		void setAccountNumber(string accountNum);
		void setAddress(string address);
		void setChecking(double checking);
		void setName(string name);
		void setPhoneNumber(string phoneNumber);
		void setSaving(double saving);
		void setSSN(string ssn);

		//member operator overloading
		bool operator==(const Account &rhs);
		bool operator==(const string &rhs);
		bool operator!=(const Account &rhs);
		bool operator!=(const string &rhs);
		bool operator>(const Account &rhs);
		bool operator<(const Account &rhs);

		//friend operator overloading
		friend ostream &operator<<(ostream &output, const Account &obj);
		friend ofstream &operator<<(ofstream &output, const Account &obj);
		friend istream &operator>>(istream &input, Account &obj);
		friend ifstream &operator>>(ifstream &input, Account &obj);
		friend bool operator==(const string &lhs, const Account &rhs);
		friend bool operator!=(const string &lhs, const Account &rhs);

		
};

#endif