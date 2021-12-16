/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA3
* Date Assigned:  10/22/21
*      Due Date:  10/29/21
*      Filename:  stub.cpp
*
* Description:
*    Implementation of a doubly linked list
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

#include <iostream>
#include "doublyLinkedList.h"

using namespace std;

int main()
{
   DoublyLinkedList<int> *list;
   int             i;

   list = new DoublyLinkedList<int>;

   cout << "Testing isEmpty, expecting true, received " 
        << (list->isEmpty() ? "true" : "false") << endl;

   for (i = 0; i <= 10; i += 2)
   {
      list->insert(i);
      list->display();
   }

   for (i = 1; i < 10; i += 2)
   {
      list->insert(i);
      list->display();
   }

   cout << "Display list in reserve:  ";
   list->displayInReverse();
   cout << endl;

   cout << "Testing isEmpty, expecting false, received " 
        << (list->isEmpty() ? "true" : "false") << endl;

   cout << "Testing isExist(6), expecting true, received "
        << (list->isExist(6) ? "true" : "false") << endl;

   cout << "Testing isExist(20), expecting false, received "
        << (list->isExist(20) ? "true" : "false") << endl;


   for (i = 0; i <= 12; i += 2)
   {
      cout << "Removing " << i << ", received " << list->remove(i) << endl;
      list->display();
   }

   for (i = 1; i < 10; i++)
   {
      cout << "Removing " << i << ", received " << list->remove(i) << endl;
      list->display();
   }

   delete list;

   system("pause");

   return 0;
}