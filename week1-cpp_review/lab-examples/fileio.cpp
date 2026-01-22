#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Movie
{
    char title[50];
};

void lowercaseEverything(char w[]);
void printMovies(Movie m[], int n);
void printMovie(Movie &m);

int main() {

    Movie movies[5];
    char filename[25];
    
    //file variable
    ifstream inFile;

    //ask for file name
    cout << "Enter input file name: ";
    cin >> filename;

    //open the file
    inFile.open(filename);

    if(inFile.fail()) {
        cout << "File does not exist" << endl;
        return 0;
    }

    char c;
    inFile.get(c); //attempt to get a char from the file
    if(inFile.eof()) {
        cout << "File is empty" << endl;
        return 0;
    }

    //if it's not empty, put back the character I grabbed before
    inFile.putback(c);
    int counter = 0;
    while (inFile.getline(movies[counter].title,50))
    {
        counter++;
    }

    for(int i=0;i < counter;i++) {
        cout << movies[i].title << endl;
    }
    
    //loop over each movie title in the movies array and make all
    // of them lowercase
    for(int i=0;i < counter;i++) {
        lowercaseEverything(movies[i].title);
    }

    //print everything again to see the changes
    printMovies(movies,count);

    return 0;
}

/* lowercaseEverything: lowercase all letters in w
    alters the actual parameter
    Parameters:
    w - the char array to modify
    Returns: nothing
*/
void lowercaseEverything(char w[]) {
    //loop over every letter in w
    for(int i=0; i< strlen(w);i++) {
        //assign the lowercase version of the letter 
        ///back into its original position in the array
        w[i] = tolower(w[i]);
    }
}

/*print all the movie titles in array m
  Parameters:
    m: array of Movies to print
    n: number of valid movies inside of m
  Returns: nothing
*/
void printMovies(Movie m[], int n) {
    for(int i=0;i < n;i++) {
        cout << m[i].title << endl;
    }
}