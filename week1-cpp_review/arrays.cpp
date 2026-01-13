/* File: arrays.cpp
 * Author: Cindy
 * Description: fills an array of at most 10 ints with random ints from [0,100]
 * Prints, sorts, prints
 */
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX = 10;


int fillArray( int[] );
void printArray( int[], int );
void sortArray( int[], int );
void swap( int&, int& );

int main() {
   int array[MAX];
   int count;

   count = fillArray( array );
   printArray( array, count );
   sortArray( array, count );
   cout << endl;
   printArray( array, count );

   return( 0 );

}

/* fillArray: fills array with at most 10 integers between 0 and 100
 * Parameters:
 *    a the array of integers
 * Returns: count of numbers put in the array
 */
int fillArray( int a[] ) { 
   srand(time(0));
   
   int i;
   // randomly generated number of elements in array 
   int n = rand()%MAX + 1; 
   for( i = 0; i < n; i++ ) {
      a[i] = rand()%100;
   }
   return n;
}

/* printArray: print array content
 * Parameters:
 * 	a array
 * 	n number of elements in array
 * Returns: nothing
 */
void printArray( int a[], int count ) {
   int i;
   for( i = 0; i < count; i++ ) {
      cout << a[i] << endl;
   }
}

/* sortArray: uses a selection sort to sort array a
 * Parameters
 * 	a array
 * 	n number of elements in array
 * Returns: nothing
 */
void sortArray( int a[], int count ) {
   int i, topIndex, minIndex, countMinus1 = count-1;

   for( topIndex = 0; topIndex < countMinus1; topIndex++ ) {
      // find the min from the "top" to the bottom
      minIndex = topIndex;
      for( i = minIndex+1; i < count; i++ ) {
         if( a[minIndex] > a[i] ) // we have a new min
            minIndex = i;
      }
      // swap the min with the "top"
      swap( a[minIndex], a[topIndex] );
   } 
}

/* swap: swaps two integers
 * Parameters:
 *    aRef first int, reference variable
 *    bRef second int, reference vaiable
 * Post-condition: actual parameter values are swapped
 * Returns: nothing
 */
void swap( int& aRef, int& bRef ) {
   int temp;
   temp = aRef;
   aRef = bRef;
   bRef = temp;
}
