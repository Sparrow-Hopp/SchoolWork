#include "Header.h"

int main()
{
	Student* ptr = new Student [MAX_SIZE];

	//method calls
	ptr->setSize(promptSize());
	populate(ptr->getSize(), DATA_FILE, ptr);
	display(ptr->getSize(), ptr);
	cout << "\n\n\n\n\n\n\n\n\n\n\n";
	sort(ptr->getSize(), ptr);
	display(ptr->getSize(), ptr);

	delete [] ptr;
	return 0;
}