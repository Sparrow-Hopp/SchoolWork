#include "Teller.h"

//constructor and destructor

/*
* Pre: none
* Post: none
* Purpose: Set the values inside teller to the default
*/
Teller::Teller()
{
	count = 0;
	tellers = NULL;
}

/*
* Pre: none
* Post: none
* Purpose: Reset the values inside teller to the default
*/
Teller::~Teller()
{
	count = 0;
	tellers = NULL;
}

//other methods

/*
* Pre: a filename
* Post: a boolean indicating if the file opened properly
* Purpose: Set the values inside teller to the values specified in fileName
*/
bool Teller::loadData(string fileName)
{
	ifstream fin;
	fin.open(fileName);
	if (fin.fail())//check to see if the file opens
	{
		cout << "Error opening file" << endl;
		return false;
	}
	else
	{
		int i = 0;
		fin >> count;
		tellers = new Employee[count];//define tellers
		while (!fin.eof() && i < count)
		{
			fin >> tellers[i++];//use the overloaded operator in employee to define all values inside tellers
		}
		return true;
	}
}

/*
* Pre: a filename
* Post: none
* Purpose: Store the values inside teller to fileName
*/
void Teller::storeData(string fileName)
{
	int i = 0;
	ofstream fout;
	fout.open(fileName);
	if (fout.fail())//check to see if the file opens
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		fout << count << endl;
		while (i < count)
		{
			fout << tellers[i++];//use the overloaded operator in employee to store all the values inside teller
		}
	}
}

/*
* Pre: an ID and a password
* Post: a boolean indicating if the ID and password combo exists
* Purpose: check to see if the provided ID and password is valid
*/
bool Teller::verifyTeller(const string& id, const string& password)
{
	int i = 0;
	while (i < count)
	{
		if (tellers[i].mID == id && tellers[i].mPW == password)//check to see if they match an existing ID and password combo
			return true;
		i++;
	}
	return false;
}
