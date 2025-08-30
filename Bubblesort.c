#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void generaterandomarray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100000;
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    int *copy = (int*)malloc(n * sizeof(int));

    generaterandomarray(arr, n);

    clock_t start = clock();
    for (int i = 0; i < 1000; i++) {
        for (int j = 0; j < n; j++)
            copy[j] = arr[j];

        bubbleSort(copy, n);
    }
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Average time taken per sort (Bubble) = %f seconds\n", timetaken);

    free(arr);
    free(copy);
    return 0;
}