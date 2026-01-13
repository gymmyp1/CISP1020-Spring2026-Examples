/* File: charIO.cpp
   Author: Cindy Arnold
   Prompts user for one word, reads it then reads rest of line until the end
     to get rid of extra characters the user might have typed
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
   string word;
   char nextChar;
   
   cout << "Enter one word (but type in 2 words to see what happens): ";
   cin >> word;
   cout << "Your word is: " << word << endl;
//cout << "The rest of what you typed is: |";
   do
   {
      cin.get( nextChar );
//      cout.put( nextChar );
   } while ( nextChar != '\n' );
//cout << "|\n";
   return( 0 );
}
