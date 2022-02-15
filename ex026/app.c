#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dbg.h"

int main(int argc, char *argv[]) {

    printf("\n**** START PROGRAM ****\n\n");

    int i = 0;
    int search_index = 0;
    int total_search_terms = 0;
    char **search_terms = NULL;
    bool is_or = false;

    for (i = 1; i < argc; i++) {

        if (strcmp(argv[i], "-o") == 0) {
            is_or = true;

        } else {
            total_search_terms += 1;
        }
    }

    search_terms = calloc(total_search_terms, 250);
    check_mem(search_terms);

    for (i = 1; i < argc; i++) {

        if (strcmp(argv[i], "-o") != 0) {
            search_terms[search_index] = argv[i];
            search_index += 1;
        } 
    }

    debug("total_search_terms: %d", total_search_terms);
    debug("is_or: %s", is_or ? "true" : "false");
    debug("List search terms:");

    for (i = 0; i < total_search_terms; i++) {
        debug("\ttotal_search_terms[%d] - %s", i, search_terms[i]);
    }


    free(search_terms);

    return 0;

error:
    if (search_terms) {
        free(search_terms);
    }

    search_terms = NULL;

    return -1;
}
