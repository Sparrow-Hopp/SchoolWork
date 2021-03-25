#ifndef TELLER_H
#define TELLER_H

#pragma once

#include "employee.h"

class Teller
{
	private:
		//declare variables
		int count;
		Employee* tellers;

	public:
		//constructor and destructor
		Teller();
		~Teller();

		//other methods
		bool loadData(string fileName);
		void storeData(string fileName);
		bool verifyTeller(const string& id, const string& password);
};

#endif