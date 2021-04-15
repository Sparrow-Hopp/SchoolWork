#include "Header.h"


/*
* Pre: the size of the array and a pointer which points to an array of students
* post: none
* purpose: to display the contents of the array which pointer points to
*/
void display(int size, Student *ptr)
{
	for (int i = 0; i < size; i++)
		cout << ptr[i] << endl;//use overloaded method in student
}

/*
* Pre: none
* Post: an integer
* Purpose: ask the user for the size of the array of students
*/
int promptSize()
{
	int size;
	cout << "Please enter the size of the array" << endl;
	cin >> size;
	while (size < 1 || size > MAX_SIZE)//failsafe
	{
		cout << "Invalid size. Please enter a new size" << endl;
		cin >> size;
	}
	return size;
	return 1;
}

/*
* Pre: the size of the array, the name of the input file, and the pointer for the array
* Post: none
* Purpose: populate the array with the data from filename
*/
void populate(int size, string filename, Student *ptr)
{
	string SSN, name, sGPA;
	double gpa;
	if (!ptr)//failsafe #1
	{
		cout << "Not enough memory for the array" << endl;
	}
	else
	{
		ifstream fin;
		fin.open(filename);
		if (fin.fail())//failsafe #2
		{
			cout << "Failed to open data file" << endl;
		}
		else
		{
			for (int i = 0; i < size; i++)
			{
				fin >> ptr[i];
			}
		}
	}
}

/*
* Pre: the size of the array and the pointer for the array
* Post: none
* Purpose: sort the array in ascending order
*/
void sort(int size, Student *ptr)//selection sort (my personal favourite and go to choice)
{
	for (int i = 0; i < size - 1; i++)
	{
		Student min = ptr[i];
		int minIndex = i;
		for (int k = i; k < size; k++)
		{
			if (min > ptr[k])//use overloaded method in student
			{
				min = ptr[k];
				minIndex = k;
			}
		}
		//swap positions of students
		Student temp = min;
		ptr[minIndex] = ptr[i];
		ptr[i] = temp;

	}
}