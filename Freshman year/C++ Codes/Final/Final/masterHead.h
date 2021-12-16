/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  masterHead.h
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