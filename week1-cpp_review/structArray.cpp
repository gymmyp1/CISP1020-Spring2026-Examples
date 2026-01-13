#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Define the Cookie structure
struct Cookie
{
   string type;
   double price;
   bool icing;
};

// Function prototypes
int readCookie(ifstream& input, Cookie cArray[]);
void printCookie(Cookie cArray[], int count);

int main() {
    const int MAX_SIZE = 10;
    Cookie cArray[MAX_SIZE];
    
    // Attempt to open the input file
    ifstream inputFile("cookies.txt");
    
    if (!inputFile) {
        cerr << "Error: Could not open the file 'cookies.txt'." << endl;
        return 1;
    }

    // Call readCookie (precondition: file is already open)
    int count = readCookie(inputFile, cArray);
    
    inputFile.close();

    // Call printCookie to display the results
    if (count > 0) {
        printCookie(cArray, count);
    } else {
        cout << "No data was found in the file." << endl;
    }

    return 0;
}

/**
 * Reads at most 10 Cookie from the file.
 * Returns the actual number of Cookie read.
 */
int readCookie(ifstream& input, Cookie cArray[]) {
    int i = 0;
    char c;
    // Read while there is space in the array and data in the file
    while (i < 10 && input >> cArray[i].type >> cArray[i].price >> c) {
        (c == 'Y') ? cArray[i].icing = true : cArray[i].icing = false;
        i++;
    }
    return i;
}

/**
 * Prints the data in a formatted table.
 */
void printCookie(Cookie cArray[], int count) {
    cout << "--- Cookie Records ---\n";
    // Table Rows
    for (int i = 0; i < count; i++) {
        cout << cArray[i].type << " " << cArray[i].price << " " << (cArray[i].icing ? "Iced" : "Not iced") << endl;
    }
}