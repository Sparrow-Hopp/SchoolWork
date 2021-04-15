/***        Author:  Tempest Hopp
   *         Class:  CSI-240-03
   *    Assignment:  Lab 4
   * Date Assigned:  March 8, 2021
   *      Due Date:  March 15, 2021, 13:00
   *      Filename:  header.h
   *
   * Description:
   *    Populate an array of students based on a given size, and then sort said array
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
#pragma once

#include "student.h"


//variable declarations
const int MAX_SIZE = 1000;
//Student students[MAX_SIZE];

const string DATA_FILE = "data.txt";

void display(int size, Student *ptr);
int promptSize();
void populate(int size, string filename, Student *ptr);
void sort(int size, Student *ptr);
