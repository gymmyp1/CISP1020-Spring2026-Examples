#include <iostream>
using namespace std;

//function prototypes
double square(double x);
void swapByReference(int& iRef, int& jRef);
void swapByPointer(int* iPtr, int* jPtr);

int main() 
{
    // ----- Pass-by-value example -----
    double num = 5.0;
    double result = square(num);

    cout << "Pass-by-value example\n";
    cout << "Original num: " << num << endl;
    cout << "Result of square(num): " << result << endl;
    cout << "After function call, num is still: " << num << endl;
    cout << endl;

    // ----- Pass-by-reference example -----
    int a = 10;
    int b = 20;

    cout << "Pass-by-reference example\n";
    cout << "Before swap: a = " << a << ", b = " << b << endl;
    swapByReference(a, b);
    cout << "After swap:  a = " << a << ", b = " << b << endl;
    cout << endl;

    // ----- Pointer example -----
    int x = 30;
    int y = 40;

    cout << "Pointer example\n";
    cout << "Before swap: x = " << x << ", y = " << y << endl;
    swapByPointer(&x, &y);   // pass addresses
    cout << "After swap:  x = " << x << ", y = " << y << endl;

    return 0;
}


// ----------------------------
// Pass-by-value
// Just passes a copy; original is NOT changed
double square(double x)
{
    x = x * x;   // modifies only the local copy
    return x;
}

// ----------------------------
// Pass-by-reference (C++ only)
// Swaps the actual arguments
void swapByReference(int& iRef, int& jRef)
{
    int temp = iRef;
    iRef = jRef;
    jRef = temp;
}

// ----------------------------
// Pointers (C and C++)
// Swaps values via memory addresses
void swapByPointer(int* iPtr, int* jPtr)
{
    int temp = *iPtr;
    *iPtr = *jPtr;
    *jPtr = temp;
}
