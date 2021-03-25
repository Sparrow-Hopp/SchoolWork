/***
Author: Jolly Cotton
Class : CSI 240-03
Assignment : PA 1
Date Assigned : Jan 25
Due Date : Jan 28 at 1pm
Description :
Analyze data from a file and report the average cases, average deaths, and the ten days with the highest cases in descending order (with other data included)
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

#include"Header.h"
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

using namespace std;

/*takes the data in column 1 of the 2d array and calculates the average
pre: a filled array
post: none*/
void avgCase(string data[368][3])
{
	double cases = 0;
	int i;

	for (i = 0; i < 368; i++)
	{
		cases += stod(data[i][1]);
	}

	//doesn't calculate average until print line to make sure it rounds to three decimal places, otherwise it'll round to one and have zeros at the end
	cout << "Average cases: " << setprecision(3) << fixed << cases / i << endl;
}

/*takes the data in column 2 of the 2d array and calculates the average
pre: a filled array
post: none*/
void avgDeath(string data[368][3])
{
	double deaths = 0;
	int i = 0;
	do
	{
		deaths += stod(data[i][2]);
		i++;
	} while (i < 368);

	//doesn't calculate average until print line to make sure it rounds to three decimal places, otherwise it'll round to one and have zeros at the end
	cout << "Average deaths: " << setprecision(3) << fixed << deaths / i << endl;
}

void topTen(string data[368][3])
{
	//set the cap to a number larger than the largest number in the data set
	double cap = 10000000000;
	string topTen[10][3];
	//fills from the first open slot, in descending order... and makes sure numbers aren't duplicated by lowering the cap each time
	for (int i = 0; i < 10; i++)
	{
		double max = 100;
		for (int k = 0; k < 368; k++)
		{
			if (stod(data[k][1]) > max && stod(data[k][1]) < cap)
			{
				max = stod(data[k][1]);
				for (int j = 0; j < 3; j++)
				{
					topTen[i][j] = data[k][j];
				}
			}
		}
		cap = max;
	}
	for (int r = 0; r < 10; r++)
	{
		for (int c = 0; c < 3; c++)
			cout << topTen[r][c] << "   ";
		cout << endl;
	}
}