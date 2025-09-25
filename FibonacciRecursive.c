#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int recursive_fib(int n) {
    if (n <= 1) {
        return n;
    }
    return recursive_fib(n - 1) + recursive_fib(n - 2);
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the value of n for Recursive Fibonacci: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Input cannot be negative.\n");
        return 1;
    }

    printf("\nCalculating Recursive Fibonacci for n = %d...\n", n);

    start = clock();
    long long int result = recursive_fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Result: %lld\n", result);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
