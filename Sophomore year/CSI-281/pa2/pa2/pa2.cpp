/***        Author:  Tempest Hopp
   *         Class:  CSI-281-01
   *    Assignment:  PA2 part 4
   * Date Assigned:  9/28/21
   *      Due Date:  10/5/21
   *      Filename:  pa2.cpp
   *
   * Description:
   *    Implement a plethora of sorting algorithms using template types and run an analysis on how long they take to run
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

#include "testSorts.h"

int main()
{
	testBubbleSort();
	testInsertionSort();
	testSelectionSort();
	testShellSort();
	testQuickSort();
	testMergeSort();
	return 0;
}