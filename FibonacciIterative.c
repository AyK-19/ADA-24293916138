#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int iterative_fib(int n) {
    if (n <= 1) {
        return n;
    }
    long long int a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the value of n for Iterative Fibonacci: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Input cannot be negative.\n");
        return 1;
    }

    printf("\nCalculating Iterative Fibonacci for n = %d...\n", n);

    start = clock();
    long long int result = iterative_fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Result: %lld\n", result);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
