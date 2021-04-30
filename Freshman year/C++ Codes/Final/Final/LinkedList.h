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