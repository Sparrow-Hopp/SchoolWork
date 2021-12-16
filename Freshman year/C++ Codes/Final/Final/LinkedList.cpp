/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Final
   * Date Assigned:  April 5, 2021
   *      Due Date:  April 30, 2021, 17:00
   *      Filename:  LinkedList.cpp
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

#include "linkedList.h"



/*
* Pre: none
* Post: none
* Purpose: define the node with the default values
*/
LinkedList::Node::Node()
{
    mNext = NULL; // indicate it is not pointing to anywhere
}

/*
* Pre: a double and a string
* Post: none
* Purpose: define the node with the given values
*/
LinkedList::Node::Node(double price, string name)
{
    mName = name;
    mPrice = price;
    mNext = NULL;
}

/*
* Pre: none
* Post: none
* Purpose: define the linked list with the default values
*/
LinkedList::LinkedList()
{
    mHead = NULL;
    mTail = NULL;
    mCount = 0;
}


// remove all the nodes in the list

/*
* Pre: none
* Post: none
* Purpose: remove all nodes in the list
*/
LinkedList::~LinkedList()
{
    clear();
}

//accessors and modifiers

/*
* Pre: none
* Post: int
* Purpose: get the count variable
*/
int LinkedList::getCount()
{
    return mCount;
}

/*
* Pre: int
* Post: string
* Purpose: get the name of the item at the given node
*/
string LinkedList::getName(int index)
{
    int i;
    Node* tmp;

    if (index < 0 || index >= mCount)
        return "";
    else
    {
        tmp = mHead;
        for (i = 0; i < index; i++)
            tmp = tmp->mNext;

        return tmp->mName;
    }
}

/*
* Pre: int
* Post: double
* Purpose: get the price of the item at the given node
*/
double LinkedList::getPrice(int index)
{
    int i;
    Node* tmp;

    if (index < 0 || index >= mCount)
        return -1;
    else
    {
        tmp = mHead;
        for (i = 0; i < index; i++)
            tmp = tmp->mNext;

        return tmp->mPrice;
    }
}

/*
* Pre: int and string
* Post: none
* Purpose: change the name of the given node
*/
void LinkedList::setName(int index, string name)
{
    int i;
    Node* tmp;

    if (index >= 0 && index < mCount)
    {
        tmp = mHead;
        for (i = 0; i < index; i++)
            tmp = tmp->mNext;

        remove(tmp->mPrice, tmp->mName);
        insert(tmp->mPrice, name);
        //tmp->mData = data;
    }
}

/*
* Pre: int and double
* Post: none
* Purpose: change the price of the given node
*/
void LinkedList::setPrice(int index, double price)
{
    int i;
    Node* tmp;

    if (index >= 0 && index < mCount)
    {
        tmp = mHead;
        for (i = 0; i < index; i++)
            tmp = tmp->mNext;

        remove(tmp->mPrice, tmp->mName);
        insert(price, tmp->mName);
        //tmp->mData = data;
    }
}

//other methods

/*
* Pre: none
* Post: none
* Purpose: clear the contents of the list
*/
void LinkedList::clear()
{
    Node* toBeDeleted;

    toBeDeleted = mHead;
    while (mHead != NULL)
    {
        mHead = mHead->mNext;
        toBeDeleted->mNext = NULL;
        delete toBeDeleted;
        toBeDeleted = mHead;
    }

    mTail = NULL;
    mCount = 0;
}

/*
* Pre: none
* Post: none
* Purpose: display the contents of the linked list to the screen
*/
void LinkedList::display()
{
    Node* tmp;

    if (mHead == NULL)
        cout << "The list is empty\n";
    else
    {
        int count = 1;
        tmp = mHead;
        while (tmp != NULL)
        {
            cout << count++ << ": " << tmp->mName << " " << tmp->mPrice << endl;
            tmp = tmp->mNext;
        }
        cout << endl;
    }
}


// inserting into the list as sorted

/*
* Pre: double and string
* Post: bool
* Purpose: insert a new node into the appropriate slot in the sorted list
*/
bool LinkedList::insert(double price, string name)
{
    Node* newNode, * oneBefore = NULL,
        * tmp = NULL;

    // create a new node for the data
    newNode = new Node(price, name);
    // check if the node is created
    if (newNode == NULL)
        return false;

    // 1. the list is empty
    if (mHead == NULL)  // mCount == 0
    {
        mHead = newNode;
        mTail = newNode;
    }
    else
    {
        // 2. adding at the head
        if (price <= mHead->mPrice)
        {
            // pointing the next of newNode to mHead
            newNode->mNext = mHead;
            // relocating mHead to newNode, newNode is the new head
            mHead = newNode;
        }

        // 3. adding at the tail
        else if (price >= mTail->mPrice)
        {
            // connecting the newNode next to mTail
            mTail->mNext = newNode;
            // relocating mTail to newNode, mTail is the last node
            mTail = newNode;
        }

        // 4. adding at the middle
        else
        {
            // setting tmp to the 2nd node
            tmp = mHead->mNext;
            // setting oneBefore to the 1st ndoe
            oneBefore = mHead;
            // traverse the list while data > tmp->mData
            while (price > tmp->mPrice)
            {
                oneBefore = tmp;
                tmp = tmp->mNext;
            }
            // inserting newNode in between oneBefore and tmp
            oneBefore->mNext = newNode;
            newNode->mNext = tmp;
        }
    }

    mCount++;
    return true;
}

/*
* Pre: none
* Post: bool
* Purpose: check to see if the list is empty
*/
bool LinkedList::isEmpty()
{
    return mCount == 0;
}

/*
* Pre: double
* Post: bool
* Purpose: check to see if the given node exists
*/
bool LinkedList::isExist(double searchKey, string name)
{
    bool existed = false;
    Node* tmp;

    tmp = mHead;
    while (tmp != NULL)
    {
        if (tmp->mPrice == searchKey && tmp->mName == name)
        {
            existed = true;
            break;
        }
        tmp = tmp->mNext;
    }

    return existed;
}

/*
* Pre: double and string
* Post: bool
* Purpose: remove the given node from the list
*/
bool LinkedList::remove(double searchKey, string name)
{
    bool deleted = false;
    Node* toBeDeleted, * tmp, * oneBefore;

    // 1. the list is empty
    if (mHead != NULL)
    {
        // 2. deleting at the head
        if (mHead->mPrice == searchKey && mHead->mName == name)
        {
            toBeDeleted = mHead;
            mHead = mHead->mNext;
            toBeDeleted->mNext = NULL;

            delete toBeDeleted;
            mCount--;

            // remove the only node in the list, set tail to NULL
            if (mCount == 0) // mHead == NULL
                mTail = NULL;

            deleted = true;
        }
        else
        {
            tmp = mHead->mNext;
            oneBefore = mHead;
            while (tmp != NULL)
            {
                if (tmp->mPrice == searchKey)
                    break;

                oneBefore = tmp;
                tmp = tmp->mNext;
            }

            if (tmp != NULL)
            {
                toBeDeleted = tmp;

                // 3. deleting at the tail
                if (tmp == mTail)
                {
                    mTail = oneBefore;
                    mTail->mNext = NULL;
                }
                // 4. deleting at the middle
                else
                    oneBefore->mNext = tmp->mNext;

                toBeDeleted->mNext = NULL;
                delete toBeDeleted;
                mCount--;
                deleted = true;
            }
        }
    }

    return deleted;
}

/*
* Pre: int
* Post: int
* Purpose: get the price of the given node
*/
int LinkedList::operator[](int index)
{
    return getPrice(index);
}