/* ***       Author:  Wei Kian Chen with students in CSI-281
     *  Last Update:  October 25, 2021
     *        Class:  CSI-281
     *     Filename:  queue.h
     *
     *  Description:
     *      This is the template queue definition.
     *  
     *  Certification of Authenticity:
     *     I certify that this assignment is entirely own work.
     ******************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <typename T>
class Queue {
   private:
      template <typename R>
      struct Node
      {
         R       mData;
         Node<R> *mNext;

         /*      Pre:  None
          *     Post:  This object is initialized using default values
          *  Purpose:  To initialize node object
          *************************************************************/
         Node()
         {
            mData = R();
            mNext = NULL;
         }

         /*      Pre:  None
          *     Post:  This object is initialized using specified data
          *  Purpose:  To initialize node object
          *************************************************************/
         Node(R data)
         {
            mData = data;
            mNext = NULL;
         }
      };

      Node<T> *mFront, *mRear;
      int     mCount;

   public:
      Queue();
      ~Queue();

      int  getCount();

      void clear();
      T    dequeue();
      void display();
      void enqueue(T data);
      bool isEmpty();
      bool isExist(T searchKey);
};


/*      Pre:  The queue is instantiated
 *     Post:  Both mFront and mRear are initialized to NULL and mCount
 *            is set to zero 
 *  Purpose:  To initialize queue object
 *********************************************************************/
template <typename T>
Queue<T>::Queue()
{
   mFront = NULL;
   mRear  = NULL;
   mCount = 0;
}


/*      Pre:  The queue is instantiated 
 *     Post:  The queue is removed and both mFront and mRear are
 *            reset to NULL and mCount is reset to zero 
 *  Purpose:  To clear up a queue object
 *********************************************************************/
template <typename T>
Queue<T>::~Queue()
{
   while (!isEmpty())
      dequeue();
}


/*      Pre:  The queue is instantiated
 *     Post:  The count for the queue object is returned 
 *  Purpose:  To retrieve the count for a queue object
 *********************************************************************/
template <typename T>
int Queue<T>::getCount()
{
   return mCount;
}


/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is cleared
 *  Purpose:  To clear the entire queue object
 *********************************************************************/
template <typename T>
void Queue<T>::clear()
{
   while (!isEmpty())
      dequeue();
}


/*      Pre:  The queue is instantiated
 *     Post:  The data for the object in the front of the queue is
 *            returned and the node is removed 
 *  Purpose:  To retrieve the data in the first node in the queue and
 *            delete the node
 *********************************************************************/
template <typename T>
T Queue<T>::dequeue()
{
   T       data = T();
   Node<T> *tmp;

   if (!isEmpty())
   {
      tmp = mFront;

      mFront = tmp->mNext;
      if (mFront == NULL)
         mRear = NULL;

      tmp->mNext = NULL;
      data = tmp->mData;
      
      delete tmp;
   
      mCount--;
   }

   return data;
}


/*      Pre:  The queue is instantiated
 *     Post:  The entire queue is displayed on the screen
 *  Purpose:  To display the entire queue from the front to the back
 *********************************************************************/
template <typename T>
void Queue<T>::display()
{
   Node<T> *tmp;

   if (isEmpty())
      cout << "Empty Queue\n";
   else
   {
      tmp = mFront;

      while (tmp != NULL)
      {
         cout << tmp->mData << " ";
         tmp = tmp->mNext;
      }
      cout << endl;
   }
}


/*      Pre:  The queue is instantiated
 *     Post:  A new node is added at the end of the queue
 *  Purpose:  To add a new data to the queue
 *********************************************************************/
template <typename T>
void Queue<T>::enqueue(T data)
{
   Node<T> *newNode;

   newNode = new Node<T>(data);
   if (newNode == NULL)
   {
      cerr << "System Error:  Insufficient Space to Generate Another Node!!\n";
      return;
   }

   if (mFront == NULL)
   {
      mFront = newNode;
      mRear = newNode;
   }
   else
   {
      mRear->mNext = newNode;
      mRear = newNode;
   }

   mCount++;
}


/*      Pre:  The queue is instantiated
 *     Post:  True if the queue is empty, otherwise false
 *  Purpose:  To determine if the queue is empty
 *********************************************************************/
template <typename T>
bool Queue<T>::isEmpty()
{
   return mCount == 0;
}


/*      Pre:  The queue is instantiated and a searchKey is available
 *     Post:  True if the searchKey existed in the queue, 
 *            otherwise false
 *  Purpose:  To determine if a value existed in the queue
 *********************************************************************/
template <typename T>
bool Queue<T>::isExist(T searchKey)
{
   bool    found = false;
   Node<T> *tmp;

   if (!isEmpty())
   {
      tmp = mFront;

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


#endif