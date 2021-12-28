#include <stdio.h>

// Assign numbers into name, trying to treat it like an array of int and print
// it out one int at a time.  What does the debugger think of that?
//
// There was no compiler warnings, the program continued to run like there was
// no issues.

int main(int argc, char *argv[]) {
    int numbers[4] = { 0 };
    char name[4] = { 'a' };

    // first, print them out raw
    printf("numbers: %d %d %d %d\n", 
            numbers[0], numbers[1], numbers[2], numbers[3]);

    printf("name each: %c %c %c %c\n", 
            name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    // set up the numbers
    numbers[0] = 1;
    numbers[1] = 2;
    numbers[2] = 3;
    numbers[3] = 4;

    // set up the name
    name[0] = 1;
    name[1] = 2;
    name[2] = 3;
    name[3] = 4;

    // then print them out initialized
    printf("numbers: %d %d %d %d\n", 
            numbers[0], numbers[1], numbers[2], numbers[3]);

    //printf("name each: %c %c %c %c\n", 
    //        name[0], name[1], name[2], name[3]);
    printf("name each: %d %d %d %d\n", 
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
