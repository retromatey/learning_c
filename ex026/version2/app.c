#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

struct Logfind_model {
    int total_search_terms;
    char **search_terms;
    int total_search_files;
    char **search_files;
    int is_or;
};

int validate(int argc, char *argv[]) {

    if (argc <= 1) {
        printf("Arguments required, ex: logfind word1 word2.\n\n");
        return -1;

    } else if (argc == 2 && strstr(argv[1], "-o")) {
        printf("Arguments required, ex: logfind -o word1 word2.\n\n");
        return -1;
    }

    return 0;
}

struct Logfind_model *Logfind_model_init(int argc, char *argv[]) {
    struct Logfind_model *model = malloc(sizeof(struct Logfind_model));
    check_mem(model);

    int i = 0;

    char *or_arg = strstr(argv[1], "-o");
    model->is_or = or_arg != NULL;

    int arg_option_offset = model->is_or == 0 ? 1 : 2;

    model->total_search_terms = argc - arg_option_offset;
    model->search_terms = calloc(model->total_search_terms, 250);

    model->total_search_files = 0;

    for (i = 0; i < model->total_search_terms; i++) {
        model->search_terms[i] = strdup(argv[i+arg_option_offset]);
    }

    return model;

error:
    if (model) {

        if (model->search_terms) {
            free(model->search_terms);
        }

        free(model);
    }

    model = NULL;

    return model;
}

void Logfind_model_destroy(struct Logfind_model *model) {
    int i = 0;

    if (model) {

        if (model->search_terms) {

            for (i = 0; i < model->total_search_terms; i++) {
                free(model->search_terms[i]);
            }

            free(model->search_terms);
        }

        if (model->search_files) {

            for (i = 0; i < model->total_search_files; i++) {
                free(model->search_files[i]);
            }

            free(model->search_files);
        }

        free(model);
    }

    model = NULL;
}

void Logfind_model_summary(struct Logfind_model *model) {
    int i = 0;

    debug("\tmodel->total_search_terms: %d", model->total_search_terms);

    for (i = 0; i < model->total_search_terms; i++) {
        debug("\t\tsearch_term[%d] - %s", i, model->search_terms[i]);
    }

    debug("\tis_or: %s", model->is_or == 0 ? "false" : "true");

    for (i = 0; i < model->total_search_files; i++) {
        debug("\t\tsearch_files[%d] - %s", i, model->search_files[i]);
    }
}

int Logfind_init_search_files(struct Logfind_model *model) {
    model->total_search_files = 0;
    int search_file_index = 0;
    int close_file_status = 0;
    char line[250];
    int i = 0;

    FILE *logfind_file = fopen(".logfind", "r");
    check(logfind_file != NULL, "Failed to open file.");

    while (feof(logfind_file) == 0) {
        fgets(line, 250, logfind_file);

        if (feof(logfind_file) == 0) {
            model->total_search_files += 1;
        }
    }

    close_file_status = fclose(logfind_file);
    check(close_file_status == 0, "Failed to close file.");

    model->search_files = calloc(model->total_search_files, 250);
    check_mem(model->search_files);

    logfind_file = fopen(".logfind", "r");
    check(logfind_file != NULL, "Failed to open file.");

    while (feof(logfind_file) == 0) {
        fgets(line, 250, logfind_file);

        if (feof(logfind_file) == 0) {
            model->search_files[search_file_index] = malloc(250 * sizeof(char));
            check_mem(model->search_files[search_file_index]);

            for (i = 0; i < 250; i++) {
                if (line[i] != '\n') {
                    model->search_files[search_file_index][i] = line[i];
                }
            }

            search_file_index += 1;
        }
    }

    close_file_status = fclose(logfind_file);
    check(close_file_status == 0, "Failed to close file.");

    return 0;

error:
    return -1;
}

int main(int argc, char *argv[]) {
    int is_valid = validate(argc, argv);
    check(is_valid == 0, "Error found, terminating program");

    struct Logfind_model *model = Logfind_model_init(argc, argv);
    check_mem(model);

    int search_file_result = Logfind_init_search_files(model);
    check(search_file_result == 0, "Error: search files not resolved");

    Logfind_model_summary(model);

    Logfind_model_destroy(model);

    return 0;

error:
    return -1;
}
