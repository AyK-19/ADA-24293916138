#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int top_down_dp_fib_recursive(int n, long long int* fib_array) {
    if (n <= 1) {
        return n;
    }
    // Check if we have already computed it
    if (fib_array[n] != 0) {
        return fib_array[n];
    }
    // If not, compute and store it
    fib_array[n] = top_down_dp_fib_recursive(n - 1, fib_array) + top_down_dp_fib_recursive(n - 2, fib_array);
    return fib_array[n];
}

long long int top_down_dp_fib(int n) {
    if (n < 0) return -1;
    long long int* fib_array = (long long int*)calloc(n + 1, sizeof(long long int));
    if (fib_array == NULL) return -1; // Allocation failed
    long long int result = top_down_dp_fib_recursive(n, fib_array);
    free(fib_array);
    return result;
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the value of n for Top-Down DP Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Input cannot be negative.\n");
        return 1;
    }

    printf("\nCalculating Top-Down DP Fibonacci for n = %d...\n", n);
    
    start = clock();
    long long int result = top_down_dp_fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Result: %lld\n", result);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
