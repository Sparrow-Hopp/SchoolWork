/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Lab2
   * Date Assigned:  February 8, 2021
   *      Due Date:  February 15, 2021, 13:00
   *      Filename:  functions.cpp
   *
   * Description:
   *    This file define all the functions declared in header.h
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

#include "header.h"


/***     Pre: The size of the data and the data array
   *    Post: The average of the data is returned to the caller
   * Purpose: Compute the average for the given data
   *******************************************************************************/
double computeAverage(int size, int data[])
{
   int total = 0, i;

   for (i = 0; i < size; i++)
      total += data[i];

   return static_cast<double>(total) / size;
}

/*
Pre: The data array
Post: the average cases of the data
Purpose: compute the average cases of the data
*/
double computeAverageCasePer(int size, Covid covidArray[])
{
    double avgCases = 0;

    for (int i = 0; i < size; i++)
    {
        Covid v = covidArray[i];
        avgCases += v.mPerC;
    }
    return avgCases / size;
}

/*
Pre: The data array
Post: the average deaths of the data
Purpose: compute the average deaths of the data
*/
double computeAverageDeathPer(int size, Covid covidArray[])
{
    double avgDeaths = 0;

    for (int i = 0; i < size; i++)
    {
        avgDeaths += covidArray[i].mPerD;
    }
    return avgDeaths / size;
}

/*
Pre: the data array
Post: The percent cases and percent deaths for each piece of data
Purpose: calculate the percent cases and deaths for each country
*/
void computePercentages(int size, Covid covidArray[])
{
    double perD = 0;
    double perC = 0;

    for (int i = 0; i < size; i++)
    {
        perD = (double)covidArray[i].mTotD / (double)covidArray[i].mPop * 100;
        perC = (double)covidArray[i].mTotC / (double)covidArray[i].mPop * 100;

        covidArray[i].mPerC = perC;
        covidArray[i].mPerD = perD;
    }
}


/***     Pre: The size of the data, the array for the date, cases and deaths
   *    Post: These array by the number of case from the highest to lowest
   * Purpose: Sort these arrays in descending order based on the number of cases
   *******************************************************************************/
void computeTopCases(int size, string date[], int cases[], int deaths[],
                     string topDate[], int topCases[], int topDeaths[])
{
   int i, j, maxIndex;

   for (i = 0; i < RECORD; i++)
   {
      maxIndex = 0;
      for (j = 0; j < size; j++)
      {
         if (cases[j] > cases[maxIndex])
            maxIndex = j;
      }

      topDate[i] = date[maxIndex];
      topCases[i] = cases[maxIndex];
      topDeaths[i] = deaths[maxIndex];

      cases[maxIndex] = USED;
   }
}


/***     Pre: None
   *    Post: A valid filename is returned to the caller
   * Purpose: Get the name of the input file from the user
   *******************************************************************************/
string getInputFileName()
{
   string   filename;
   ifstream fin;
   bool     valid = false;

   while (!valid)
   {
      cout << " Enter Input Filename:  ";
      getline(cin, filename);

      fin.open(filename);

      if (fin.fail())
      {
         cout << "\a\a\n\n\t\tInvalid Input File\n\n\n";
         fin.close();
         fin.clear();
      }
      else
         valid = true;
   }

   return filename;
}


/***     Pre: None
   *    Post: A valid filename is returned to the caller
   * Purpose: Get the name of the output file from the user
   *******************************************************************************/
string getOutputFileName()
{
   string   filename, response;
   ifstream fin;
   bool     valid = false;

   while (!valid)
   {
      cout << "Enter Output Filename:  ";
      getline(cin, filename);

      fin.open(filename);

      if (!fin.fail())
      {
         response = "";

         do
         {
            cout << "\a\a\n\nThe File Already Existed!!\n"
                 << "Do you want to override the file? ";
            getline(cin, response);

            response = toUpper(response);

            switch (response[0])
            {
               case 'N':
               case 'Y': break;
               default: cout << "\n\n\t\t\a\aInvalid Entry\n\n";
            }
         } while (response != "N" && response != "Y");

         fin.close();

         if (response == "N")
         {
            fin.clear();
         }
         else
            valid = true;
      }
      else
         valid = true;
   }

   return filename;
}


/***     Pre: An int array
   *    Post: All int are initialize as 0
   * Purpose: Initialize an int array
   *******************************************************************************/
void initializeArray(int intArray[])
{
   int i;

   for (i = 0; i < SIZE; i++)
      intArray[i] = 0;
}


/***     Pre: A string array
   *    Post: All strings are initialize as ""
   * Purpose: Initialize a string array
   *******************************************************************************/
void initializeArray(string strArray[])
{
   int i;

   for (i = 0; i < SIZE; i++)
      strArray[i] = "";
}

