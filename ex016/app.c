#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// What do the additional header files above provide?
// - stdio.h:
//   - printf: console output
// - assert.h:
//   - assert: conditional checks for development purposes
// - stdlib.h: 
//   - malloc: allocate memory for an object
//   - free: deallocates a piece of memory
// - string.h: 
//   - NULL: the integer constant 0
//   - strdup: ? not defined in my C reference book

// Define a data structure for a Person with properties that define a person.
struct Person {
    char *name;
    int age;
    int height;
    int weight;
};

// This function will return a pointer to a Person data structure the the
// properties of the Person data structure populated with the parameters passed
// into the function.
struct Person *Person_create(char *name, int age, int height, int weight) {
    // Allocate memory for a Person data structure.
    struct Person *who = malloc(sizeof(struct Person));

    // Check if the Person pointer was created properly. Abort operation if the
    // pointer is equal to NULL.
    assert(who != NULL);

    // Populate the Person properties with the args passed to this function.
    // Perform a string copy of the name arg.
    who->name = strdup(name);
    who->age = age;
    who->height = height;
    who->weight = weight;

    return who;
}

// This function will deallocate the memory for a Person data structure.
void Person_destroy(struct Person *who) {
    // Check that the Person pointer arg is valid, abort operation if it is NULL
    assert(who != NULL);

    // Deallocate the memory for the name string data
    free(who->name);

    // Deallocate the memory for the Person data
    free(who);
}

// This function will print out the properties of a Person data structure.
void Person_print(struct Person *who) {
    printf("Name: %s\n", who->name);
    printf("\tAge: %d\n", who->age);
    printf("\tHeight: %d\n", who->height);
    printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[]) {
    // make two people structures
    struct Person *joe = Person_create("Joe Alex", 32, 64, 140);
    struct Person *frank = Person_create("Frank Blank", 20, 72, 180);

    // print them out and where they are in memory
    printf("Joe is at memory location %p:\n", joe);
    Person_print(joe);

    printf("Frank is at memory location %p:\n", frank);
    Person_print(frank);

    // make everyone age 20 years and print them again
    joe->age += 20;
    joe->height -= 2;
    joe->weight += 40;
    Person_print(joe);

    frank->age += 20;
    frank->weight += 20;
    Person_print(frank);

    // destroy them both so we clean up
    Person_destroy(joe);
    Person_destroy(frank);

    return 0;
}
