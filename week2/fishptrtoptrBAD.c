//Showing an intentionally broken swap
#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LENGTH 50

typedef struct {
    char name[MAX_CHAR_LENGTH];
    char type[MAX_CHAR_LENGTH];
    int age;
} fish_t;

void swapFish(fish_t *a, fish_t *b);  //changed this to be pointer to fish_t
int main() {
    fish_t f = {"Nemo","clownfish", 2};
    fish_t b = {"Frank","Guppy", 8};

    fish_t *fPtr = &f;
    fish_t *bPtr = &b;
    
    printf("Before swap:\n");
    printf("fPtr: %s\n", fPtr->name);
    printf("bPtr: %s\n\n", bPtr->name);

    swapFish(fPtr, bPtr);   // removed the &

    printf("After swap (nothing should have changed bc swap is written wrong):\n");
    printf("fPtr: %s\n", fPtr->name);
    printf("bPtr: %s\n", bPtr->name);

    return 0;
}

void swapFish(fish_t *a, fish_t *b) {
    fish_t *temp = a;
    a = b;
    b = temp;
}
