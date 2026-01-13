/* File: cookieStruct.cpp
   Author: Base code by Cindy Arnold
   This program illustrates structures
*/
#include <iostream>
#include <string>
using namespace std;

// note the global creation of the Cookie structure type
struct Cookie
{
   string type;
   double price;
   bool icing;
};

// getCookie demonstrates returning a structure - not as efficient
// as passing by reference, actually
// A better function would have prototype:
// void getCookie( Cookie& );
Cookie getCookie( );

// printCookie demonastrates passing by reference - constant since
// printing doesn't change values in the actual parameter
void printCookie( const Cookie& );

int main()
{
   Cookie myCookie;        // declare a variable of type Cookie

   myCookie = getCookie(); // use getCookie to fill in the values in variable myCookie
   printCookie(myCookie);  // use printCookie to print out me's values
   return( 0 );
}

/* getCookie: asks user for type, price, and icing status 
   Parameters: none
   Returns: a Cookie
*/
Cookie getCookie( )
{
   Cookie c;
   char choice;

   cout << "Enter cookie type: ";
   cin >> c.type;
   cout << "Enter price: ";
   cin >> c.price;
   cout << "Is it iced or not? (Y/N) ";
   cin >> choice;
   if(choice == 'Y') {
      c.icing = true;
   } else {
      c.icing = false;
   }

   return( c );
}

/* printCookie: prints data members of a Cookie
   Parameters: Cookie to print
   Preconditions: Cookie parameter has valid values for type, price, and icing status
   Returns: nothing
*/
void printCookie( const Cookie& c )
{
   cout << c.type << " " << c.price << " " << (c.icing ? "Iced" : "Not iced") << endl;
}
