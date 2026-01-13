#include <iostream>
#include <iomanip>
using namespace std;

const double PI = 3.1415926535897932384626433832795;

int main()
{
   int i = 123;
   int p;               // current precision
  
   // use precision/setprecision to get current precision value,
   // set a new precision, use it then set it back to what it had been
   // and print same number
   p = cout.precision(); 
   cout << p << endl;
   cout << setprecision( 10 ) << PI << endl; 
   cout.precision( p );
   cout << PI << endl; 
   
   // use setw to set the width of a field to 10, then print left
   // justified 
   cout << "|" << setw( 10 ) << i << "|\n";
   cout << "|" << setw( 10 ) << left << i << "|\n";

   // use showpoint, scientific 
   cout << showpoint << scientific << PI << endl;

   // use noshowpoint and fixed
   cout << noshowpoint << fixed << setprecision( 0 ) << PI << endl;

   // reset precision to default then use uppercase and showpos
   cout.precision( p );
   cout << scientific << uppercase << showpos << PI << endl;

   // set fill character to '*' in a field
   cout.fill( '*' );
   cout << "|" << showpos << setw( 10 ) << internal << i << "|\n";

   // unset some flags I set earlier
   cout.unsetf( ios::showpoint | ios::scientific | ios::showpos );
   cout << PI << endl;
    
   return( 0 );
}
