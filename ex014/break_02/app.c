#include <stdio.h>
#include <ctype.h>

// When you call print_arguments inside main, try adding 1 to argc so that it
// goes past the end of the argv array.

// forward declarations
int can_print_it(char ch);
void print_letters(char arg[]);

void print_arguments(int argc, char *argv[]) {
    int i = 0;

    for (i = 0; i < argc; i++) {
        print_letters(argv[i]);
    }
}

void print_letters(char arg[]) {
    int i = 0;

    for (i = 0; arg[i] != '\0'; i++) {
        char ch = arg[i];

        if (can_print_it(ch)) {
            printf("'%c' == %d ", ch, ch);
        }
    }

    printf("\n");
}

int can_print_it(char ch) {
    return isalpha(ch) || isblank(ch);
}

int main(int argc, char *argv[]) {
    argc += 1;
    print_arguments(argc, argv);
    return 0;
}
