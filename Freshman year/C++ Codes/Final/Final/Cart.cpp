/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  Cart.cpp
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

#include "Cart.h"





void Cart::fillAllItems()
{
    mAllItems.clear();
    ifstream fin;
    string name, junk;
    double price;
    fin.open(ITEMS_FILE);
    while (!fin.eof())
    {
        getline(fin, name);
        fin >> price;
        getline(fin, junk);
        mAllItems.insert(price, name);
    }
    fin.close();
}

/*
* Pre: none
* Post: LinkedList
* Purpose: get the linked list of all items
*/
LinkedList Cart::getAllItems()
{
    return mAllItems;
}

/*
* Pre: none
* Post: LinkedList
* Purpose: get the cart
*/
LinkedList Cart::getCart()
{
    return mCurrentCart;
}

/*
* Pre: none
* Post: double
* Purpose: get the total cost of the cart
*/
double Cart::getCost()
{
    return mCost;
}

void Cart::setCost(double cost)
{
    mCost += cost;
}

/*
* Pre: input stream and a linked list
* Post: the input stream
* Purpose: populate the linked list with the items from the given file
*/
ifstream &operator>>(ifstream &input, LinkedList &obj)
{
    input.open(ITEMS_FILE);
    if (input.fail());
    else
    {
        while (!input.eof())
        {
            string name, junk;
            double price;
            getline(input, name);
            input >> price >> junk;
        }
    }
    input.close();
    return input;
}

/*
* Pre: output stream and a linked list
* Post: the output stream
* Purpose: display the contents of the cart to the screen
*/
ostream &operator<<(ostream &out, LinkedList &obj)
{
    out << "";
    obj.display();
    return out;
}
