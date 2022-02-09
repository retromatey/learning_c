#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dbg.h"

void change_var_value(int *p, int new_value) {
    *p = new_value;
    printf("\n------------------------------------------\n");
    printf("Variable | Address        | Value\n");
    printf("------------------------------------------\n");
    printf("      *p | %p | %p\n", &p, p);
    printf("------------------------------------------\n\n");
}

int main(int argc, char *argv[]) {

    int a = 100;
    int *ap = &a;
    int **app = &ap;

    //int b = 200;
    int *b = NULL;
    b = (int *)malloc(sizeof(int));
    *b = 500;
    printf("\n------------------------------------------\n");
    printf("Variable | Address        | Value\n");
    printf("------------------------------------------\n");
    printf("      *b | %p | %p\n", &b, b);
    printf("------------------------------------------\n\n");
    printf("*b is %d", *b);


    printf("\n------------------------------------------\n");
    printf("Variable | Address        | Value\n");
    printf("------------------------------------------\n");
    printf("       a | %p | %d\n", &a, a);
    printf("     *ap | %p | %p\n", &ap, ap);
    printf("    *app | %p | %p\n", &app, app);
    printf("------------------------------------------\n\n");

    printf("running change_var_value(&a, 200)\n");
    change_var_value(&a, 200);
    printf("\n------------------------------------------\n");
    printf("Variable | Address        | Value\n");
    printf("------------------------------------------\n");
    printf("       a | %p | %d\n", &a, a);
    printf("     *ap | %p | %p\n", &ap, ap);
    printf("    *app | %p | %p\n", &app, app);
    printf("------------------------------------------\n\n");

    printf("running change_var_value(ap, 300)\n");
    change_var_value(ap, 300);
    printf("\n------------------------------------------\n");
    printf("Variable | Address        | Value\n");
    printf("------------------------------------------\n");
    printf("       a | %p | %d\n", &a, a);
    printf("     *ap | %p | %p\n", &ap, ap);
    printf("    *app | %p | %p\n", &app, app);
    printf("------------------------------------------\n\n");

    /*
    printf("  a: %d\n", a);
    printf("*ap: %d\n", *ap);
    printf(" &a: %p\n", &a);
    printf(" ap: %p\n", ap);

    printf("\nperform *ap = 101\n\n");

    *ap = 101;

    printf("  a: %d\n", a);
    printf("*ap: %d\n", *ap);
    printf(" &a: %p\n", &a);
    printf(" ap: %p\n", ap);

    printf("\nperform *app = &b\n\n");

    *app = &b;

    printf("  a: %d\n", a);
    printf("*ap: %d\n", *ap);
    printf(" &a: %p\n", &a);
    printf(" ap: %p\n", ap);
    */

    return 0;
}
