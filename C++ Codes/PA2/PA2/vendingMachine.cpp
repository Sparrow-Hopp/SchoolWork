#include "vendingMachine.h"
#include <fstream>
#include <iomanip>
//constructor and deconstructor

/*pre: none
post: all variables defined
purpose: to read from a file (if it exists) and define all variables necessary to run the vending machine
*/
VendingMachine::VendingMachine()
{
	ifstream fin;
	fin.open(DATA_FILE_NAME);
	if (fin.fail())//if the file doesn't already exist, set values to default
	{
		mPassword = BASE_PASSWORD;
		mMoney = BASE_MONEY;
		mNumItems = BASE_NUM_ITEMS;
		mStock[0].mName = "Snickers";
		mStock[0].mQuantity = MAX_QUANTITY;
		mStock[0].mPrice = 2.50;
		mStock[1].mName = "Twix";
		mStock[1].mQuantity = MAX_QUANTITY;
		mStock[1].mPrice = 1.75;
		mStock[2].mName = "Milk Duds";
		mStock[2].mQuantity = MAX_QUANTITY;
		mStock[2].mPrice = 1.00;
		mStock[3].mName = "Reese's";
		mStock[3].mQuantity = MAX_QUANTITY;
		mStock[3].mPrice = 3.00;
	}
	else//read from the existing file for the data on the vending machine
	{
		string p, name, junk;//junk is needed to prevent errors between using getline and fin
		int n, quantity;
		double m, price;
		fin >> n >> m >> p;
		getline(fin, junk);
		mNumItems = n;
		mMoney = m;
		mPassword = p;
		for (int i = 0; i < mNumItems; i++)//setting the values for each individual item
		{
			getline(fin, name);
			fin >> quantity >> price;
			getline(fin, junk);
			mStock[i].mName = name;
			mStock[i].mPrice = price;
			mStock[i].mQuantity = quantity;
		}
	}
	fin.close();//close the file
}

VendingMachine::~VendingMachine()
{
}

//accessors and mutators

/*pre: none
post: the contents of money
purpose: return the contents specified in money
*/
double VendingMachine::getMoney()
{
	return mMoney;
}

/*pre: none
post: the contents of numItems
purpose: return the contents specified in numItems
*/
int VendingMachine::getNumItems()
{
	return mNumItems;
}

/*pre: none
post: the contents of password
purpose: return the contents specified in password
*/
string VendingMachine::getPassword()
{
	return mPassword;
}

/*pre: a double named m
post: none
purpose: change the contents of money
*/
void VendingMachine::setMoney(double m)
{
	mMoney = m;
}

/*pre: an int named n
post: none
purpose: change the contents of numItems
*/
void VendingMachine::setNumItems(int n)
{
	mNumItems = n;
}

/*pre: a string named p
post: none
purpose: change the contents of password
*/
void VendingMachine::setPassword(string p)
{
	mPassword = p;
}

//other methods

/*pre: none
post: none
purpose: adding a new item to the vending machine
*/
void VendingMachine::addItem()
{
	string name, junk;
	int quantity;
	double price;
	cout << "Please enter the name, quantity, and price of the new item IN THAT ORDER on separate lines" << endl;
	getline(cin, junk);
	getline(cin, name);
	cin >> quantity >> price;//getting the values for the new item
	//setting the values for the new item
	mStock[mNumItems].mName = name;
	mStock[mNumItems].mQuantity = quantity;
	mStock[mNumItems].mPrice = price;
	mNumItems++;//increase the number of items by 1
}

/*pre: none
post: none
purpose: set the money inside the vending machine back to 5.00
*/
void VendingMachine::collectMoney()
{
	mMoney = 5.00;
}

