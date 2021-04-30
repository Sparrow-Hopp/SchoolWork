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
