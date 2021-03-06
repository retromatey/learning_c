#include <stdio.h>

// Trying to break this program:
// Get rid of the initializers that set up name
//
// The compiler gave a warning when attempting to build this file.
// output results:
// name each: ý     
// name: ý
// name each: T o m  
// name: Tom

int main(int argc, char *argv[]) {
    //char name[4] = { 'a' };
    char name[4];

    printf("name each: %c %c %c %c\n", 
            name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    // set up the name
    name[0] = 'T';
    name[1] = 'o';
    name[2] = 'm';
    name[3] = '\0';

    printf("name each: %c %c %c %c\n", 
            name[0], name[1], name[2], name[3]);

    // print the name like a string
    printf("name: %s\n", name);

    return 0;
}
