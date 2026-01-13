/*
   File: pp6a.cpp
   Author: Cindy Arnold
   This program gets input and output file names from the user,
   reads numbers from the input file and write the numbers formatted
   as dollar amounts to the output file
*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include <iomanip>
using namespace std;


bool readNum( ifstream&, double& );
void writeNum( ofstream&, double );

const int MAX_FILENAME = 256;

int main()
{
   double num;
   ifstream input;
   ofstream output;
   char filename[MAX_FILENAME];

   // get input file name, open it
   cout << "Enter input file name: ";
   cin >> filename;
   input.open( filename );

   // input file doesn't exists, end program
   if ( input.fail() )
   {
      cout << "Input file " << filename << " open failed.\n";
      return 0;
   }

   // if existing input file empty, end program
   char c;
   input.get( c );
   if ( input.eof() ) {
      cout << "Input file " << filename << " is empty.\n";
      return 0;
   }

   // otherwise, input file exists and is non-empty so put back char read
   // to check empty and read/write to output file until eof
    input.putback( c );
   cout << "Enter output file name: ";
   cin >> filename;
   output.open( filename );

   // read numbers while there is still a data to get and write them formatted to output file
   while ( readNum( input, num )  )
   {
      writeNum( output, num );
   }

   // close files and we're done
   input.close( );
   output.close( );
   return 0;
}


/* readNum: reads one number from a file
   Parameters:
      in: input file
      n: number read in
   Pre-condition: input file is already open
   Post-condition: n has a value from the file if the read was successful
   Returns:true if data was read successfully
*/
bool readNum( ifstream& in, double& n )
{
   if (in >> n) { 
      return true;
   } else {
      return false;
   }
}

/* writeNum: writes one number to a file in dollar format
   Parameters:
      out: output file
      n: number to write 
   Pre-condition: output file is already open
   Returns: nothing
*/
void writeNum( ofstream& out, double n )
{
   out.precision( 2 );
   out.setf( ios::fixed );
   out.setf( ios::showpoint );
   out << "$" << setw(7) << right << n << "\n";
}   