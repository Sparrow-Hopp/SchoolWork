/***        Author:  Legolas
   *         Class:  CSI-281-01
   *    Assignment:  PA1
   * Date Assigned:  8/31/21
   *      Due Date:  9/7/21
   *      Filename:  SampleData.cpp
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


#include "SampleData.h"

/*
Pre: none
Post: none
Purpose: define the variables within the SampleData class
*/
SampleData::SampleData()
{
    pMushrooms = new Mushroom[MAX_MUSHROOMS];
    mNumMushrooms = 0;
}

/*
Pre: a string
Post: none
Purpose: define the variables within the SampleData class
*/
SampleData::SampleData(string fileName)
{
    pMushrooms = new Mushroom[MAX_MUSHROOMS];
    mpDirections = new Direction[MAX_MUSHROOMS];
    mNumMushrooms = 0;
    ifstream fin;
    fin.open(fileName);
    if (!fin.fail())
    {
        while (!fin.eof())
        {
            fin >> pMushrooms[mNumMushrooms];
            string edibility;
            fin >> edibility;
            pMushrooms[mNumMushrooms].mEdibility = edibility;
            mpDirections[mNumMushrooms].mEdibility = edibility;
            mNumMushrooms++;
        }
    }
    else
    {
        exit(1);
    }
    fin.close();
    mNumMushrooms--;
}

/*
Pre: none
Post: none
Purpose: clean up the variables within the SampleData class upon destruction
*/
SampleData::~SampleData()
{
    delete[] pMushrooms;
    pMushrooms = nullptr;

    delete[] mpDirections;
    mpDirections = nullptr;
}

//accessor

/*
Pre: none
Post: an int
Purpose: get the number of mushrooms
*/
int SampleData::getNumMushrooms()
{
    return mNumMushrooms;
}

/*
Pre: none
Post: a dynamic array of mushrooms
Purpose: get the dynamic array of mushrooms
*/
Mushroom* SampleData::getMushrooms()
{
    return pMushrooms;
}

/*
Pre: none
Post: a dynamic array of directions
Purpose: get the dynamic array of mushrooms
*/
Direction* SampleData::getDirection()
{
    return mpDirections;
}

//distance methods

/*
Pre: two mushrooms and a direction
Post: none
Purpose: calculate the distance between the two mushrooms, and plug that data into the direction variable
*/
void SampleData::calcDirection(Mushroom mysteryMushroom, Mushroom sampleMushroom, Direction& dir)
{
    double distance = 0;
    double sum = 0;
    for (int i = 0; i < NUM_ATTRIBUTES; i++)
    {
        sum += pow((mysteryMushroom.mAttributes[i] - sampleMushroom.mAttributes[i]), 2);
    }
    distance = sqrt(sum);
    dir.mDirection = distance;
    dir.mEdibility = sampleMushroom.mEdibility;    
}

/*
Pre: a list of Directions
Post: a bool
Purpose: figure out if the majority of the mushrooms in closestMushrooms are edible
*/
bool SampleData::isEdible(Direction closestMushrooms[])
{
    int pCounter = 0;
    int eCounter = 0;
    for (int i = 0; i < closestMushrooms->mSize; i++)
    {
        char edibility = closestMushrooms[i].mEdibility.c_str()[0];
        switch (edibility)
        {
        case 'p':
            pCounter++;
            break;
        case 'e':
            eCounter++;
            break;
        }
    }
    return (eCounter > pCounter);
}

/*
Pre: a 1d array of directions
Post: none
Purpose: sort the array from least to greatest distance
*/
void SampleData::selectionSort(int size)
{
    int index = 0;
    for (int i = 0; i < size - 1; i++)
    {
        index = i;
        for (int k = i + 1; k < size; k++)
        {
            if (mpDirections[k].mDirection < mpDirections[index].mDirection)
            {
                index = k;
            }
        }
        Direction temp = mpDirections[index];
        mpDirections[index] = mpDirections[i];
        mpDirections[i] = temp;
    }
}