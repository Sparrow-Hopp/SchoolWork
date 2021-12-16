/***        Author:  Tempest Hopp
   *         Class:  CSI-281-01
   *    Assignment:  PA2 part 4
   * Date Assigned:  9/28/21
   *      Due Date:  10/5/21
   *      Filename:  testSorts.h
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

#include "sortingFunctions.h"
#include "timerSystem.h"
#include <fstream>

//variables
const int RANGE = 100000;
const int HUNDRED = 100;
const int TEN_THOUSAND = 10000;
const int HUNDRED_THOUSAND = 100000;

const string RANDOM = "rand";
const string ASCENDING = "ascending";
const string DESCENDING = "descending";

const string BUBBLE_SORT = "bubble_";
const string INSERTION_SORT = "insertion_";
const string SELECTION_SORT = "selection_";
const string SHELL_SORT = "shell_";
const string QUICK_SORT = "quick_";
const string MERGE_SORT = "merge_";

const string FILE_ENDING = ".txt";

TimerSystem timer;

int hundredList[HUNDRED];
int tenThousandList[TEN_THOUSAND];
int millionList[HUNDRED_THOUSAND];

ofstream fout;

//filling functions

/*
* Pre: an int array, an int
* Post: none
* Purpose: Take the sorted array and put its contents into descending order
* */
void fillDescending(int list[], int size)
{
	for (int i = 0; i < size / 2; i++)
		swap(list[i], list[size - 1 - i]);
}

/*
* Pre: an int array, an int
* Post: none
* Purpose: Take the array and fill it with random values
* */
void fillRandom(int list[], int size)
{
	srand(unsigned(time(NULL)));
	for (int i = 0; i < size; i++)
		list[i] = rand() % RANGE;
}

//test functions

/*
* Pre: none
* Post: none
* Purpose: to test the speed of bubble sort on different sizes and kinds of arrays
*/
void testBubbleSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(BUBBLE_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	bubbleSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(BUBBLE_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	bubbleSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(BUBBLE_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	bubbleSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	bubbleSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}

/*
* Pre: none
* Post: none
* Purpose: to test the speed of insertion sort on different sizes and kinds of arrays
*/
void testInsertionSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(INSERTION_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	insertionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(INSERTION_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	insertionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(INSERTION_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	insertionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	insertionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}

/*
* Pre: none
* Post: none
* Purpose: to test the speed of merge sort on different sizes and kinds of arrays
*/
void testMergeSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(MERGE_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	mergeSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(MERGE_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	mergeSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(MERGE_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	mergeSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	mergeSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}

/*
* Pre: none
* Post: none
* Purpose: to test the speed of quick sort on different sizes and kinds of arrays
*/
void testQuickSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(QUICK_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	quickSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(QUICK_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	quickSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(QUICK_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	quickSort(hundredList, 0, HUNDRED - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(tenThousandList, 0, TEN_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	quickSort(millionList, 0, HUNDRED_THOUSAND - 1);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}

/*
* Pre: none
* Post: none
* Purpose: to test the speed of selection sort on different sizes and kinds of arrays
*/
void testSelectionSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(SELECTION_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	selectionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(SELECTION_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	selectionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(SELECTION_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	selectionSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	selectionSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}

/*
* Pre: none
* Post: none
* Purpose: to test the speed of shell sort on different sizes and kinds of arrays
*/
void testShellSort()
{
	fout.setf(ios::fixed | ios::showpoint);
	fout.precision(16);

	fout.open(SHELL_SORT + RANDOM + FILE_ENDING);

	fillRandom(hundredList, HUNDRED);
	fillRandom(tenThousandList, TEN_THOUSAND);
	fillRandom(millionList, HUNDRED_THOUSAND);

	//random size sort
	timer.startClock();
	shellSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//switch output files
	fout.close();
	fout.open(SHELL_SORT + ASCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	shellSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	//sort lists into descending order
	fillDescending(hundredList, HUNDRED);
	fillDescending(tenThousandList, TEN_THOUSAND);
	fillDescending(millionList, HUNDRED_THOUSAND);

	//switch output files
	fout.close();
	fout.open(SHELL_SORT + DESCENDING + FILE_ENDING);

	//ascending order sort
	timer.startClock();
	shellSort(hundredList, HUNDRED);
	fout << "The time it takes to sort a list of size " << HUNDRED << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(tenThousandList, TEN_THOUSAND);
	fout << "The time it takes to sort a list of size " << TEN_THOUSAND << " is " << timer.getTime() << endl;

	timer.startClock();
	shellSort(millionList, HUNDRED_THOUSAND);
	fout << "The time it takes to sort a list of size " << HUNDRED_THOUSAND << " is " << timer.getTime() << endl;

	fout.close();
}