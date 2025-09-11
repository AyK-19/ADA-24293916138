#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void add(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void subtract(int n, int **A, int **B, int **C) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void strassenMultiply(int n, int **A, int **B, int **C) {
    if (n == 1) {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int newSize = n / 2;
    int **A11, **A12, **A21, **A22;
    int **B11, **B12, **B21, **B22;
    int **C11, **C12, **C21, **C22;
    int **P1, **P2, **P3, **P4, **P5, **P6, **P7;
    int **tempA, **tempB;

    A11 = (int **)malloc(newSize * sizeof(int *));
    A12 = (int **)malloc(newSize * sizeof(int *));
    A21 = (int **)malloc(newSize * sizeof(int *));
    A22 = (int **)malloc(newSize * sizeof(int *));
    B11 = (int **)malloc(newSize * sizeof(int *));
    B12 = (int **)malloc(newSize * sizeof(int *));
    B21 = (int **)malloc(newSize * sizeof(int *));
    B22 = (int **)malloc(newSize * sizeof(int *));
    C11 = (int **)malloc(newSize * sizeof(int *));
    C12 = (int **)malloc(newSize * sizeof(int *));
    C21 = (int **)malloc(newSize * sizeof(int *));
    C22 = (int **)malloc(newSize * sizeof(int *));
    P1 = (int **)malloc(newSize * sizeof(int *));
    P2 = (int **)malloc(newSize * sizeof(int *));
    P3 = (int **)malloc(newSize * sizeof(int *));
    P4 = (int **)malloc(newSize * sizeof(int *));
    P5 = (int **)malloc(newSize * sizeof(int *));
    P6 = (int **)malloc(newSize * sizeof(int *));
    P7 = (int **)malloc(newSize * sizeof(int *));
    tempA = (int **)malloc(newSize * sizeof(int *));
    tempB = (int **)malloc(newSize * sizeof(int *));

    for (int i = 0; i < newSize; i++) {
        A11[i] = (int *)malloc(newSize * sizeof(int));
        A12[i] = (int *)malloc(newSize * sizeof(int));
        A21[i] = (int *)malloc(newSize * sizeof(int));
        A22[i] = (int *)malloc(newSize * sizeof(int));
        B11[i] = (int *)malloc(newSize * sizeof(int));
        B12[i] = (int *)malloc(newSize * sizeof(int));
        B21[i] = (int *)malloc(newSize * sizeof(int));
        B22[i] = (int *)malloc(newSize * sizeof(int));
        C11[i] = (int *)malloc(newSize * sizeof(int));
        C12[i] = (int *)malloc(newSize * sizeof(int));
        C21[i] = (int *)malloc(newSize * sizeof(int));
        C22[i] = (int *)malloc(newSize * sizeof(int));
        P1[i] = (int *)malloc(newSize * sizeof(int));
        P2[i] = (int *)malloc(newSize * sizeof(int));
        P3[i] = (int *)malloc(newSize * sizeof(int));
        P4[i] = (int *)malloc(newSize * sizeof(int));
        P5[i] = (int *)malloc(newSize * sizeof(int));
        P6[i] = (int *)malloc(newSize * sizeof(int));
        P7[i] = (int *)malloc(newSize * sizeof(int));
        tempA[i] = (int *)malloc(newSize * sizeof(int));
        tempB[i] = (int *)malloc(newSize * sizeof(int));
    }

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + newSize];
            A21[i][j] = A[i + newSize][j];
            A22[i][j] = A[i + newSize][j + newSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + newSize];
            B21[i][j] = B[i + newSize][j];
            B22[i][j] = B[i + newSize][j + newSize];
        }
    }
    
    add(newSize, A11, A22, tempA);
    add(newSize, B11, B22, tempB);
    strassenMultiply(newSize, tempA, tempB, P1);

    add(newSize, A21, A22, tempA);
    strassenMultiply(newSize, tempA, B11, P2);

    subtract(newSize, B12, B22, tempB);
    strassenMultiply(newSize, A11, tempB, P3);

    subtract(newSize, B21, B11, tempB);
    strassenMultiply(newSize, A22, tempB, P4);

    add(newSize, A11, A12, tempA);
    strassenMultiply(newSize, tempA, B22, P5);

    subtract(newSize, A21, A11, tempA);
    add(newSize, B11, B12, tempB);
    strassenMultiply(newSize, tempA, tempB, P6);

    subtract(newSize, A12, A22, tempA);
    add(newSize, B21, B22, tempB);
    strassenMultiply(newSize, tempA, tempB, P7);

    add(newSize, P1, P4, tempA);
    subtract(newSize, tempA, P5, tempB);
    add(newSize, tempB, P7, C11);

    add(newSize, P3, P5, C12);
    
    add(newSize, P2, P4, C21);

    subtract(newSize, P1, P2, tempA);
    add(newSize, tempA, P3, tempB);
    add(newSize, tempB, P6, C22);

    for (int i = 0; i < newSize; i++) {
        for (int j = 0; j < newSize; j++) {
            C[i][j] = C11[i][j];
            C[i][j + newSize] = C12[i][j];
            C[i + newSize][j] = C21[i][j];
            C[i + newSize][j + newSize] = C22[i][j];
        }
    }

    for (int i = 0; i < newSize; i++) {
        free(A11[i]); free(A12[i]); free(A21[i]); free(A22[i]);
        free(B11[i]); free(B12[i]); free(B21[i]); free(B22[i]);
        free(C11[i]); free(C12[i]); free(C21[i]); free(C22[i]);
        free(P1[i]); free(P2[i]); free(P3[i]); free(P4[i]);
        free(P5[i]); free(P6[i]); free(P7[i]);
        free(tempA[i]); free(tempB[i]);
    }
    free(A11); free(A12); free(A21); free(A22);
    free(B11); free(B12); free(B21); free(B22);
    free(C11); free(C12); free(C21); free(C22);
    free(P1); free(P2); free(P3); free(P4);
    free(P5); free(P6); free(P7);
    free(tempA); free(tempB);
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("Enter the size of the square matrices (N x N, N must be a power of 2): ");
    scanf("%d", &n);

    if (n <= 0 || (n & (n - 1)) != 0) {
        printf("Matrix size must be a positive integer and a power of 2.\n");
        return 1;
    }

    int **matA = (int **)malloc(n * sizeof(int *));
    int **matB = (int **)malloc(n * sizeof(int *));
    int **result = (int **)malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++) {
        matA[i] = (int *)malloc(n * sizeof(int));
        matB[i] = (int *)malloc(n * sizeof(int));
        result[i] = (int *)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matA[i][j] = i + j;
            matB[i][j] = i - j;
        }
    }

    start = clock();
    strassenMultiply(n, matA, matB, result);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nMatrix multiplication for a %d x %d matrix completed.\n", n, n);
    printf("Execution time: %f seconds\n", cpu_time_used);

    for (int i = 0; i < n; i++) {
        free(matA[i]);
        free(matB[i]);
        free(result[i]);
    }
    free(matA);
    free(matB);
    free(result);

    return 0;
}

