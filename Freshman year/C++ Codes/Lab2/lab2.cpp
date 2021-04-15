/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Lab2
   * Date Assigned:  February 8, 2021
   *      Due Date:  February 15, 2021, 13:00
   *      Filename:  pa1.cpp
   *
   * Description:
   *   The project will use the modify the preexisting methods which are used to compute the
   * following information:
   * - the total cases
   * - the total death
   * - the 10 days with most cases
   * - the average cases per day
   * - the average death per day
   * 
   *	The modification will introduce a new struct, Covid, to more easily store the data
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

int main()
{
   Covid data [SIZE];
   double averageCase, averageDeath;
   string inputFile, outputFile;

   initializeArray(data);

   inputFile = getInputFileName();
   outputFile = getOutputFileName();

   int size = loadData(inputFile, data);

   computePercentages(size, data);

   averageCase = computeAverageCasePer(size, data);
   averageDeath = computeAverageDeathPer(size, data);

   storeData(outputFile, data, averageCase, averageDeath, size);

   return 0;
}