/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  October 25, 2021
     *        Class:  CSI-281
     *     Filename:  stack.h
     *
     *  Description:
     *      This is the template stack definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely own work.
     ******************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <typename T>
class Stack {
   private:
       template <typename R>
       struct Node
       {
          R       mData;
          Node<R> *mNext;

          /*      Pre:  None
           *     Post:  This object is initialized using default values
           *  Purpose:  To initialize node object
           *************************************************************************/
          Node()
          {
             mData = R();
             mNext = NULL;
          }


          /*      Pre:  None
           *     Post:  This object is initialized using specified data
           *  Purpose:  To initialize node object
           *************************************************************************/
          Node(R data)
          {
             mData = data;
             mNext = NULL;
          }
       };

      Node<T> *mTop, *mBottom;
      int     mCount;

   public:
      Stack();
      ~Stack();

      int  getCount();

      void clear();
      void display();
      bool isEmpty();
      bool isExist(T searchKey);
      T peek();
      T    pop();
      void push(T data);
};


/*      Pre:  The stack is instantiated
 *     Post:  Both mTop and mBottom are initialized to NULL and mCount
 *            is set to zero 
 *  Purpose:  To initialize stack object
 *********************************************************************/
template <typename T>
Stack<T>::Stack()
{
   mTop    = NULL;
   mBottom = NULL;
   mCount  = 0;
}


/*      Pre:  The stack is instantiated
 *     Post:  The stack is removed and both mTop and mBottom are
 *            reset to NULL and mCount is reset to zero 
 *  Purpose:  To clear up a stack object
 *********************************************************************/
template <typename T>
Stack<T>::~Stack()
{
   clear();
}


/*      Pre:  The stack is instantiated
 *     Post:  The count for the stack object is returned 
 *  Purpose:  To retrieve the count for a stack object
 *********************************************************************/
template <typename T>
int Stack<T>::getCount()
{
   return mCount;
}


/*      Pre:  The stack is instantiated
 *     Post:  The entire stack is cleared
 *  Purpose:  To clear the entire stack object
 *********************************************************************/
template <typename T>
void Stack<T>::clear()
{
   while (!isEmpty())
      pop();
}


/*      Pre:  The stack is instantiated
 *     Post:  The entire stack is displayed on the screen
 *  Purpose:  To display the entire stack from the top to bottom
 *********************************************************************/
template <typename T>
void Stack<T>::display()
{
   Node<T> *tmp;

   if (isEmpty())
      cout << "Empty Stack\n";
   else
   {
      tmp = mTop;

      while (tmp != NULL)
      {
         cout << tmp->mData << " ";
         tmp = tmp->mNext;
      }
      cout << endl;
   }
}


/*      Pre:  The stack is instantiated
 *     Post:  True if the stack is empty, otherwise false
 *  Purpose:  To determine if the stack is empty
 *********************************************************************/
template <typename T>
bool Stack<T>::isEmpty()
{
   return mCount == 0;
}


/*      Pre:  The stack is instantiated and a searchKey is available
 *     Post:  True if the searchKey existed in the stack, 
 *            otherwise false
 *  Purpose:  To determine if a value existed in the stack
 *********************************************************************/
template <typename T>
bool Stack<T>::isExist(T searchKey)
{
   bool    found = false;
   Node<T> *tmp;

   if (!isEmpty())
   {
      tmp = mTop;

      while (tmp != NULL)
      {
         if (tmp->mData == searchKey)
         {
            found = true;
            break;
         }

         tmp = tmp->mNext;
      }
   }

   return found;
}

/*      Pre:  The stack is instantiated
 *     Post:  The data for the object in the top of the stack is
 *            returned
 *  Purpose:  To retrieve the data in the top node in the stack
 *********************************************************************/
template<typename T>
inline T Stack<T>::peek()
{
    return mTop->mData;
}


/*      Pre:  The stack is instantiated
 *     Post:  The data for the object in the top of the stack is
 *            returned and the node is removed 
 *  Purpose:  To retrieve the data in the top node in the stack and
 *            delete the node
 *********************************************************************/
template <typename T>
T Stack<T>::pop()
{
   T       data = T();
   Node<T> *tmp;

   if (!isEmpty())
   {
      tmp = mTop;

      mTop = tmp->mNext;
      if (mTop == NULL)
         mBottom = NULL;

      tmp->mNext = NULL;
      data = tmp->mData;
      
      delete tmp;

      mCount--;
   }

   return data;
}


/*      Pre:  The stack is instantiated
 *     Post:  A new node is added at the top of the stack
 *  Purpose:  To add a new data to the stack
 *********************************************************************/
template <typename T>
void Stack<T>::push(T data)
{
   Node<T> *newNode;

   newNode = new Node<T>(data);
   if (newNode == NULL)
   {
      cerr << "System Error:  Insufficient Space to Generate Another Node!!\n";
      return;
   }

   newNode->mNext = mTop;
   mTop = newNode;

   if (mBottom == NULL)
      mBottom = newNode;

   mCount++;
}


#endif