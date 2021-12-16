/***        Author:  Tempest Hopp
   *         Class:  CSI-281-01
   *    Assignment:  PA2 part 4
   * Date Assigned:  9/28/21
   *      Due Date:  10/5/21
   *      Filename:  sortingFunctions.h
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

#pragma once
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

//sorts

template <typename T>
/*
* Pre: a list of type T, a size
* Post: none
* Purpose: sort the list using bubble sort
*/
void bubbleSort(T list[], int size)
{
	int iterations = 0;
	bool swapHappened = false;
	do
	{
		swapHappened = false;
		for (int i = 0; i < size - iterations - 1; i++)
		{
			if (list[i] < list[i + 1]);
			else
			{
				swapHappened = true;
				swap(list[i], list[i + 1]);
			}
		}
		iterations++;
	} while (swapHappened);
}

template <typename T>
/*
* Pre: a list of type T, a size
* Post: none
* Purpose: sort the list using insertion sort
*/
void insertionSort(T list[], int size)
{
	T value;
	int i, j;
	for (i = 1; i < size; i++)
	{
		value = list[i];
		j = i - 1;
		while (j >= 0 && list[j] > value)
		{
			list[j + 1] = list[j];
			j--;
		} 
		list[j + 1] = value;
	}
}

template <typename T>
/*
* Pre: a list of type T, the lower bound, middle, and upper bound indices of the list
* Post: none
* Purpose: merge a list back together
*/
void merge(T list[], int lowerBound, int middle, int upperBound)
{
	int size1 = middle - lowerBound + 1;
	int size2 = upperBound - middle;

	T* temp1 = new T[size1];
	T* temp2 = new T[size2];
	int i, j;

	for (i = 0; i < size1; i++)
	{
		temp1[i] = list[lowerBound + i];
	}

	for (j = 0; j < size2; j++)
	{
		temp2[j] = list[middle + j + 1];
	}

	i = 0;
	j = i;
	int k;

	for (k = lowerBound; k < upperBound && i < size1 && j < size2; k++)
	{
		if (temp1[i] <= temp2[j])
		{
			list[k] = temp1[i];
			i++;
		}
		else
		{
			list[k] = temp2[j];
			j++;
		}
	}

	while (i < size1)
	{
		list[k] = temp1[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		list[k] = temp2[j];
		j++;
		k++;
	}

	delete [] temp1;
	delete [] temp2;
}

template <typename T>
/*
* Pre: a list of type T, the lower and upper bound indices of the list
* Post: none
* Purpose: sort the list using merge sort
*/
void mergeSort(T list[], const int &lowerBound, const int &upperBound)
{
	if (lowerBound < upperBound)
	{
		int middle = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, middle);
		mergeSort(list, middle + 1, upperBound);
		merge(list, lowerBound, middle, upperBound);
	}
}

template <typename T>
/*
* Pre: a list of type T, the lower and upper bound indices of the list
* Post: none
* Purpose: sort the list using quick sort
*/
void quickSort(T list[], const int &lowerBound, const int &upperBound)
{
	int i = lowerBound;
	int j = upperBound;

	T pivot = list[(lowerBound + upperBound) / 2];

	while (i <= j)
	{
		while (list[i] < pivot)
			i++;

		while (list[j] > pivot)
			j--;

		if (i <= j)
		{
			swap(list[i], list[j]);
			i++;
			j--;
		}
	}

	if (lowerBound < j)
		quickSort(list, lowerBound, j);

	if (i < upperBound)
		quickSort(list, i, upperBound);
}

template <typename T>
/*
* Pre: a list of type T, a size
* Post: none
* Purpose: sort the list using selection sort
*/
void selectionSort(T list[], int size)
{
	int index = 0;
	for (int i = 0; i < size - 1; i++)
	{
		index = i;
		for (int k = i + 1; k < size; k++)
		{
			if (list[k] < list[index])
			{
				index = k;
			}
		}
		swap(list[i], list[index]);
	}
}

template <typename T>
/*
* Pre: a list of type T, a size
* Post: none
* Purpose: sort the list using shell sort
*/
void shellSort(T list[], int size)
{
	int gap = size / 2;
	do
	{
		for (int i = 0; i < size - gap; i++)
		{
			if (list[i] > list[i + gap])
				swap(list[i], list[i + gap]);
		}
		gap /= 2;
	} while (gap > 0);
	bubbleSort(list, size);
}