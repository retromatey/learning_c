#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

// Write another sorting algorithm, then change test_sorting so that it takes
// both an arbitrary sort function and the sort function's callback comparison.
// Use it to test both of your algorithms.
// I'll use selection sort from algorithms pg 249

void die(const char *message) {

    if (errno) {
        perror(message);

    } else {
        printf("ERROR: %s\n", message);
    }

    exit(1);
}

// A typedef creates a fake type, in this case for a function pointer.
typedef int (*compare_cb) (int a, int b);

typedef int *(*sort_cb) (int *numbers, int count, compare_cb cmp);

int *selection_sort(int *numbers, int count, compare_cb cmp) {
    int temp = 0;
    int i = 0;
    int j = 0;
    int swap_index = 0;
    int array_size = count * sizeof(int);
    int *numbers_copy = malloc(array_size);

    if (!numbers_copy) {
        die("Memory error.");
    }

    memcpy(numbers_copy, numbers, array_size);

    for (i = 0; i < count; i++) {
        swap_index = i;

        for (j = i+1; j < count; j++) {

            if (cmp(numbers_copy[swap_index], numbers_copy[j]) > 0) {
                swap_index = j;
            }
        }

        temp = numbers_copy[i];
        numbers_copy[i] = numbers_copy[swap_index];
        numbers_copy[swap_index] = temp;
    }

    return numbers_copy;
}

// A classic bubble sort function that uses the compare_cb to do the sorting.
int *bubble_sort(int *numbers, int count, compare_cb cmp) {
    int temp = 0;
    int i = 0;
    int j = 0;
    int *target = malloc(count * sizeof(int));

    if (!target) {
        die("Memory error.");
    }

    memcpy(target, numbers, count * sizeof(int));

    for (i = 0; i < count; i++) {
        
        for (j = 0; j < count - 1; j++) {

            if (cmp(target[j], target[j + 1]) > 0) {
                temp = target[j + 1];
                target[j + 1] = target[j];
                target[j] = temp;
            }
        }
    }

    return target;
}

int sorted_order(int a, int b) {
    return a - b;
}

int reverse_order(int a, int b) {
    return b - a;
}

// Used to test that we are storing things correctly by doing the sort and
// printing it out.
void test_sorting(int *numbers, int count, compare_cb cmp, sort_cb sorter) {
    int i = 0;
    //int *sorted = bubble_sort(numbers, count, cmp);
    int *sorted = sorter(numbers, count, cmp);

    if (!sorted) {
        die("Failed to sort as requested.");
    }

    for (i = 0; i < count; i++) {
        printf("%d ", sorted[i]);
    }

    printf("\n");

    free(sorted);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        die("USAGE: ex18 4 3 1 5 ");
    }

    int count = argc - 1;
    int i = 0;
    char **inputs = argv + 1;

    int *numbers = malloc(count * sizeof(int));

    if (!numbers) {
        die("Memory error.");
    }

    for (i = 0; i < count; i++) {
        numbers[i] = atoi(inputs[i]);
    }

    printf("Sorted order | bubble sort\n");
    test_sorting(numbers, count, sorted_order, bubble_sort);

    printf("Sorted order | selection sort\n");
    test_sorting(numbers, count, sorted_order, selection_sort);

    printf("\n");

    printf("Reverse order | bubble sort\n");
    test_sorting(numbers, count, reverse_order, bubble_sort);

    printf("Reverse order | selection sort\n");
    test_sorting(numbers, count, reverse_order, selection_sort);

    free(numbers);

    return 0;
}
