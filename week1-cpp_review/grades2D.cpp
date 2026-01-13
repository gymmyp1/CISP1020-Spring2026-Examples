/* File: grades2D.cpp
   Author: Cindy
   Description: demonstration of processing a 2D array
      and a 1D paraellel array
      Calculates averages
   Reads grades from standard in (can use redirection from a file to
      make input easier)
*/
#include <iostream>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 26;
const int NUM_TESTS = 3;

int readGrades( double[][NUM_TESTS] );
double calculateAverages( double[][NUM_TESTS], double[], int );
void printTable( double[][NUM_TESTS], double[], double, int );


int main()
{
   // 3 test grades per student 
   double grades[MAX_STUDENTS][NUM_TESTS];
   double averages[MAX_STUDENTS]; // each students test average
   int count = 0; // number of students
   double avg; // average of all student test averages
   
   count = readGrades( grades );
   avg = calculateAverages( grades, averages, count );
   printTable( grades, averages, avg, count ); 
   return( 0 );
}

/* readGrades: reads grades from standard input, NUM_TESTS at a time
 * Parameters:
 *    g 2D array of NUM_TESTS test grades per student
 * Returns: number of students (so, number of test grades/NUM_TESTS)
 */
int readGrades( double g[][NUM_TESTS] ) {
   int i = 0; // student count
   int j;
   
   // while not out of bounds in array and not eof
   while( i < MAX_STUDENTS && cin >> g[i][0]) {
      for( j = 1; j < NUM_TESTS; j++ ) {
         cin >> g[i][j];
      }
      i++;
   }
   return i;
}

/* calculateAverages: calculates every student's test average and 
 *    average of all test averages
 * Parameters:
 *    g 2D array of student test grades
 *    a 1D array of test averages
 *    n number of rows in g and a
 * Precondition: array g has n rows of NUM_TEST test grades
 * Postcondition: a is filled with averages of test grades in g
 * Returns: average of all test averages
 */
double calculateAverages( double g[][NUM_TESTS], double a[], int n) {
   int i, j;
   double sum; // sum of grades
   
   // calculate each student's test average
   for( i = 0; i < n; i++ ) {
      sum = 0;
      for( j = 0; j < NUM_TESTS; j++ ) {
         sum += g[i][j];
      }
      a[i] = sum/NUM_TESTS;
   }  

   // calculate average of averages and return
   for( i =0; i < n; i++ ) {
      sum += a[i];
   }
   return sum/n; // average grade
}

/* printTable: prints table of student test grades, averages and overall
 *   test average
 * Parameters:
 *    g 2D array of test grades
 *    a array of test averages
 *    avg average of test averages
 *    n number of row in g and a (number of students)
 */
void printTable( double g[][NUM_TESTS], double a[], double avg, int n ) {
   int i, j; 

   // print table heading
   cout << "Student Number     ";
   for( i = 0; i < NUM_TESTS; i++ ) {
      cout << "Test" << (i+1) << " ";
   }
   cout << "Average\n";
   cout << "-----------------";
   for( i = 0; i < NUM_TESTS; i++ ) {
      cout << "-------";
   } 
   cout << "-------\n";
   
   // print student test grades and averages
   cout.setf( ios::fixed | ios::showpoint );
   cout.precision( 1 );
   for( i = 0; i < n; i++ ) {
      cout << "Student " << setw(9) <<  left << i << " ";
      for( j = 0; j < NUM_TESTS; j++ ) {
         cout << setw(6) << right << g[i][j];
      }
      cout << " " << setw(5) << right <<  a[i] << endl;
   }
  
   // print average of averages
   cout << "Overall Average: " << avg << endl; 

}



