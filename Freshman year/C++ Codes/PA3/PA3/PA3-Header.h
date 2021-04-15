/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  PA3
   * Date Assigned:  March 26, 2021
   *      Due Date:  April 5, 2021, 13:00
   *      Filename:  PA3-Header.h
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
#ifndef PA3_HEADER_H
#define PA3_HEADER_H

#include <sstream>
#include <cstdio>
#include <stdio.h>
#include <conio.h>
#include "Teller.h"
#include "Customer.h"

//constant variables
const string TERMINATION_CODE = "verlassen";
const string LOGOUT_CODE = "logout";
const string LOGO_FILE = "Logo.txt";
const string NUMBERS = "0123456789";
const string TELLERS_DATA = "tellers.dat";
const string ACCOUNTS_DATA = "accounts.dat";
const string PHONE_NUMBER_FORMAT = "000 000 0000";
const string SSN_FORMAT = "000-00-0000";
const string ACCOUNT_ENDING = ".chk";
const string DEPOSIT_KEY = "deposit";
const string WITHDRAWAL_KEY = "withdrawal";

//other variables
static Customer customers;
static Teller tellers;

//methods within commonFunctions

void checkTerminationCode(string input);
void checkLogOutCode(string input);
void clearScreen();
bool convertStr2Double(string stringValue, double& value);
void displayLogo();
void displayMessage(int errorCode);
void hub();
string mainMenu();
void systemPause();
void toUpper(string stringValue);

//methods within customerOperations

void addAccount();
void checkBalance(string accountNumber);
void deleteAccount();
void deposit(string accountNumber);
double getCurrentBalance(string accountNumber);
double getAmount(string message);
string inputHub();
void withdrawal(string accountNumber);

bool validAccountNumber(string accountNumber);
bool validPhoneNumber(string phoneNumber);
bool validSSN(string ssn);

//methods within searchOperations

string getAccountNumber();
string getAddress();
string getName();
string getPhoneNumber();
string getSSN();

bool isExistsAccountNumber(string accountNumber);
bool isExistsAddress(string address);
bool isExistsName(string name);
bool isExistsPhoneNumber(string phoneNumber);
bool isExistsSSN(string ssn);

string searchMenu();

//methods within tellerOperations

void getIdPassword(string& id, string& password);
void login();
bool validateLogin(string id, string password);

//methods within updateOperations

//main menu
void updateMenu();

//core update functions
void updateAddress();
void updateName();
void updatePhoneNumber();
void updateSSN();

#endif