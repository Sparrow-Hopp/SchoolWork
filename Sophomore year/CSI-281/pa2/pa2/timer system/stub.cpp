#include <iostream>
#include <iomanip>
#include "TimerSystem.h"

using namespace std;

const int MAX = 100, RANGE = 1001;

int main()
{
   TimerSystem timer;
   int         numbers[MAX], i;

   cout.setf(ios::fixed | ios::showpoint);
   cout.precision(16);

   srand(unsigned(time(NULL)));

   timer.startClock();
   cout << "The amount of time needed to display a line is " << timer.getTime() << "s\n";

   timer.startClock();

   for (i = 0; i < MAX; i++)
      numbers[i] = rand() % RANGE;

   cout << "\n\nThe amount of time needed to populate 100 integers is " << timer.getTime() << "s\n";


   timer.startClock();

   for (i = 0; i < MAX; i++)
   {
      cout << numbers[i] << " ";

      if (i != 0 && i % 10 == 0)
         cout << endl;
   }

   cout << "\n\n\nThe amount of time needed to display 100 integers is " << timer.getTime() << "s\n";
   
   return 0;
}