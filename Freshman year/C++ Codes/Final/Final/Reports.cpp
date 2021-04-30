#include "Reports.h"

/*
* Pre: ofstream and Day
* Post: ofstream
* Purpose: write the end of day report to the given file
*/
ofstream &operator<<(ofstream &output, Day obj)
{
    output << "Total Sales: " << obj.mTotalSales << endl;
    output << "Total Orders: " << obj.mTotalOrders << endl;
    output << "Total Items Purchased: " << obj.mTotalItems << endl;
    output << "Average Items Per Order: " << obj.mAverageItemsPerOrder << endl << endl << endl;
    return output;
}

