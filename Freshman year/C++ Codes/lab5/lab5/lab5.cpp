/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  lab 5
   * Date Assigned:  March 29, 2021
   *      Due Date:  April 1, 2021, 14:15
   *      Filename:  lab5.cpp
   *
   * Description:
   *    Create a "family" of classes that define an item, book, and a comic
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
#include "Comic.h"

int main()
{
	//dummy variables for testing
	string code = "a3kd8";
	string title = "The Dawn";
	string author = "John Doe";
	double price = 9.75;
	int quantity = 12;
	int volume = 67;
	int series = 23;

	//tests for item class
	Item item1, item3;
	cout << item1.getCode() << " " << item1.getPrice() << " " << item1.getQuantity() << endl;
	Item item2(code, price, quantity);
	item1.setCode(code);
	item1.setPrice(price);
	item1.setQuantity(quantity);
	cin >> item3;
	cout << item1 << item2 << item3 << "\n\n\n\n\n";

	//tests for book class
	Book book1, book3;
	cout << book1.getCode() << " " << book1.getTitle() << " " << book1.getAuthor() << book1.getPrice() << " " << book1.getQuantity() << endl;
	Book book2(code, title, author, price, quantity);
	book1.setCode(code);
	book1.setTitle(title);
	book1.setAuthor(author);
	book1.setPrice(price);
	book1.setQuantity(quantity);
	cin >> book3;
	cout << book1 << book2 << book3 << "\n\n\n\n\n";

	//tests for comic class
	Comic comic1, comic3;
	cout << comic1.getCode() << " " << comic1.getTitle() << " " << comic1.getAuthor() << comic1.getPrice() << " " << comic1.getQuantity() << " " << comic1.getVolume() << " " << comic1.getSeries() << endl;
	Comic comic2(code, title, author, price, quantity, volume, series);
	comic1.setCode(code);
	comic1.setTitle(title);
	comic1.setAuthor(author);
	comic1.setPrice(price);
	comic1.setQuantity(quantity);
	comic1.setVolume(volume);
	comic1.setSeries(series);
	cin >> comic3;
	cout << comic1 << comic2 << comic3 << "\n\n\n\n\n";
	return 1;
}