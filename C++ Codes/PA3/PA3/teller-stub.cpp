#include "Teller.h"

int main()
{
	Teller teller;

	//test loadData
	bool loaded;
	loaded = teller.loadData("Text.txt");
	cout << loaded << endl;

	string validID = "d-payne";
	string validPW = "sputnik";
	string invalidID = "m-johnson";
	string invalidPW = "hello";
	bool doExist, noExist;

	//test verifyTeller
	doExist = teller.verifyTeller(validID, validPW);
	noExist = teller.verifyTeller(invalidID, invalidPW);
	cout << doExist << endl << noExist << endl;

	//test storeData
	teller.storeData("out.txt");
	teller.~Teller();
	return 1;
}