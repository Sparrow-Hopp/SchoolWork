/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Lab2
   * Date Assigned:  February 8, 2021
   *      Due Date:  February 15, 2021, 13:00
   *      Filename:  header.h
   *
   * Description:
   *    This file contain all the header for functions and consts used in this
   * system.
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

#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <algorithm> 
#include <iterator>
#include "covid.h"

using namespace std;

const int SIZE = 250;
const int RECORD = 10;
const int USED = -1;
const int DATA_POINTS = 7;

double computeAverage(int size, int data[]);
double computeAverageCasePer(int size, Covid covidArray[]);
double computeAverageDeathPer(int size, Covid covidArray[]);
void computePercentages(int size, Covid covidArray[]);
void   computeTopCases(int size, string date[], int cases[], int deaths[],
                       string topDate[], int topCases[], int topDeaths[]);
string getInputFileName();
string getOutputFileName();
void   initializeArray(int intArray[]);
void   initializeArray(string strArray[]);
void   initializeArray(Covid covidArray[]);
int    loadData(string inputFile, string date[], int cases[], int deaths[]);
int    loadData(string inputFile, Covid covidArray[]);
void   storeData(string outputFile, string date[], int cases[], int deaths[],
                 double averageCases, double averageDeath);
void   storeData(string outputFile, Covid covidArray[], double averageCases, double averageDeath, int size);
string toUpper(string originalString);

#endif