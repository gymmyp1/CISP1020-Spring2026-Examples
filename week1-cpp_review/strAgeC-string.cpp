/* File: strAgeC-string.cpp 
   Author: Cindy Arnold
   Description: read age as a string with getline. Check to 
      make sure an int 
*/
#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

const int AGE_LENGTH = 4;
const int CURRENT_YEAR = 2022;

int main()
{
   char strAge[AGE_LENGTH];
   int intAge, yearBorn, i=0;
   bool notAnInt = false;

   // get age, echo it back
   cout << "Enter age: ";
   cin.getline( strAge, AGE_LENGTH );

   // check to see if all chars are digits
   for( i = 0; strAge[i] != '\0'; i++ ) {
      if ( !isdigit( strAge[i] ))  {
         notAnInt = true;
         break;
      }
   }

   // is user entered non-positive int, print error mesage
   // otherwise, convert string age to int and compute birth year
   // assuming birthday already passed
   if ( notAnInt ) {
      cout << strAge << " is not an integer\n";
   }
   else {
      intAge = atoi( strAge );
      if ( intAge > 122 ) cout << "You are older than the oldest person alive." << endl;
      else {
         yearBorn = CURRENT_YEAR - intAge;
         cout << "Born in " << yearBorn << endl;
      }
   }
   return( 0 );
}