 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 // Linear Search Function
 int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i; // Return the index of the found element
        }
    }
    return -1; // Element not found
 }
 int main() {
    int n, target, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    // Generate random numbers
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }
    // Random target
    target = rand() % 1000;
    printf("Random key to search: %d\n", target);
    // Start time
    clock_t start = clock();
    for (int i = 0; i < 10000; i++) {
        result = linearSearch(arr, n, target);
    }
    // End time
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC / 10000.0; 
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);
    printf("Average time for linear search: %f milliseconds\n", time_taken * 1000);
    free(arr);
    return 0;
 }