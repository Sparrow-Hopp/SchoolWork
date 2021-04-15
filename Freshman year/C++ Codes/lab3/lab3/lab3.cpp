#include "account.h"

using namespace std;

int main()
{
	//defining variables and testing default constructor
	Account obj, obj2, obj3;
	string ssn, name, junk;
	double saving, checking;

	//defining all variables in obj1
	cout << "\n\nYou are entering the information for account 1. Enter your SSN" << endl;
	cin >> ssn;
	cout << "Enter your first and last name" << endl;
	getline(cin, junk);
	getline(cin, name);
	cout << "Enter the amount of money in your savings account, then the amount of money in your checking account" << endl;
	cin >> saving >> checking;
	getline(cin, junk);

	//testing filled constructor
	Account obj1(ssn, name, saving, checking);

	//defining all variables in obj3
	cout << "\n\nYou are entering the information for account 3. Enter your SSN" << endl;
	cin >> ssn;
	cout << "Enter your first and last name" << endl;
	getline(cin, junk);
	getline(cin, name);
	cout << "Enter the amount of money in your savings account, then the amount of money in your checking account" << endl;
	cin >> saving >> checking;
	getline(cin, junk);

	//testing all mutators
	obj3.setSSN(ssn);
	obj3.setName(name);
	obj3.setSaving(saving);
	obj3.setChecking(checking);

	//defining all variables in obj2 and testing istream/ifstream overloading	
	cin >> obj2;

	//testing ostream/ofstream overloading
	cout << endl << endl << obj << endl << obj1 << endl << obj2 << endl;

	//testing relational operator overloading
	if (obj == obj1)
		cout << obj.getName() << " and " << obj1.getName() << " have the same SSN." << endl;
	if (obj3 == ssn)
		cout << "The SSN of " << obj3.getName() << " is " << ssn << endl;
	if (ssn != obj2)
		cout << "The SSN of " << obj2.getName() << " isn't " << ssn << endl;
	if (obj1 != obj2)
		cout << obj1.getName() << " does not have the same SSN as " << obj2.getName() << endl;
	if (obj2 != ssn)
		cout << obj2.getName() << "'s SSN isn't " << ssn << endl;
	if (ssn == obj3)
		cout << obj3.getName() << "'s SSN is " << ssn << endl;
	if (obj2 > obj3)
		cout << obj2.getName() << " has more money than " << obj3.getName() << endl;
	else
		cout << obj2.getName() << " has less than " << obj3.getName() << endl;
	if (obj < obj3)
		cout << obj.getName() << " has less money than " << obj3.getName() << endl;
	else
		cout << obj.getName() << " has more money than " << obj3.getName() << endl;

	//testing all accessor methods
	cout << "\n\nHere is all of the financial information for account 3" << endl;
	cout << obj3.getSSN() << endl << obj3.getName() << "\nSavings balance: " << obj3.getSaving() << "\nChecking balance: " << obj3.getChecking() << "\nTotal balance: " << obj3.getTotal();
	return 1;
}