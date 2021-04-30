#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

#include "LinkedList.h"
#include "Cart.h"
#include "Reports.h"
#include "Cashier.h"
#include "Manager.h"
using namespace std;


const string CASHIER_LOGINS = "cashier_login.txt";
const string MANAGER_LOGINS = "manager_login.txt";
static Manager manager;

//logins

void getIdPassword(string& id, string& password);
void login();
bool validateCashierLogin(string id, string password);
bool validateManagerLogin(string id, string password);


//hubs
void cashierHub();
void managerHub();