#include <stdio.h>

// If an array of characters is 4 bytes long, and an integer is 4 bytes long,
// then can you treat the whole name array like it's just an integer?  How might
// you accomplish this crazy hack?
// 8 bits in a byte - 4 bytes -> 32 bits

int main(int argc, char *argv[]) {
    char name[4] = { 'a' };
    int name_int = name;

    // first, print them out raw
    printf("name each: %c %c %c %c\n", 
            name[0], name[1], name[2], name[3]);

    printf("name: %s\n", name);

    printf("name (int): %d\n", name);
    printf("name_int: %d\n,", name_int);

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
