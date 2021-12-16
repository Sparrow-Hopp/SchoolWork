/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA4
* Date Assigned:  11/5/21
*      Due Date:  11/16/21
*      Filename:  bst.h
*
* Description:
*    implement a BST
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


#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class BST
{
	private:
      template <typename R>
      struct Node
      {
         R       mData;
         Node<R> *mLeft, *mRight;

         /*      Pre:  None
          *     Post:  This object is initialized using default 
          *            values
          *  Purpose:  To initialize date object
          *****************************************************/
         Node()
         {
            mData  = R();
            mLeft  = NULL;
            mRight = NULL;
         }

         /*      Pre:  None
          *     Post:  This object is initialized using specified
          *            data
          *  Purpose:  To initialize date object
          *****************************************************/
         Node(R data)
         {
            mData  = data;
            mLeft  = NULL;
            mRight = NULL;
         }

         /*      Pre:  None
          *     Post:  This object is initialized using specified
          *            data with the specified children attached
          *  Purpose:  To initialize date object
          *****************************************************/
         Node(R data, Node<R> *left, Node<R> *right)
         {
            mData  = data;
            mLeft  = left;
            mRight = right;
         }
      };

		Node<T> *mRootNode;

      BST(T data, Node<T> *left, Node<T> *right);

		void destroySubtree(Node<T> *&node);
		void displayInOrder(Node<T> *node);
		void displayPreOrder(Node<T> *node);
		void displayPostOrder(Node<T> *node);
      void displayTree(Node<T> *node, int tab);
		void insert(Node<T> *&node, const T &data);
		void makeDeletion(Node<T> *&node);
		void remove(Node<T> *&node, const T &searchKey);

	public:
		BST();
		~BST();

      bool bfs(T searchKey);
      void clear();
      bool dfs(T searchKey, Node<T>* node);
      bool dfs(T searchKey);
      int getHeight(Node<T>* node);
      int  getHeight();
		void insert(T data);
      bool isEmpty();
		bool isExists(T searchKey);
      int leavesCount(Node<T>* node);
      int  leavesCount();
      int nodesCount(Node<T>* node);
      int  nodesCount();
		void remove(T searchKey);
      void printPath(T searchKey, Node<T>* node);
      void printPath(T searchKey);
		void showInOrder();
		void showPreOrder();
		void showPostOrder();
      void showTree();
};


/*      Pre:  None
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::BST()
{
	mRootNode = NULL;
}


/*      Pre:  data, left pointer and right pointer
 *     Post:  The root node of the BST is initialized to the
 *            new root node with both left and right child
 *  Purpose:  Constructor
 **************************************************************/
template <typename T>
BST<T>::BST(T data, Node<T> *left, Node<T> *right)
{
   Node<T> *newNode;

   newNode = new Node<T>(data, left, right);
   if (newNode != NULL)
	   mRootNode = newNode;
}


/*      Pre:  The BST is instantiated 
 *     Post:  The root node of the BST is initialized to NULL
 *  Purpose:  Default constructor
 **************************************************************/
template <typename T>
BST<T>::~BST()
{
   destroySubtree(mRootNode);

   mRootNode = NULL;
}


/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using breadth-first search
 **************************************************************/
template <typename T>
bool BST<T>::bfs(T searchKey)
{
    bool found = false;
    Node<T>* current = mRootNode;
    queue<Node<T>*> temp;
    temp.push(mRootNode);
    while (!temp.empty())
    {
        current = temp.front();
        temp.pop();
        if (current->mData == searchKey)
        {
            found = true;
            break;
        }
        else
        {
            if (current->mLeft != NULL)
                temp.push(current->mLeft);
            if (current->mRight != NULL)
                temp.push(current->mRight);
        }
    }
    return found;
}


/*      Pre:  The BST is instantiated
 *     Post:  The entire BST is deleted
 *  Purpose:  To clear the entire BST
 **************************************************************/
template <typename T>
void BST<T>::clear()
{
   destroySubtree(mRootNode);

   mRootNode = NULL;
}


/*      Pre:  A node within the BST
 *     Post:  All the subtree branching from the node (including
 *            the node) is deleted
 *  Purpose:  To delete a subtree
 **************************************************************/
template <typename T>
void BST<T>::destroySubtree(Node<T> *&node)
{
   if (node == NULL)
      return;

   destroySubtree(node->mLeft);
   destroySubtree(node->mRight);

   delete node;

   node = NULL;
}

/*      Pre:  A search key and the current node
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchkey, Node<T>* node)
{
    if (node == NULL)
        return false;
    if (node->mData == searchkey)
        return true;
    else
        return (dfs(searchkey, node->mLeft) || dfs(searchkey, node->mRight));
}

/*      Pre:  A search key
 *     Post:  True is return is the search key is found in the
 *            BST, otherwise false
 *  Purpose:  Searching the tree using depth-first search
 **************************************************************/
