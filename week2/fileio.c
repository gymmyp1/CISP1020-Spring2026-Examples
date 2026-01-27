#include <stdio.h>

int main() {
	FILE *in; //declare file variable
	char name[50];

	in = fopen("names.dat", "r"); //open file in read mode

	//read from file as long as one name was read
	//fscanf stops at whitespace
	while(fscanf(in, "%s", name)  == 1) {
		printf("Name read: %s\n", name);
		//fflush(stdout); //make sure the printf statment on previous line prints
	}

	//ALTERNATIVE: read from file until fgets returns NULL, which is what happens when EOF is reached
	// fgets reads until \n.
	/*while(fgets(name, 50, in)) {
		printf("Name read: %s\n", name);
	}*/

	return 0;
}