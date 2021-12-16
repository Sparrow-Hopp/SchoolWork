/***        Author:  Legolas
   *         Class:  CSI-281-01
   *    Assignment:  PA1
   * Date Assigned:  8/31/21
   *      Due Date:  9/7/21
   *      Filename:  TestCases.cpp
   *
   * Description:
   *    Implement machine learning to determine the edibility of some mushrooms
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


#include "TestCases.h"



/*
Pre: none
Post: none
Purpose: define the variables within the TestCases class
*/
TestCases::TestCases()
{
    pMushrooms = new Mushroom[MAX_MUSHROOMS];
    mNumMushrooms = 0;
    mKValue = 0;
}

/*
Pre: a string
Post: none
Purpose: define the variables within the TestCases class
*/
TestCases::TestCases(string fileName)
{
    pMushrooms = new Mushroom[MAX_MUSHROOMS];
    ifstream fin;
    fin.open(fileName);
    if (!fin.fail())
    {
        fin >> mKValue;
        mpClosest = new Direction[mKValue];
        while (!fin.eof())
        {
            fin >> pMushrooms[mNumMushrooms];
            mNumMushrooms++;
        }
        mpClosest->mSize = mNumMushrooms;
    }
    else
    {
        exit(1);
    }
    fin.close();
}

/*
Pre: none
Post: none
Purpose: clean up the variables within the TestCases class upon destruction
*/
TestCases::~TestCases()
{
    delete[] pMushrooms;
    pMushrooms = nullptr;

    delete[] mpClosest;
    mpClosest = nullptr;
}

//accessors

/*
Pre: none
Post: an int
Purpose: get the number of mushrooms
*/
int TestCases::getNumMushrooms()
{
    return mNumMushrooms;
}

/*
Pre: none
Post: an int
Purpose: get the k value
*/
int TestCases::getKValue()
{
    return mKValue;
}

/*
Pre: none
Post: a mushroom
Purpose: get the dynamic array of mushrooms
*/
Mushroom* TestCases::getMushrooms()
{
    return pMushrooms;
}

/*
Pre: none
Post: a direction
Purpose: get the dynamic array of directions
*/
Direction* TestCases::getDirection()
{
    return mpClosest;
}