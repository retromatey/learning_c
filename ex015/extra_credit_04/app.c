#include <stdio.h>

// Rewrite this program to use a function for each of the ways you're printing
// out things.  Try to pass pointers to these functions so that they work on the
// data.  Remember you can declare a function to accept a pointer, but just use
// it like an array.

void ex_func_01(char **names_ptr, int *age_ptr, int count) {
    int i = 0;

    printf("Using ex_func_01\n");

    for (i = 0; i < count; i++) {
        printf("%s is %d years old.\n", 
                *(names_ptr + i), *(age_ptr + i));
    }
}

int main(int argc, char *argv[]) {
    // create two arrays we care about 
    int ages[] = { 23, 43, 12, 89, 2 };
    char *names[] = {
        "Alan", "Frank", "Mary", "John", "Lisa"
    };

    // safely get the size of ages
    int count = sizeof(ages) / sizeof(int);
    int i = 0;

    // first way using indexing
    for (i = 0; i < count; i++) {
        printf("%s has %d years alive.\n", names[i], ages[i]);
    }

    printf("---\n");

    // set up the pointers to the start of the arrays
    int *cur_age = ages;
    char **cur_name = names;

    // second way using pointers
    ex_func_01(cur_name, cur_age, count);
    //for (i = 0; i < count; i++) {
    //    printf("%s is %d years old.\n", 
    //            *(cur_name + i), *(cur_age + i));
    //}

    printf("---\n");

    // third way, pointers are just arrays
    for (i = 0; i < count; i++) {
        printf("%s is %d years old again.\n", cur_name[i], cur_age[i]);
    }

    printf("---\n");

    // fourth way with pointers in a stupid complex way
    for (cur_name = names, cur_age = ages; 
            (cur_age - ages) < count; cur_name++, cur_age++) {
        printf("%s lived %d years so far.\n", *cur_name, *cur_age);
    }

    return 0;
}
