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

