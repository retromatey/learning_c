#include <stdio.h>

// Trying to break this program:
// Set the initializer to { 'a', 'a', 'a', 'a' } so that there are too many 'a'
// characters and no space for the '\0' terminator.
//
// No compiler warning.
// The program ran as if there were no issues.

int main(int argc, char *argv[]) {
    char name[4] = { 'a', 'a', 'a', 'a' };

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

    // another way to use name
    char *another = "Tom";

    printf("another: %s\n", another);

    printf("another each: %c %c %c %c\n", 
            another[0], another[1], another[2], another[3]);

    return 0;
}
