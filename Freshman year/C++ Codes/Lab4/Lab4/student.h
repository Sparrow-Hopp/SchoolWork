//  filename:  student.h

/*
Author:  Wei Kian Chen
Class:  CSI-240-03
Assignment: Lab 4
Created on: March 3, 2021

Description:
The project is to create a dynamic array of Student and manipulate this array.  
However, the purpose of this file is merely create the Student type

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others.I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment may, for
the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff; and/or
- Communicate a copy of this assignment to a plagiarism checking service(which may then
retain a copy of this assignment on its database for the purpose of future plagiarism
checking)
*/


#ifndef _Student_H
#define _Student_H

#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

class Student  
{
   protected:
      string mId, mName;
      double mGpa;

      static int mSize;

   public:
      //  constructor
      Student();

      //  copy constructor
      Student(string id, string name, double gpa);

      //  deconstructor
      ~Student();

      //  Accessor
      double getGPA();
      string getID();
      string getName();

      //  mutator
      void setGPA(double gpa);
      void setID(string id);
      void setName(string name);

      //  other
      static int getSize();
      static void setSize(int size);

      //  overloading operators
      friend ostream& operator<<(ostream& output, Student obj);
      friend ofstream& operator<<(ofstream& output, Student obj);
      friend istream& operator>>(istream& input, Student& obj);
      friend ifstream& operator>>(ifstream& input, Student& obj);
      bool operator==(Student rhs);
      bool operator==(string rhs);
      friend bool operator==(string lhs, Student rhs);
      bool operator!=(Student rhs);
      bool operator!=(string rhs);
      friend bool operator!=(string lhs, Student rhs);
      bool operator>(Student rhs);
};


#endif