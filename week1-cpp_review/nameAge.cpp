/* File: nameAge.cpp
 * Author: Cindy
 * Description: repeatedly asks users for name (using getline) and age, an int. 
 *    Has code for both C-string and C++ string object for name
 */
#include <iostream>
#include <string>

using namespace std;

const int MAX_NAME_LENGTH = 81; // for a name with max 80 chars

int main() {
   char cName[MAX_NAME_LENGTH];
   string cppName;
   int age;
   char junk;

   // Test using C string
   cout << "Enter your full name (press Enter to end): ";
   cin.getline( cName, MAX_NAME_LENGTH );
   while ( cName[0] != '\0' ) { 
      cout << "Enter your age: ";
      cin >> age;
      cout << "You entered: |" << cName << "| " << age << endl;
      do {
         cin.get( junk );
      } while ( junk != '\n' );
      cout << "Enter your full name (press Enter to end): ";
      cin.getline( cName, MAX_NAME_LENGTH );
   } 
  
   // Test using C++ string object
   cout << "Enter your full name (press Enter to end): ";
   getline( cin, cppName );
   while ( cppName[0] != '\0' ) { 
      cout << "Enter your age: ";
      cin >> age;
      cout << "You entered: |" << cppName << "| " << age << endl;
      cin.ignore( 1000, '\n' );
      cout << "Enter your full name (press Enter to end): ";
      getline( cin,cppName );
   } 
}
