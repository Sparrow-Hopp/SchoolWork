#include "account.h"

using namespace std;

/*int main()
{
	//defining variables and testing default constructor
	ifstream fin;
	ofstream fout;
	Account obj, obj2, obj3, obj4;
	string accountNum, ssn, name, address, phoneNumber, save, check;
	double savings, checking;

	//open files
	fin.open(INPUT_FILE);
	fout.open(OUTPUT_FILE);

	//test to see if files opened properly
	if (fin.fail() || fout.fail())
		cout << "Error opening input or output file." << endl;
	else
	{
		//defining all variables in obj1
		cout << "Account Number: " << endl;
		getline(cin, accountNum);
		cout << "SSN: " << endl;
		getline(cin, ssn);
		cout << "Name: " << endl;
		getline(cin, name);
		cout << "Address (one line): " << endl;
		getline(cin, address);
		cout << "Phone Number: " << endl;
		getline(cin, phoneNumber);
		cout << "Savings Amount: $" << endl;
		getline(cin, save);
		savings = stod(save);
		cout << "Checking Amount: $" << endl;
		getline(cin, check);
		checking = stod(check);

		//testing filled constructor
		Account obj1(accountNum, ssn, name, address, phoneNumber, savings, checking);

		//defining all variables in obj3
		cout << "You are entering the information for account 3. Account Number: " << endl;
		getline(cin, accountNum);
		cout << "SSN: " << endl;
		getline(cin, ssn);
		cout << "Name: " << endl;
		getline(cin, name);
		cout << "Address (one line): " << endl;
		getline(cin, address);
		cout << "Phone Number: " << endl;
		getline(cin, phoneNumber);
		cout << "Savings Amount: $" << endl;
		getline(cin, save);
		savings = stod(save);
		cout << "Checking Amount: $" << endl;
		getline(cin, check);
		checking = stod(check);

		//testing all mutators
		obj3.setAccountNumber(accountNum);
		obj3.setSSN(ssn);
		obj3.setName(name);
		obj3.setAddress(address);
		obj3.setPhoneNumber(phoneNumber);
		obj3.setSaving(savings);
		obj3.setChecking(checking);

		//defining all variables in obj2 and obj4 and testing istream/ifstream overloading	
		cout << endl;
		cin >> obj2;
		fin >> obj4;

		//testing ostream/ofstream overloading
		cout << obj << endl << obj1 << endl << obj2 << endl;

		//testing relational operator overloading
		if (obj == obj1)
			cout << obj.getName() << " and " << obj1.getName() << " have the same account number." << endl;
		if (obj3 == accountNum)
			cout << "The account number of " << obj3.getName() << " is " << accountNum << endl;
		if (accountNum != obj2)
			cout << "The account number of " << obj2.getName() << " isn't " << accountNum << endl;
		if (obj1 != obj2)
			cout << obj1.getName() << " does not have the same account number as " << obj2.getName() << endl;
		if (obj2 != accountNum)
			cout << obj2.getName() << "'s account number isn't " << accountNum << endl;
		if (accountNum == obj3)
			cout << obj3.getName() << "'s account number is " << accountNum << endl;
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
		cout << "Account Number: " << obj3.getAccountNumber() << endl << "SSN: " << obj3.getSSN() << endl << "Name: " << obj3.getName() << endl
			<< "Address: " << obj3.getAddress() << endl << "Phone Number: " << obj3.getPhoneNumber() << endl << "Saving Amount: $" << obj3.getSaving() << endl << "Checking Amount: $" << obj3.getChecking() << endl << "Total: $" << obj3.getTotal() << endl;

		//store data to file
		fout << obj4 << endl;

		//close files
		fout.close();
		fin.close();
	}
	return 1;
}*/