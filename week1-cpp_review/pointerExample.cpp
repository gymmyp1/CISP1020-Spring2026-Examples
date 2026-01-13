/* File: pointerExample.cpp 
   Author: Cindy Arnold 
   Description: illustrates pointer operators and values 
*/
#include <iostream>
#include <cstdlib> // for NULL
using namespace std;

int main()
{
   //int* iPtr = NULL; // best practice to init pointers to NULL
   int* iPtr;
   int i;
   int j;

   // assign an integer value to an integer variable
   i = 6;
//   iPtr = 6;   // why not?
//   cout << *iPtr << endl;

   // assign an address of an integer to a pointer to an integer, an int* type
   iPtr = &i;
//   i = iPtr;     // why not
//   i = &iPtr;
   // print out i's value using i
   cout << "i\'s value using i: " << i << endl;

   // print out i's value using *iPtr
   cout << "i\'s value using *iPtr: " << *iPtr << endl;
   
   // print out i's address using i
   cout << "i\'s address using &i: " << &i << endl;

   // print out i's address using iPtr
   cout << "i\'s address using iPtr: " << iPtr << endl;

   // what's iPtr's address?
   cout << "iPtr's address, using &iPtr: " << &iPtr << endl;

   return( 0 );
}