/*
Pre: a covid array
Post: all strings are initialized as "" and all ints are initialized as 0
Purpose: initialize a covid array
*/
void initializeArray(Covid covidArray[])
{
    for (int i = 0; i < SIZE; i++)
    {
        Covid v = covidArray[i];
        v.mCode = "";
        v.mCont = "";
        v.mDate = "";
        v.mName = "";
        v.mPop = 0;
        v.mTotD = 0;
        v.mTotC = 0;
        v.mPerC = 0;
        v.mPerD = 0;
    }
}


/***     Pre: The name of the input file, a string array and 2 int arrays
   *    Post: The data is loaded from the file into the different arrays and the
   *          total number of record is returned to the caller
   * Purpose: To load the data from the file into the memory
   *******************************************************************************/
int loadData(string inputFile, string date[], int cases[], int deaths[])
{
   int      i = 0;
   ifstream fin;

   fin.open(inputFile);
   if (!fin.fail() && i < SIZE)
   {
      fin >> date[i];

      while (!fin.eof())
      {
         fin >> cases[i] >> deaths[i];

         i++;

         fin >> date[i];
      }
   }

   fin.close();
   
   return i;
}

/***     Pre: The name of the input file and a Covid array
   *    Post: The data is loaded from the file into the array
   * Purpose: To load the data from the file into the memory
   *******************************************************************************/
int loadData(string inputFile, Covid covidArray[])
{
    int i = 0;
    string line = "";
    ifstream fin;

    fin.open(inputFile);
    if (!fin.fail() && i < SIZE)
    {
         //Covid v = covidArray[i];
         while (!fin.eof())
         {
             string dataPoints[SIZE];
             initializeArray(dataPoints);
             getline(fin, line);
             if (line != "")
             {
                 int k = 0;
                 int prevIndex = 0;
                 for (int j = 0; j < line.length(); j++)
                 {
                     //break down the line into its individual data points
                     if (line.at(j) == ',')
                     {
                         dataPoints[k] = line.substr(prevIndex, j - prevIndex);
                         prevIndex = j + 1;
                         k++;
                     }
                 }
                 dataPoints[k] = line.substr(prevIndex, line.length() - prevIndex);
                 //put all data in respective spot (couldn't think of more efficient way to do this)
                 covidArray[i].mCode = dataPoints[0];
                 covidArray[i].mCont = dataPoints[1];
                 covidArray[i].mName = dataPoints[2];
                 covidArray[i].mDate = dataPoints[3];
                 covidArray[i].mTotC = stoi(dataPoints[4]);
                 covidArray[i].mTotD = stoi(dataPoints[5]);
                 covidArray[i].mPop = stoi(dataPoints[6]);
                                     
             }
             i++;
         }
         
    }
    return i - 1;
}


/***     Pre: The name of the output file, a string array and 2 int arrays
   *    Post: The data is stored to the output file 
   * Purpose: To store the data from the file into the memory
   *******************************************************************************/
void storeData(string outputFile, string date[], int cases[], int deaths[],
               double averageCases, double averageDeath)
{
   int      i;
   ofstream fout;

   fout.setf(ios::fixed | ios::showpoint);
   fout.precision(3);

   fout.open(outputFile);

   fout << " Average Cases per Day: " << averageCases << endl;
   fout << "Average Deaths per Day: " << averageDeath << endl;

   fout << "\nThe top " << RECORD << " days with the most cases\n";
   fout << setw(10) << "Date" << " " << setw(10) << "Cases" << " "
        << setw(10) << "Deaths" << endl;
   for (i = 0; i < RECORD; i++)
      fout << setw(10) << date[i] << " " << setw(10) << cases[i] << " "
           << setw(10) << deaths[i] << endl;

   fout.close();
}

/***     Pre: The name of the output file and a Covid array
   *    Post: The data is stored to the output file
   * Purpose: To store the data from the file into the memory
   *******************************************************************************/
void storeData(string outputFile, Covid covidArray[], double averageCases, double averageDeath, int size)
{
    ofstream fout;

    fout.setf(ios::fixed | ios::showpoint);
    fout.precision(3);

    fout.open(outputFile);

    fout << " Average Percent Infected: " << averageCases << endl;
    fout << "Average Percent Dead: " << averageDeath << endl;
    fout << left << setw(12) << "Date:" << setw(10) << "ISO Code: " << setw(35) 
        << "Location: " << right << setw(12) << "Percent Infected: " << setw(12) << "Percent Dead: " << endl;

    //print the data for all countries
    for (int i = 0; i < size; i++)
    {
        Covid v = covidArray[i];
        fout << left << setw(12) << v.mDate << setw(10) << v.mCode << setw(35)
            << v.mName << right << setw(12) << setprecision(1) << v.mPerC << setw(12) << setprecision(1) << v.mPerD << endl;
    }
}


/***     Pre: A string
   *    Post: A string in all CAP is returned to the caller
   * Purpose: Convert the entire string to upper case
   *******************************************************************************/
string toUpper(string str)
{
   transform(str.begin(), str.end(), str.begin(), ::toupper);

   return str;
}