#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// Convert this program to not use pointers and malloc.  
//   - How to create a struct on the stack, just like you're making any other
//     variable.
//   - How to initialize it using the x.y (period) character instead of the x->y
//     syntax.
//   - How to pass a structure to other functions without using a pointer.

struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

//struct Person *Person_create(char *name, int age, int height, int weight) {
struct Person Person_create(char *name, int age, int height, int weight) {
    //struct Person *who = malloc(sizeof(struct Person));
    struct Person who; 

    //assert(who != NULL);

    //who->name = strdup(name);
    who.name = strdup(name);
    //who->age = age;
    who.age = age;
    //who->height = height;
    who.height = height;
    //who->weight = weight;
    who.weight = weight;

    return who;
}

//void Person_destroy(struct Person *who) {
void Person_destroy(struct Person who) {
    //assert(who != NULL);
    //free(who->name);
    free(who.name);
    //free(who);
}

//void Person_print(struct Person *who) {
void Person_print(struct Person who) {
    //printf("Name: %s\n", who->name);
    printf("Name: %s\n", who.name);
    //printf("\tAge: %d\n", who->age);
    printf("\tAge: %d\n", who.age);
    //printf("\tHeight: %d\n", who->height);
    printf("\tHeight: %d\n", who.height);
    //printf("\tWeight: %d\n", who->weight);
    printf("\tWeight: %d\n", who.weight);
}

int main(int argc, char *argv[]) {
    //struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person joe = Person_create("Joe Alex", 32, 64, 140);
    //struct Person *frank = Person_create("Frank Blank", 20, 72, 180);
    struct Person frank = Person_create("Frank Blank", 20, 72, 180);

    //printf("Joe is at memory location %p:\n", joe);
    printf("Joe is at memory location %p:\n", &joe);
    Person_print(joe);

    //printf("Frank is at memory location %p:\n", frank);
    printf("Frank is at memory location %p:\n", &frank);
    Person_print(frank);

    joe.age += 20;
    joe.height -= 2;
    joe.weight += 40;
    Person_print(joe);

    frank.age += 20;
    frank.weight += 20;
    Person_print(frank);

    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
