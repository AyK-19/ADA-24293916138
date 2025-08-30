#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

        quickSort(copy, 0, n - 1);
    }
    clock_t end = clock();

    double timetaken = ((double)(end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("Average time taken per sort (Quick) = %f seconds\n", timetaken);

    free(arr);
    free(copy);
    return 0;
}