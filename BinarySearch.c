 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>
 // Binary Search Function
 int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
 }
 // Comparison function for qsort
 int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
 }
 int main() {
    int n, result;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(0));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
    }
    qsort(arr, n, sizeof(int), compare);
    int target = rand() % 1000;
    printf("Random key to search: %d\n", target);
    clock_t start = clock();
    for (int i = 0; i < 1000000; i++) {
        result = binarySearch(arr, n, target);
    }
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC / 1000000.0;
    if (result != -1)
        printf("Element %d found at index %d\n", target, result);
    else
        printf("Element %d not found\n", target);
    printf("Average time for binary search: %f milliseconds\n", time_taken * 1000);
    free(arr);
    return 0;
}