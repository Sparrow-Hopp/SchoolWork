

#ifndef REPORTS_H
#define REPORTS_H

#pragma once
#include <iostream>
#include <fstream>

using namespace std;

struct Day
{
	double mTotalSales;
	int mTotalOrders;
	int mTotalItems;
	double mAverageItemsPerOrder;

	friend ofstream &operator<<(ofstream &output, Day obj);
};

#endif