/*pre: none
post: none
purpose: provide a menu for the owner of the vending machine with options for what to do
*/
void VendingMachine::ownerMenu()
{
	int choice;
	cout << "1. Set password\n2. Collect money\n3. Restock the machine\n4. Change the info of an item\n5. Shut down menu\n6. Add an item\n7. Remove an item\n8. Return to user menu\n\nPlease make your selection" << endl;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:
			{
				string p;
				cout << "please enter the new password" << endl;
				cin >> p;
				mPassword = p;
				cout << "The password has been reset" << endl;
				break;
			}
			case 2:
			{
				collectMoney();
				break;
			}
			case 3:
			{
				restock();
				break;
			}
			case 4:
			{
				int index;
				cout << "Please enter the index of the item you wish to edit" << endl;
				cin >> index;
				while (index < 0 || index >= mNumItems)
				{
					cout << "Invalid selection. Please enter a new index" << endl;
					cin >> index;
				}
				int choice2;
				cout << "1. Name\n2. Quantity\n3. Price\n\nPlease select what you would like to edit" << endl;
				cin >> choice2;
				while (choice2 < 1 || choice2 > 3)
				{
					cout << "Invalid selection. Please enter a new selection" << endl;
					cin >> choice2;
				}
				switch (choice2)
				{
					case 1:
					{
						string n;
						cout << "Please enter the new name of the item" << endl;
						cin >> n;
						mStock[index].mName = n;
						break;
					}
					case 2:
					{
						int q;
						cout << "Please enter the new quantity of the item" << endl;
						cin >> q;
						mStock[index].mQuantity = q;
						break;
					}
					case 3:
					{
						double p;
						cout << "Please enter the new price of the item" << endl;
						cin >> p;
						mStock[index].mPrice = p;
						break;
					}
				}
				break;
			}
			case 6:
			{
				addItem();
				break;
			}
			case 7:
			{
				removeItem();
				break;
			}
			case 8:
			{
				userMenu();
				break;
			}
			default:
			{
				cout << "Invalid selection. Please select again." << endl;
				cin >> choice;
			}
		}
		cout << "1. Set password\n2. Collect money\n3. Restock the machine\n4. Change the info of an item\n5. Shut down menu\n6. Add an item\n7. Remove an item\n8. Return to user menu\n\nPlease make your selection" << endl;
		cin >> choice;
	}
	shutDown();
}

/*pre: none
post: none
purpose: removing an item from the vending machine
*/
void VendingMachine::removeItem()
{
	int selection;
	for (int i = 1; i <= mNumItems; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		Item v = mStock[i - 1];
		cout << left << i << ": " << setw(20) << v.mName << right << setw(4) << v.mPrice << endl;
	}
	cout << "Please enter the index of the item you wish to remove" << endl;
	cin >> selection;//indicate the item to be removed
	for (int i = selection; i < mNumItems; i++)
		mStock[i - 1] = mStock[i];//shift all proceding items forward in the array
	mNumItems--;//decrement the number of items by 1
}

/*pre: none
post: none
purpose: reset the quantity of each item back to the max capacity (20)
*/
void VendingMachine::restock()
{
	for (int i = 0; i < mNumItems; i++)
	{
		mStock[i].mQuantity = MAX_QUANTITY;
	}
}

/*pre: none
post: none
purpose: send all the data stored in the vending machine to a text file which can be opened and used next time the machine is run
*/
void VendingMachine::shutDown()
{
	ofstream fout;
	fout.open(DATA_FILE_NAME);
	if (fout.fail())
		cout << "Error saving vending machine data" << endl;
	else
	{
		fout << mNumItems << " " << mMoney << " " << mPassword << endl;
		for (int i = 0; i < mNumItems; i++)
		{
			Item v = mStock[i];
			fout << v.mName << endl << v.mQuantity << " " << v.mPrice << endl;
		}
	}
	fout.close();
}

/*pre: none
post: none
purpose: provide a menu to the user of the vending machine with options for what to do (and an option to enter the secret owner password to send you to the owner menu)
*/
void VendingMachine::userMenu()
{
	string choiceP;
	int choice;
	double moneyInserted;
	for (int i = 1; i <= mNumItems; i++)
	{
		cout << fixed << showpoint << setprecision(2);
		Item v = mStock[i - 1];
		cout << left << i << ": " << setw(20) << v.mName << right << setw(4) << v.mPrice << endl;
	}
	cout << "Please pick a number" << endl;
	cin >> choiceP;
	while (choiceP != mPassword)
	{
		choice = stoi(choiceP);
		choice--;
		while (choice < 1 || choice >= mNumItems)
		{
			cout << "Invalid selection. Please make a new selection" << endl;
			cin >> choiceP;
			choice = stoi(choiceP);
		}
		
		cout << "Please insert your cash" << endl;
		cin >> moneyInserted;
		if (moneyInserted > mStock[choice].mPrice)
		{
			if (moneyInserted - mStock[choice].mPrice > mMoney)
				cout << "Not enough money in machine to give change. Have a nice day." << endl;
			else
			{
				mStock[choice].mQuantity--;
				mMoney += mStock[choice].mPrice;
				cout << "Your change is " << moneyInserted - mStock[choice].mPrice << ". Have a nice day." << endl;
			}
		}
		else
			cout << "Not enough money inserted for selected item. Have a nice day." << endl;
		cout << "Please make a selection" << endl;
		cin >> choiceP;
	}
	ownerMenu();
}


