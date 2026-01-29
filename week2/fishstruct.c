#include <stdio.h>
#include <string.h>

#define MAX_CHAR_LENGTH 50

typedef struct {
    char name[MAX_CHAR_LENGTH];
    char type[MAX_CHAR_LENGTH];
    int age;
} fish_t;

void setFish(fish_t *f, char n[], char t[],int a);

int main() {
    fish_t f;

    setFish(&f,"Nemo", "Clownfish",2);

    printf("Name: %s\n Type: %s\n Age: %d\n",f.name, f.type, f.age);
    return 0;
}

void setFish(fish_t *f, char n[], char t[],int a) {
    strcpy(f->name,n);
    strcpy(f->type,t);
    f->age = a;
}
