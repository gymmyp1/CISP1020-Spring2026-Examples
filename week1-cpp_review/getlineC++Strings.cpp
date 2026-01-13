/* File: getlineC++Strings.cpp  
   Author: Cindy Arnold
   Description: illustrates problems with getline and using cin >> 
*/
#include <iostream>
using namespace std;

int main()
{
   int n;
   string s1;
   char junk;
   
   // type 42 (enter) Hi Mom. cin >> n doesn't get rid of
   // the \n typed after entering n so getline reads and empty string
   cout << "Enter an integer: ";
   cin >> n;
// Can use cin.get but it only reads one character
 //cin.get( junk );
// OR can use cin.ignore to read past at most 10000 characters
 cin.ignore (10000, '\n' );
   cout << "Enter any old string (spaces ok): ";
   getline( cin, s1 );
 
   cout << "You entered: " << n << " |" << s1 << "|\n";

   return( 0 );
}
