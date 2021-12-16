/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Manager.h
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
#include "Cashier.h"

const string DAILY_REPORTS = "reports.txt";
const int MAX_SIZE = 100;

class Manager : public Cashier
{
    private: 
        Cashier* mCashiers;
        int mSize;
    public:
        //constructor
        Manager();

        //class specific functions
        void reloadCashiers();
        bool isCashierExists(string name);

        //manager operations
        void hireCashier();
        void fireCashier();
        void generateReport();
        void searchCashierInfo();
        void shutDown();
        void updateCashierInfo();
};

