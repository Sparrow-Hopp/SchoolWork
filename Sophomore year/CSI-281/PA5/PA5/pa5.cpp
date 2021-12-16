/***        Author:  Tempest Hopp
*         Class:  CSI-281-01
*    Assignment:  PA4
* Date Assigned:  11/5/21
*      Due Date:  11/16/21
*      Filename:  pa5.cpp
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

#include "bst.h"

int main()
{
	BST<int> tree;

	tree.insert(1);
	tree.insert(5);
	tree.insert(3);
	tree.insert(-2);
	tree.insert(9);
	tree.insert(0);
	tree.insert(6);

	tree.showTree();

	cout << "\n\nLooking for 6 using BFS: " << tree.bfs(6) << endl;
	cout << "Looking for -2 using DFS: " << tree.dfs(-2) << endl;
	cout << "The path to find 3 using binary search: " << endl;
	tree.printPath(3);
	cout << "\nThe path to find 19 using binary search: " << endl;
	tree.printPath(19);

	cout << "\n\n\nNumber of nodes: " << tree.nodesCount() << endl;
	cout << "Number of leaves: " << tree.leavesCount() << endl;
	cout << "Height of the tree: " << tree.getHeight() << endl;

	cout << "\n\nTree displayed in preorder notation: ";
	tree.showPreOrder();
	cout << "\nTree displayed in postorder notation: ";
	tree.showPostOrder();

	return 1;
}