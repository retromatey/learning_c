#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"

#define MAX_SIZE 250

//int copy_strings(int size, char **out_array) {
int copy_strings(int size, char ***out_array) {
    **out_array = malloc(size * sizeof(char *));
    check_mem(**out_array);

    int i = 0;

    for (i = 0; i < size; i++) {
        *(out_array+i) = malloc(10 * sizeof(char));
        **(out_array+i) = "a";
    }

    for (i = 0; i < size; i++) {
        printf("%d - %s\n", i, **(out_array+i));
        //printf("%d - %s\n", i, *(my_argv[i]));
    }

    return 0;

error:
    /*
    if (*out_array) {
        free(*out_array);
    }

    *out_array = NULL;
    */
    return -1;
}

int main(int argc, char *argv[]) {
    int rows = argc;
    int i = 0;
    printf("%ld\n", rows * sizeof(int *));
    int **my_argv = malloc(rows * sizeof(int *));
    check_mem(**my_argv);
    for (i = 0; i < rows; i++) {
        //my_argv[i] = malloc(MAX_SIZE * sizeof(char));
        //my_argv[i] = malloc(1 * sizeof(int));
        //check_mem(my_argv[i]);
        //*(my_argv+i) = i;
        //*my_argv[i] = i;
        //printf("%d - %d", i, *my_argv[i]);
    }

    free(*my_argv);

error:
    if (*my_argv) {
        free(*my_argv);
    }

    *my_argv = NULL;
    return -1;

    /*
    //char *my_argv[3];
    char **my_argv = NULL;
    int i = 0;
    copy_strings(3, &my_argv);
    for (i = 0; i < 3; i++) {
        //printf("%d - %s\n", i, my_argv[i]);
        //printf("%d - %s\n", i, *(my_argv+i));
        //printf("%d - %d\n", i, *(my_argv+i));
        //printf("%d - %s\n", i, *(my_argv[i]));
    }
    */
    
    /*
    char **my_argv = NULL;
    my_argv = calloc(argc, 250);
    int i = 0;
    for (i = 0; i < argc; i++) {
        //my_argv[i] = argv[i];     // this works to, maybe more readable?
        *(my_argv+i) = argv[i];
        printf("%d - %s\n", i, argv[i]);
    }

    printf("\noutput my_argv\n");
    
    for (i = 0; i < argc; i++) {
        //printf("%d - %s\n", i, my_argv[i]);
        printf("%d - %s\n", i, *(my_argv+i));
    }
    */

    /*
    char *my_argv[argc];
    *my_argv = calloc(argc, 250);

    int i = 0;
    for (i = 0; i < argc; i++) {
        my_argv[i] = argv[i];
        printf("%d - %s\n", i, argv[i]);
    }

    printf("\noutput my_argv\n");
    
    for (i = 0; i < argc; i++) {
        printf("%d - %s\n", i, my_argv[i]);
    }
    */
    

    /*
    int i = 0;
    int size = 3;
    char **str_array = NULL;

    copy_strings(size, &str_array);

    for (i = 0; i < size; i++) {
        printf("%d is %s\n", i, str_array[i]);
    }
    */

    return 0;
}
