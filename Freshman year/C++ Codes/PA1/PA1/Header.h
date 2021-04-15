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

#pragma once
#include<string>
#include<iostream>

using namespace std;

void avgCase(string data[731][3]);
void avgDeath(string data[731][3]);
void topTen(string data[731][3]);
