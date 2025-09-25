#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long long int bottom_up_dp_fib(int n) {
    if (n < 0) return -1;
    if (n == 0) return 0;
    long long int* dp = (long long int*)malloc((n + 1) * sizeof(long long int));
    if (dp == NULL) return -1; // Allocation failed
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    long long int result = dp[n];
    free(dp);
    return result;
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the value of n for Bottom-Up DP Fibonacci: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Input cannot be negative.\n");
        return 1;
    }

    printf("\nCalculating Bottom-Up DP Fibonacci for n = %d...\n", n);

    start = clock();
    long long int result = bottom_up_dp_fib(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    
    printf("Result: %lld\n", result);
    printf("Time taken: %f seconds\n", cpu_time_used);
    
    return 0;
}
