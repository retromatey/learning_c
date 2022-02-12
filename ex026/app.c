#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dbg.h"

const char *OR_ARG = "-o";

int read_search_terms(
        int argc, 
        char *argv[], 
        int *out_argc,
        char **search_terms[],
        int *out_is_or) {
    // return an array of strings to search for
    // ignore -o if it is found
    // probably will need to know the size of the return array
    // probabl cannot return this array from the function...

    int i = 0;
    *out_argc = 0;
    *out_is_or = 0;
    search_terms = calloc(3, 250);
    int search_term_index = 0;
    check_mem(search_terms);

    for (i = 1; i < argc; i++) {
        debug("Search term %d is [%s]", i, argv[i]);
        int is_or_arg = strcmp(argv[i], OR_ARG);

        if (is_or_arg != 0) {
            *out_argc += 1;
            search_terms[search_term_index] = argv[i];
            debug("test input %d %s", search_term_index, search_terms[search_term_index]);
            search_term_index += 1;

        } else {
            *out_is_or = 1;
        }

    }

    return 0;

error:

    if (search_terms) {
        free(search_terms);
    }

    search_terms = NULL;

    return -1;
}


int main(int argc, char *argv[]) {

    int i = 0;
    int search_terms_count = 0;
    char *search_terms[250];
    int use_or = 0;

    read_search_terms(argc, argv, &search_terms_count, &search_terms, &use_or);

    debug("Total search terms: %d", search_terms_count);
    debug("Using or: %d", use_or);

    for (i = 0; i < search_terms_count; i++) {
        debug("Search term %d is %s", i, search_terms[i]);
    }

    free(*search_terms);

    return 0;
}
