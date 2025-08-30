#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    clock_t start, end;
    int n;
    const int RUNS = 100; 

    printf("How many random numbers in your array?\n");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    int *original_array = (int*)malloc(n * sizeof(int));
    int *working_array = (int*)malloc(n * sizeof(int));

    if (original_array == NULL || working_array == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    srand(time(NULL)); 

    for (int i = 0; i < n; i++) {
        original_array[i] = rand() % 100000;
    }

    start = clock();

    for (int i = 0; i < RUNS; i++) {
        memcpy(working_array, original_array, n * sizeof(int));
        insertionSort(working_array, n);
    }

    end = clock();

    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTime taken to sort %d elements %d times: %f seconds\n", n, RUNS, time_taken);
    printf("Average time per sort: %f seconds\n", time_taken / RUNS);

    free(original_array);
    free(working_array);

    return 0;
}

