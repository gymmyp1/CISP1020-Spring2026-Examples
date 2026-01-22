#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int num = 50;

    //cout << "Setting the width using setw to 5:" << endl;
    cout << "|" << setw(5) << left << num << "|";

    return 0;
}