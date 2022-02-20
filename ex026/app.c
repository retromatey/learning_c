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
    char **search_files = NULL;

    /***************************************************************************
     * Read in search terms, determine if the search is 'and' or 'or'.
     **************************************************************************/
    printf("\nReading search terms...\n");

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


    /***************************************************************************
     * Generate list of searchable files.
     **************************************************************************/
    printf("\nDetermining searchable files\n");

    debug("Attempting to open file ~/.logfind for reading");

    char file_path[90] = { 0 };
    const char *home_dir = getenv("HOME");
    check(home_dir != NULL, "Cannot determine home directory.");
    //debug("home_dir: %s", home_dir);
    strcat(file_path, home_dir);
    strcat(file_path, "/.logfind");
    //debug("file_path: %s", file_path);

    FILE *logfind_file = fopen(file_path, "r");
    check(logfind_file != NULL, "Failed to open file.");

    char line[90];
    debug("Read ~/.logfind contents:");

    while (feof(logfind_file) == 0) {
        fgets(line, 90, logfind_file);

        if (feof(logfind_file) == 0) {
            printf("\t%s", line);
        }
    }

    int close_file_status = fclose(logfind_file);
    check(close_file_status == 0, "Failed to close file.");

    /***************************************************************************
     * Free allocated memory.
     **************************************************************************/
    free(search_terms);

    return 0;

error:
    if (search_terms) {
        free(search_terms);
    }

    search_terms = NULL;

    return -1;
}
