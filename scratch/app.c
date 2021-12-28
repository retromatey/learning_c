#include <stdio.h>

int main(int argc, char *argv[]) {

    // a 97
    // z 122
    // A 65
    // Z 90
    // diff 32

    char a = 'a';
    char A = 'A';
    char z = 'z';
    char Z = 'Z';
    int diff = a - A;

    printf("%c %d\n", a, a);
    printf("%c %d\n", z, z);
    printf("%c %d\n", A, A);
    printf("%c %d\n", Z, Z);
    printf("diff %d\n", diff);

    return 0;
}
