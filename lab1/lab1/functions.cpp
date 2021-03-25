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
#include<iostream>
#include <iomanip>

using namespace std;

/*Pre: a filled array
Post: the array will be displayed
Purpose: display the array in the same format it is ordered*/
void displayArray(int grid[ROWS][COL])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			cout << grid[r][c] << " ";
		}
		cout << endl;//move to the next line in the output after one row is finished
	}
	cout << endl;//add a blank line before the next method call
}

/*Pre: a filled array
Post: the numbers in the array that are divisible by 5 will be displayed
Purpose: display the numbers in the array that are divisible by 5 in the same format it is ordered*/
void displayFives(int grid[ROWS][COL])
{
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			if (grid[r][c] % 5 == 0)
			{
				cout << grid[r][c] << " ";
			}
		}
	}
	cout << endl;//add a blank line before the next method call
}

/*Pre: an empty array
Post: an array filled with random integers from 1-100 inclusive
Purpose: To populate an empty array with random integers from 1-100 inclusive*/
void populateArray(int grid[ROWS][COL])
{
	srand(unsigned(time(NULL)));

	//go row by row and assign a value to each spot in the grid
	for (int r = 0; r < ROWS; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			grid[r][c] = rand() % 101;
		}
	}
	cout << endl;//add a blank line before the next method call
}

/*Pre: an unsorted array
Post: a sorted array based by column
Purpose: Sort each column in the array, with even columns being in descending order and odd columns in ascending order*/
void sortArray(int grid[ROWS][COL])
{
	for (int c = 0; c < COL; c++)
	{
		//sort the array in descending order if it is an even column
		if (c % 2 == 0)
		{
			for (int i = 0; i < COL; i++)
			{
				int index = i;
				int max = grid[index][c];
				for (int r = i; r < ROWS; r++)
				{
					if (grid[r][c] > max)
					{
						index = r;
						max = grid[r][c];
					}

				}
				int temp = grid[index][c];
				grid[index][c] = grid[i][c];
				grid[i][c] = temp;
			}
		}
		//sort the array in ascending order if it is an odd column
		else
		{
			for (int i = COL - 1; i >= 0; i--)
			{
				int index = i;
				int min = grid[i][c];
				for (int r = i; r >= 0; r--)
				{
					if (grid[r][c] < min)
					{
						index = r;
						min = grid[r][c];
					}

				}
				int temp = grid[index][c];
				grid[index][c] = grid[i][c];
				grid[i][c] = temp;
			}
		}
	}
	cout << endl;//add a blank line before the next method call
}

