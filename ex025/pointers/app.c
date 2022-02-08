#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "dbg.h"

int main(int argc, char *argv[]) {

    int a = 100;
    int *ap = &a;
    int **app = &ap;

    int b = 200;

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

    return 0;
}
