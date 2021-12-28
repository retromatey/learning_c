#include <stdio.h>

// Get rid of '\0' at the end of full_name and rerun it.  Run it under the
// debugger too.  Now, move the definition of full_name to the top of main
// before areas.  Try running it under the debugger a few times and see if you
// get some new errors.  In some cases, you might still get lucky and not catch
// any errors.

int main(int argc, char *argv[]) {
    char full_name[] = { 'J', 'o', 'e', ' ', 'E', '.', ' ', 'G', 'u', 'y' };
    int areas[] = { 10, 12, 13, 14, 20 };
    char name[] = "Joe";
    //char full_name[] = { 'J', 'o', 'e', ' ', 'E', '.', ' ', 'G', 'u', 'y', '\0' };

    // WARNING: on some systems you may have to change the %ld in this code to
    // %u since it will use unsigned ints

    printf("The size of an int: %ld\n", sizeof(int));
    printf("The size of areas (int[]): %ld\n", sizeof(areas));
    printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
    printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
    printf("The size of a char: %ld\n", sizeof(char));
    printf("The size of name (char[]): %ld\n", sizeof(name));
    printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
    printf("The size of full_name (char[]): %ld\n", sizeof(full_name));
    printf("The number of chars: %ld\n", sizeof(full_name) / sizeof(char));
    printf("name=\"%s\" and full_name=\"%s\"\n", name, full_name);

    return 0;
}
