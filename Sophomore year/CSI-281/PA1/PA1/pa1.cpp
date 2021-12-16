/***        Author:  Legolas
   *         Class:  CSI-281-01
   *    Assignment:  PA1
   * Date Assigned:  8/31/21
   *      Due Date:  9/7/21
   *      Filename:  pa1.cpp
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


#include "pa1.h"
#include "SampleData.h"
#include "TestCases.h"

int main()
{
    SampleData sampleData(getFileName());
    TestCases testData(getFileName());
    string outputFile = getFileName();
    ofstream fout;
    fout.open(outputFile);
    if (fout.fail())
        cout << "Error opening output file" << endl;
    else
    {
        Mushroom* testMushrooms = testData.getMushrooms();
        Mushroom* sampleMushrooms = sampleData.getMushrooms();
        int size = testData.getDirection()->mSize;
        for (int i = 0; i < testData.getKValue() - 1; i++)
        {
            
            for (int k = 0; k < sampleData.getNumMushrooms(); k++)
            {
                sampleData.calcDirection(testMushrooms[i], sampleMushrooms[k], sampleData.getDirection()[k]);
            }
            sampleData.selectionSort(sampleData.getNumMushrooms());
            for (int j = 0; j < testData.getKValue(); j++)
            {
                testData.getDirection()[j].mDirection = sampleData.getDirection()[j].mDirection;
                testData.getDirection()[j].mEdibility = sampleData.getDirection()[j].mEdibility;
            }
            testData.getDirection()->mSize = size;
            if (sampleData.isEdible(testData.getDirection()))
            {
                fout << "edible" << endl;
            }
            else
            {
                fout << "poisonous" << endl;
            }
        }
    }
    fout.close();
	return 1;
}

string getFileName()
{
    string fileName;
    cout << "Please input the name of the file" << endl;
    cin >> fileName;
    return fileName;
}