template <typename T>
bool BST<T>::dfs(T searchKey)
{
    return dfs(searchKey, mRootNode);
}

/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A private function that display the entire BST
 *            using in-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayInOrder(Node<T> *node)
{
   if (node != NULL)
   {
      displayInOrder(node->mLeft);
      cout << node->mData << " ";
      displayInOrder(node->mRight);
   }
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A private function that display the entire BST
 *            using pre-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPreOrder(Node<T> *node)
{
    if (node != NULL)
    {
        cout << node->mData << " ";
        displayPreOrder(node->mLeft);
        displayPreOrder(node->mRight);
    }
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A private function that display the entire BST
 *            using post-order format.
 **************************************************************/
template <typename T>
void BST<T>::displayPostOrder(Node<T> *node)
{
    if (node != NULL)
    {
        displayPostOrder(node->mLeft);
        displayPostOrder(node->mRight);
        cout << node->mData << " ";
    }
}


/*      Pre:  A node within a tree
 *     Post:  The entire BST is displayed
 *  Purpose:  A private function that display the entire BST
 **************************************************************/
template <typename T>
void BST<T>::displayTree(Node<T> *node, int tab)
{
    if (node != NULL)
    {
        for (int i = 0; i < tab; i++)
            cout << "\t";
        cout << node->mData << endl;
        displayTree(node->mLeft, tab + 1);
        displayTree(node->mRight, tab + 1);
    }
}


/*      Pre:  The current node
 *     Post:  The height of a tree is returned
 *  Purpose:  To compute the longest branch within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight(Node<T>* node)
{
    if (node == NULL)
        return 0;
    int leftHeight = getHeight(node->mLeft);
    int rightHeight = getHeight(node->mRight);
    if (leftHeight > rightHeight)
        return 1 + leftHeight;
    else
        return 1 + rightHeight;
}

/*      Pre:  None
 *     Post:  The height of a tree is returned
 *  Purpose:  To compute the longest branch within the BST
 **************************************************************/
template <typename T>
int BST<T>::getHeight()
{
   return getHeight(mRootNode);
}


/*      Pre:  A data to insert into a BST
 *     Post:  A new data is inserted into a BST
 *  Purpose:  To insert a new value into a BST
 **************************************************************/
template <typename T>
void BST<T>::insert(T data)
{
	insert(mRootNode, data);
}


/*      Pre:  A node within a tree and the value to insert
 *     Post:  The new value is inserted into the BST
 *  Purpose:  A private function that insert a new data into a
 *            BST.  BST does not allow duplication of value. 
 *            Hence, a duplicated value will not be inserted
 **************************************************************/
template <typename T>
void BST<T>::insert(Node<T> *&node, const T &data)
{
   if (node == NULL)
   {
      node = new Node<T>(data);
      return;
   }

   if (node->mData == data)
      return;
   else if (node->mData > data)
      insert(node->mLeft, data);
   else
      insert(node->mRight, data);
}


/*      Pre:  None
 *     Post:  True if the BST is empty, otherwise false
 *  Purpose:  To determine if the BST is empty
 **************************************************************/
template <typename T>
bool BST<T>::isEmpty()
{
   return (mRootNode == NULL);
}


/*      Pre:  A search key
 *     Post:  True is return if the search key existed in the
 *            BST, otherwise false
 *  Purpose:  To search if a search key exists in the BST using
 *            the typical binary tree search
 **************************************************************/
template <typename T>
bool BST<T>::isExists(T searchKey)
{
   Node<T> *tmp;
   bool     found = false;

   tmp = mRootNode;

   while (tmp != NULL && !found)
   {
      // 1. match
      if (tmp->mData == searchKey)
         found = true;

      // 2. go left
      else if (tmp->mData > searchKey)
         tmp = tmp->mLeft;

      // 3. go right
      else
         tmp = tmp->mRight;
   }

   return found;   
}

/*      Pre:  The current node
 *     Post:  The number of leave nodes is returned
 *  Purpose:  To determine the number of leave nodes in the BST
 **************************************************************/
template<typename T>
inline int BST<T>::leavesCount(Node<T>* node)
{
    if (node == NULL)
        return 0;
    if (node->mLeft != NULL || node->mRight != NULL)
        return leavesCount(node->mLeft) + leavesCount(node->mRight);
    return 1 + leavesCount(node->mLeft) + leavesCount(node->mRight);
    
}

/*      Pre:  None
 *     Post:  The number of leave nodes is returned
 *  Purpose:  To determine the number of leave nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::leavesCount()
{
    return leavesCount(mRootNode);
}



/*      Pre:  A node within the BST
 *     Post:  The node is deleted from the BST
 *  Purpose:  A private function that delete the node from the
 *            BST.  If the node has only one child, then the
 *            child will serve as the new root node for that
 *            branch.  However, if the node has two children,
 *            then the right child will serve as the new root
 *            node for the branch.
 **************************************************************/
template <typename T>
void BST<T>::makeDeletion(Node<T> *&node)
{
   Node<T> *toBeDeleted, *attachPoint;

   toBeDeleted = node;

   // case 1, only left child exists
   if (node->mRight == NULL)
      node = node->mLeft;

   // case 2, only right child exists
   else if (node->mLeft == NULL)
      node = node->mRight;

   // case 3, both children exist
   else
   {
      attachPoint = node->mRight;

      while (attachPoint->mLeft != NULL)
         attachPoint = attachPoint->mLeft;

      attachPoint->mLeft = node->mLeft;

      node = node->mRight;
   }

   toBeDeleted->mLeft = NULL;
   toBeDeleted->mRight = NULL;
   delete toBeDeleted;
}


/*      Pre:  The current node
 *     Post:  The number of nodes is returned
 *  Purpose:  To determine the number of nodes in the BST
 **************************************************************/
template<typename T>
inline int BST<T>::nodesCount(Node<T>* node)
{
    if (node == NULL)
        return 0;
    return 1 + nodesCount(node->mLeft) + nodesCount(node->mRight);
}

/*      Pre:  None
 *     Post:  The number of nodes is returned
 *  Purpose:  To determine the number of nodes in the BST
 **************************************************************/
template <typename T>
int BST<T>::nodesCount()
{
   return nodesCount(mRootNode);
}


/*      Pre:  A search key and the current node
 *     Post:  The path from the root node to the search key is
 *            displayed on the screen or an error message
 *            indicating the search key does not exist
 *  Purpose:  To display the path from the root node to the
 *            search key is displayed on the screen.  If the
 *            search key does not exist in the BST, a message
 *            indicating the search key does not exist in the
 *            BST
 **************************************************************/
template<typename T>
void BST<T>::printPath(T searchKey, Node<T>* node)
{
    if (node != NULL)
    {
        cout << node->mData << endl;
        if (node->mData == searchKey)
            cout << "Reached desired value" << endl;
        else
        {
            if (node->mData > searchKey)
                printPath(searchKey, node->mLeft);
            else
                printPath(searchKey, node->mRight);
        }
    }
    else
        cout << "Value is not in tree" << endl;
}

/*      Pre:  A search key and the current node
 *     Post:  The path from the root node to the search key is
 *            displayed on the screen or an error message
 *            indicating the search key does not exist
 *  Purpose:  To display the path from the root node to the
 *            search key is displayed on the screen.  If the 
 *            search key does not exist in the BST, a message
 *            indicating the search key does not exist in the
 *            BST
 **************************************************************/
template <typename T>
void BST<T>::printPath(T searchKey)
{
    printPath(searchKey, mRootNode);
}


/*      Pre:  A search key
 *     Post:  The search key is removed from the BST
 *  Purpose:  To remove a value from a BST
 **************************************************************/
template <typename T>
void BST<T>::remove(T searchKey)
{
	remove(mRootNode, searchKey);
}


/*      Pre:  A node within the BST and a search key
 *     Post:  The search key is removed from the BST if the 
 *            value exists
 *  Purpose:  A private function that to remove a value from a
 *            BST recursively.  This function will find the node
 *            where the value occur.  Once the node is found,
 *            call makeDeletion to complete the process.
 **************************************************************/
template <typename T>
void BST<T>::remove(Node<T>*& node, const T& searchKey)
{
   if (node == NULL)
      return;

   // 1. match
   if (node->mData == searchKey)
      makeDeletion(node);

   // 2. go left
   else if (node->mData > searchKey)
      remove(node->mLeft, searchKey);

   // 3. go right
   else
      remove(node->mRight, searchKey);
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using in-order format
 *  Purpose:  A function that display the entire BST using
 *            in-order format.  This function will call
 *            displayInOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showInOrder()
{
   if (mRootNode == NULL)
      cout << "Empty Tree\n";
   else
	   displayInOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using pre-order format
 *  Purpose:  A function that display the entire BST using
 *            pre-order format.  This function will call
 *            displayPreOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPreOrder()
{
   if (mRootNode == NULL)
      cout << "Empty Tree\n";
   else
   	displayPreOrder(mRootNode); 
}


/*      Pre:  None
 *     Post:  The entire BST is displayed using post-order format
 *  Purpose:  A function that display the entire BST using
 *            post-order format.  This function will call
 *            displayPostOrder to complete the process
 **************************************************************/
template <typename T>
void BST<T>::showPostOrder()
{
   if (mRootNode == NULL)
      cout << "Empty Tree\n";
   else
   	displayPostOrder(mRootNode);
}


/*      Pre:  None
 *     Post:  The entire BST is displayed
 *  Purpose:  A function that display the entire BST.  This
 *            function will call displayTree to complete the
 *            process
 **************************************************************/
template <typename T>
void BST<T>::showTree()
{
    if (mRootNode == NULL)
        cout << "Empty Tree" << endl;
    else
        displayTree(mRootNode, 0);
}

#endif