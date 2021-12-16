/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  LinkedList.h
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

#ifndef LINKED_LIST
#define LINKED_LIST

#include <iostream>
#include <string>

using namespace std;

class LinkedList
{
    struct Node
    {
        string mName;
        double  mPrice;
        Node* mNext;

        Node();
        Node(double price, string name);
    };

private:
    Node* mHead, * mTail;
    int  mCount;

public:
    //constructor and deconstructor
    LinkedList();
    ~LinkedList();

    //accessors and modifiers
    int  getCount();
    string getName(int index);
    double getPrice(int index);
    void setName(int index, string name);
    void setPrice(int index, double price);

    //other methods
    void clear();
    void display();
    bool insert(double price, string name);
    bool isEmpty();
    bool isExist(double searchKey, string name);
    bool remove(double searchKey, string name);

    int operator[](int index);
};

#endif