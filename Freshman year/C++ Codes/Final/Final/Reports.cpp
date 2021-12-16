/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Reports.cpp
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

