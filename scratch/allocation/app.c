#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dbg.h"

struct Logfind_model {
    int total_search_terms;
    char **search_terms;
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

        free(model);
    }

    model = NULL;
}

void Logfind_model_summary(struct Logfind_model *model) {
    int i = 0;

    debug("\tmodel->total_search_terms: %d", model->total_search_terms);
    debug("\tis_or: %s", model->is_or == 0 ? "false" : "true");

    for (i = 0; i < model->total_search_terms; i++) {
        debug("\t\tsearch_term[%d] - %s", i, model->search_terms[i]);
    }
}

int main(int argc, char *argv[]) {
    int is_valid = validate(argc, argv);
    check(is_valid == 0, "Error found, terminating program");

    struct Logfind_model *model = Logfind_model_init(argc, argv);
    check_mem(model);

    Logfind_model_summary(model);

    Logfind_model_destroy(model);

    return 0;

error:
    return -1;
}
