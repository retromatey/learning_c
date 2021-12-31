#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Rework these functions so that you have fewer functions.  For example, do you
// really need can_print_it?

// Have print_arguments figure out how long each argument string is by using the
// strlen function, and then pass that length to print_letters.  Then, rewrite
// print_letters so it only processes this fixed length and doesn't rely on the
// '\0' terminator.  You'll need the #include <string.h> for this.

// forward declarations
//int can_print_it(char ch);
void print_letters(char arg[], int argLen);

void print_arguments(int argc, char *argv[]) {
    int i = 0;

    for (i = 0; i < argc; i++) {
        int argLen = strlen(argv[i]);
        print_letters(argv[i], argLen);
    }
}

void print_letters(char arg[], int argLen) {
    int i = 0;

    //for (i = 0; arg[i] != '\0'; i++) {
    for (i = 0; i < argLen; i++) {
        char ch = arg[i];

        if (isalpha(ch) || isblank(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

//int can_print_it(char ch) {
//    return isalpha(ch) || isblank(ch);
//}

int main(int argc, char *argv[]) {
    print_arguments(argc, argv);
    return 0;
}
