#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LENGTH 50

typedef struct {
    char name[MAX_CHAR_LENGTH];
    char type[MAX_CHAR_LENGTH];
    int age;
} fish_t;

void setFish(fish_t *f, char n[], char t[],int a);
void swapFish(fish_t **a, fish_t **b);

int main() {
    fish_t f = {"Nemo","clownfish", 2};
    fish_t b = {"Frank","Guppy", 8};

    fish_t *fPtr = &f;
    fish_t *bPtr = &b;
    
    printf("fPtr:\n");
    printf("Name: %s\n Type: %s\n Age: %d\n",fPtr->name, fPtr->type, fPtr->age);
    
    printf("bPtr:\n");
    printf("Name: %s\n Type: %s\n Age: %d\n",bPtr->name, bPtr->type, bPtr->age);
   
    swapFish(&fPtr,&bPtr);

    printf("fPtr:\n");
    printf("Name: %s\n Type: %s\n Age: %d\n",fPtr->name, fPtr->type, fPtr->age);
    
    printf("bPtr:\n");
    printf("Name: %s\n Type: %s\n Age: %d\n",bPtr->name, bPtr->type, bPtr->age);
    return 0;
}

void setFish(fish_t *f, char n[], char t[],int a) {
    strcpy(f->name,n);
    strcpy(f->type,t);
    f->age = a;
}

void swapFish(fish_t **a, fish_t **b) {
    fish_t *temp = *a;
    *a = *b;
    *b = temp;
}