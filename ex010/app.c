#include <stdio.h>

// a 97
// z 122
// A 65
// Z 90
// diff 32

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("ERROR: You need at least one argument.\n");
        return 1;
    }

    int j = 0;
    int i = 0;
    int counter = 0;

    for (j = 1; j < argc; j++) {

        for (i = 0; argv[j][i] != '\0'; i++) {
            char letter = argv[j][i];

            // Covert uppercase letters to lowercase
            if (letter >= 65 && letter <= 90) {
                letter += 32;
            }

            switch (letter) {
                case 'a':
                //case 'A':
                    printf("%d: 'A'\n", counter);
                    break;

                case 'e':
                //case 'E':
                    printf("%d: 'E'\n", counter);
                    break;

                case 'i':
                //case 'I':
                    printf("%d: 'I'\n", counter);
                    break;

                case 'o':
                //case 'O':
                    printf("%d: 'O'\n", counter);
                    break;

                case 'u':
                //case 'U':
                    printf("%d: 'U'\n", counter);
                    break;

                case 'y':
                //case 'Y':
                    if (i > 2) {
                        // It's only sometimes Y
                        printf("%d: 'Y'\n", counter);
                    }
                    break;

                default:
                    printf("%d: %c is not a vowel\n", counter, letter);
            }

            counter += 1;
        }
    }

    return 0;
}
