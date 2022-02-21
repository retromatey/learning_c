#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dbg.h"

int main(int argc, char *argv[]) {

    printf("\n**** START PROGRAM ****\n");

    int i = 0;
    int search_index = 0;
    int total_search_terms = 0;
    char **search_terms = NULL;
    char **search_files = NULL;
    bool is_or = false;

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
        debug("\tsearch_terms[%d] - %s", i, search_terms[i]);
    }


    /***************************************************************************
     * Generate list of searchable files.
     **************************************************************************/
    printf("\nDetermining searchable files\n");

    debug("Attempting to open file ~/.logfind for reading");

    int total_search_files = 0;
    int search_file_index = 0;
    char file_path[90] = { 0 };
    int close_file_status = 0;
    char line[250];

    const char *home_dir = getenv("HOME");
    check(home_dir != NULL, "Cannot determine home directory.");
    //debug("home_dir: %s", home_dir);
    strcat(file_path, home_dir);
    strcat(file_path, "/.logfind");
    //debug("file_path: %s", file_path);

    FILE *logfind_file = fopen(file_path, "r");
    check(logfind_file != NULL, "Failed to open file.");

    while (feof(logfind_file) == 0) {
        fgets(line, 250, logfind_file);

        if (feof(logfind_file) == 0) {
            total_search_files += 1;
        }
    }

    debug("total_search_files: %d", total_search_files);

    close_file_status = fclose(logfind_file);
    check(close_file_status == 0, "Failed to close file.");

    search_files = calloc(total_search_files, 250);
    check_mem(search_files);

    logfind_file = fopen(file_path, "r");
    check(logfind_file != NULL, "Failed to open file.");

    debug("Read ~/.logfind contents:");

    while (feof(logfind_file) == 0) {
        fgets(line, 250, logfind_file);

        if (feof(logfind_file) == 0) {
            search_files[search_file_index] = malloc(250 * sizeof(char));

            for (i = 0; i < 250; i++) {
                if (line[i] != '\n') {
                    search_files[search_file_index][i] = line[i];
                }
            }

            search_file_index += 1;
        }
    }

    close_file_status = fclose(logfind_file);
    check(close_file_status == 0, "Failed to close file.");

    debug("List search files:");

    for (i = 0; i < total_search_files; i++) {
        debug("\tsearch_files[%d] - %s", i, search_files[i]);
    }

    /***************************************************************************
     * Search log files for search terms
     **************************************************************************/
    printf("\nSearching files\n");

    int line_number = 0;
    char *match;

    for (i = 0; i < total_search_files; i++) {
        line_number = 0;
        FILE *search_file = fopen(search_files[i], "r");
        check(search_file != NULL, "Failed to open file.");

        while (feof(search_file) == 0) {
            fgets(line, 250, search_file);

            if (feof(search_file) == 0) {
                match = strstr(line, argv[1]);

                if (match != NULL) {
                    printf("%s[%d]: %s", search_files[i], line_number, line);
                }

                line_number += 1;
            }
        }

        close_file_status = fclose(search_file);
        check(close_file_status == 0, "Failed to close file.");
    }

    /***************************************************************************
     * Free allocated memory.
     **************************************************************************/
    free(search_terms);

    for (i = 0; i < total_search_files; i++) {
        free(search_files[i]);
    }

    free(search_files);

    return 0;

error:
    if (search_terms) {
        free(search_terms);
    }

    if (search_files) {
        for (i = 0; i < total_search_files; i++) {
            free(search_files[i]);
        }
        free(search_files);
    }

    search_terms = NULL;
    search_files = NULL;

    return -1;
}
