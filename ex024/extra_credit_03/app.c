#include <stdio.h>
#include "dbg.h"

// Fix the file so that input names get stripped of the trailing newline
// characters and any white space.
// 
// Dec Char                     
// ─────────────────────────────
// 0   NUL '\0' (null character)
// 9   HT  '\t' (horizontal tab)
// 10  LF  '\n' (new line)      
// 13  CR  '\r' (carriage ret)  
// 27  ESC (escape)             
// 32  SPACE                    

#define MAX_DATA 100

typedef enum EyeColor {
    BLUE_EYES, GREEN_EYES, BROWN_EYES, 
    BLACK_EYES, OTHER_EYES
} EyeColor;

const char *EYE_COLOR_NAMES[] = {
    "Blue", "Green", "Brown", "Black", "Other"
};

const int REMOVABLE_CHARS[] = {
    9,  // \t (horizontal tab)
    10, // \n (new line)
    13, // \r (carriage ret)
    27, // ESC (escape)
    32  // SPACE
};

typedef struct Person {
    int age;
    char first_name[MAX_DATA];
    char last_name[MAX_DATA];
    EyeColor eyes;
    float income;
} Person;

int main(int argc, char *argv[]) {
    Person you = {.age = 0};
    int i = 0;
    char *in = NULL;

    // From the man page for fgets
    // char *fgets(char *s, int size, FILE *stream);
    // fgets() reads in at most one less than size characters from stream and
    // stores them into the buffer pointed to by s.  Reading stops after an EOF
    // or a newline.   If  a newline  is read, it is stored into the buffer.  A
    // terminating null byte ('\0') is stored after the last character in the
    // buffer.

    // try to print out the variable in a loop to see each char?
    printf("Before input\n");
    for (i = 0; i < MAX_DATA; i++) {
        printf("%d %c %d | ", i, you.first_name[i], you.first_name[i]);
    }

    // Make a function to print out the string
    // Make a function to do trim

    //printf("What's your First Name? ");
    printf("\nWhat's your First Name? ");
    in = fgets(you.first_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read first name.");

    printf("\nAfter input, before trim\n");
    for (i = 0; i < MAX_DATA; i++) {
        printf("%d %c %d | ", i, you.first_name[i], you.first_name[i]);
    }

    int j = 0;
    for (i = 0; i < MAX_DATA; i++) {
        for (j = 0; j < 5; j++) {
            if ((int)you.first_name[i] == REMOVABLE_CHARS[j]) {
                you.first_name[i] = 0;
            }
        }
    }
    printf("\n\nAfter trim\n");
    for (i = 0; i < MAX_DATA; i++) {
        printf("%d %c %d | ", i, you.first_name[i], you.first_name[i]);
    }

    /*
    printf("What's your Last Name? ");
    in = fgets(you.last_name, MAX_DATA - 1, stdin);
    check(in != NULL, "Failed to read last name.");

    printf("How old are you? ");
    int rc = fscanf(stdin, "%d", &you.age);
    check(rc > 0, "You have to enter a number.");

    printf("What color are your eyes:\n");

    for (i = 0; i <= OTHER_EYES; i++) {
        printf("%d) %s\n", i + 1, EYE_COLOR_NAMES[i]);
    }

    printf("> ");

    int eyes = -1;
    rc = fscanf(stdin, "%d", &eyes);
    check(rc > 0, "You have to enter a number.");
    you.eyes = eyes - 1;
    check(you.eyes <= OTHER_EYES && you.eyes >= 0, "Do it right, that's not an option.");

    printf("How much do you make an hour? ");
    rc = fscanf(stdin, "%f", &you.income);
    check(rc > 0, "Enter a floating point number.");

    printf("----- RESULTS -----\n");

    printf("First Name: %s", you.first_name);
    printf("Last Name: %s", you.last_name);
    printf("Age: %d\n", you.age);
    printf("Eyes: %s\n", EYE_COLOR_NAMES[you.eyes]);
    printf("Income: %f\n", you.income);
    */

    return 0;

error:
    return -1;
}
