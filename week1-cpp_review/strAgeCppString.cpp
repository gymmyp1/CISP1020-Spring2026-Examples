/* File: strAgeC-string.cpp 
   Author: Cindy Arnold
   Description: get birth month, day, year from user and calc age
      using C++ String objects
   See http://www.cplusplus.com/reference/ctime/tm/ and
   http://www.cplusplus.com/reference/ctime/localtime/ 
   for info on getting the system time/date
*/
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

bool isInteger( string );

int main()
{
   // c++ strings of user-entered birth month, day, year
   string strMonth, strDay, strYear;
   // int versions of user-entered birth month, day, year
   int intMonth, intDay, intYear;
   int age;
  
   time_t rawtime; // seconds since 00:00 Jan 1 1970 GMT
   struct tm *timeInfo; // structure with month, etc.
   int currentDay;
   int currentMonth;
   int currentYear;

   //  get current day/time
   time( &rawtime );
   timeInfo = localtime( &rawtime );
   currentDay = timeInfo->tm_mday;
   currentMonth = timeInfo->tm_mon + 1; // tm_mon has Jan as 0 
   currentYear = timeInfo->tm_year + 1900; // tm_year = years since 1900

   // get birth month, day and year from user
   cout << "Enter birth month (Jan = 1, Dec = 12): ";
   getline( cin, strMonth );
   cout << "Enter birth day (i.e., 1 for the first day of the month): ";
   getline( cin, strDay );
   cout << "Enter birth year: ";
   getline( cin, strYear );
   cout << "You entered: " << strMonth << "/" << strDay << "/"
      << strYear << endl;


   // if user-entered birth month, day and year are valid, positive ints
   // compute age
   if ( isInteger( strMonth ) && isInteger( strDay ) && isInteger( strYear ) ) {
      intMonth= stoi( strMonth );
      intDay = stoi( strDay);
      intYear = stoi( strYear);
      age = currentYear - intYear;
      // if bday hasn't happened yet, subtract one from age
      if ( intMonth > currentMonth ) age--;
      else if ( intMonth == currentMonth && intDay > currentDay ) age--;
      else if ( intMonth == currentMonth && intDay == currentDay )
         cout << "Happy Birthday!\n";
      cout << "You are " << age << " years old.\n";
   }
   else {
      cout << "Invalid input. Month, day and year must be integers.\n";
   }

   return( 0 );
}

/* isInteger: determines whether parameter C++ string s contains a 
 *    valid, positive integer (no + sign)
 * Parameters:
 *    s the C++ string
 * Returns: true if s is a valid, positive int with no +
 */
bool isInteger( string s ) {
   int i;
   int length = s.length();
   for( i = 0; i < length; i++ ) {
      if ( !isdigit( s[i] ))  {
         return false;
      }
   }
   return true;
}
