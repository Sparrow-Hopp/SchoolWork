/***
Author: Tempest Hopp
Class : CSI 240-03
Assignment : lab1
Date Assigned : Feb 4
Due Date : Feb 7 at 1pm
Description :
Display the original array,
2.Count and display the occurrence of thenumbersthat are evenly divisible by 5in the array and 
3.Sort each odd columnof the array in ascending order and even columnin descending order.Once the array is sorted, display the sorted array.
Certification of Authenticity :
I certify that this is entirely my own work, except where I have given fullydocumented references to the work of others.I understand the definitionand
consequences of plagiarismand acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment :
	-Reproduce this assignment and provide a copy to another member of
	academic staff;and /or
	-Communicate a copy of this assignment to a plagiarism checking service
	(which may then retain a copy of this assignment on its database for
		the purpose of future plagiarism checking)
***/
#include "header.h"

using namespace std;

int grid[ROWS][COL];

int main()
{
	//call all methods
	populateArray(grid);
	displayArray(grid);
	displayFives(grid);
	sortArray(grid);
	displayArray(grid);

	return 1;
}