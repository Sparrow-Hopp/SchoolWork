//  filename:  student.cpp

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

#include "student.h"

//  initializing the static variable
int Student::mSize = 0;


/*
Pre: None
Post: Private members are initialized to default value
Purpose: Initialize private member when an object of the class is instantiated
*/
Student::Student()
{
    mId = "";
    mName = "";
    mGpa = 0;
}


/*
Pre: default value for ID, name and GPA
Post: Private members are initialized to the values provided
Purpose: Initialize private member when an object of the class is instantiated
*/
Student::Student(string id, string name, double gpa)
{
    mId = id;
    mName = name;
    mGpa = gpa;
}


/*
Pre: None
Post: Nothing for the time being
Purpose: Clean up the class object
*/
Student::~Student()
{
}


//  assessor
/*
Pre: None
Post: The GPA of the student is return
Purpose: Retrieve the GPA for the student
*/
double Student::getGPA()
{
    return mGpa;
}


/*
Pre: None
Post: The ID of the student is return
Purpose: Retrieve the ID for the student
*/
string Student::getID()
{
    return mId;
}


/*
Pre: None
Post: The name of the student is return
Purpose: Retrieve the name for the student
*/
string Student::getName()
{
    return mName;
}


//  mutator
/*
Pre: The new GPA value
Post: The GPA of the student is updated
Purpose: Update the GPA for the student
*/
void Student::setGPA(double gpa)
{
    mGpa = gpa;
}


/*
Pre: The new ID value
Post: The ID of the student is updated
Purpose: Update the ID for the student
*/
void Student::setID(string id)
{
    mId = id;
}


/*
Pre: The new name value
Post: The name of the student is updated
Purpose: Update the name for the student
*/
void Student::setName(string name)
{
    mName = name;
}


// other
/*
Pre: None
Post: The static size is returned
Purpose: Retrieve the size for the student
*/
int Student::getSize()
{
    return mSize;
}


/*
Pre: size
Post: The static size is updated
Purpose: Update the size for the student
*/
void Student::setSize(int size)
{
    mSize = size;
}


//  overloading operators
/*
Pre: Student object
Post: True if the ID of the lhs matches the ID of the rhs; otherwise false
Purpose: Evaluate if the two Student objects match
*/
bool Student::operator==(Student rhs)
{
    return mId == rhs.mId;
}


/*
Pre: ID
Post: True if the ID of the object matches the specified ID; otherwise false
Purpose: Evaluate if the ID of the Student object matches the provided ID
*/
bool Student::operator==(string id)
{
    return mId == id;
}


/*
Pre: ID and Student object
Post: True if the ID of the lhs matches the ID of the rhs; otherwise false
Purpose: Evaluate if the ID of the Student object matches the provided ID
*/
bool operator==(string lhs, Student rhs)
{
    return lhs == rhs.mId;
}


/*
Pre: ID
Post: True if the ID of the Student does not matches the ID of the rhs;
      otherwise false
Purpose: Evaluate if the two Student objects match
*/
bool Student::operator!=(string rhs)
{
    return !(mId == rhs);
}


/*
Pre: Student
Post: True if the ID of the Student does not matches the ID of the rhs;
      otherwise false
Purpose: Evaluate if the two Student objects match
*/
bool Student::operator!=(Student rhs)
{
    return !(mId == rhs.mId);
}


/*
Pre: ID and Student
Post: True if the ID of the lhs does not matches the ID of the rhs;
      otherwise false
Purpose: Evaluate if the two Student objects match
*/
bool operator!=(string lhs, Student rhs)
{
    return !(lhs == rhs.mId);
}


//  friend functions
/*
Pre: input stream and Student object
Post: The Student object is updated and the updated input stream is returned
Purpose: Read a Student object from the input stream
*/
istream& operator>>(istream& input, Student& obj)
{
    string junk;

    cout << "  Enter ID:  ";
    getline(input, obj.mId);

    cout << "Enter Name:  ";
    getline(input, obj.mName);

    cout << " Enter GPA:  ";
    input >> obj.mGpa;
    getline(input, junk);

    return input;
}


/*
Pre: input file stream and Student object
Post: The Student object is updated and the updated input file stream is returned
Purpose: Read a Student object from the input file stream
*/
ifstream& operator>>(ifstream& input, Student& obj)
{
    string junk;

    getline(input, obj.mId);
    getline(input, obj.mName);
    input >> obj.mGpa;
    getline(input, junk);

    return input;
}


/*
Pre: output stream and Student object
Post: The Student object is displayed and the updated output stream is returned
Purpose: Output a Student object to the output stream
*/
ostream& operator<<(ostream& output, Student obj)
{
    output << "  ID:  " << obj.mId << endl
        << "Name:  " << obj.mName << endl
        << " GPA:  " << obj.mGpa << endl;

    return output;
}


/*
Pre: output file stream and Student object
Post: The Student object is displayed and the updated output file stream is returned
Purpose: Output a Student object to the output file stream
*/
ofstream& operator<<(ofstream& output, Student obj)
{
    output << obj.mId << endl
        << obj.mName << endl
        << obj.mGpa << endl;

    return output;
}


/*
Pre: Student object
Post: True is the ID object is greater than the ID of the Student object in rhs;
      otherwise false
Purpose: Compare the ID on the lhs and and the rhs
*/
bool Student::operator>(Student rhs)
{
    return mId > rhs.mId;
}