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
#include <fstream>

using namespace std;

int main()
{
	//variable declarations
	string data[368][3];
	ifstream fin;
	string name, date, cases, deaths;

	cout << "Please input the name of the data file: " << endl;
	cin >> name;
	fin.open(name, ios::in);
	//check to see if the data file exists and opened properly
	if (fin.fail())
	{
		cout << "Failed to open data file" << endl;
		return 1;
	}
	else
	{
		//take the values in the text file and place them into the 2d array
		int i = 0;
		while (!fin.eof())
		{
			fin >> date >> cases >> deaths;
			data[i][0] = date;
			data[i][1] = cases;
			data[i][2] = deaths;
			i++;
		}
	}

	int choice;

	cout << "Please select what you would like to do: \n1: See the average cases\n2: See the average deaths\n3: See the top ten days with the most cases\n4: Exit" << endl;
	cin >> choice;
	while (choice != 4)
	{
		switch (choice)
		{
		case 1:
			avgCase(data);
			break;
		case 2:
			avgDeath(data);
			break;
		case 3:
			topTen(data);
			break;
		default:
			cout << "invalid selection." << endl;
		}
		cout << "Please select what you would like to do: \n1: See the average cases\n2: See the average deaths\n3: See the top ten days with the most cases\n4: Exit" << endl;
		cin >> choice;
	}
}