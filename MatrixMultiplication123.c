#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int** allocatematrix(int n)
{
    int** a = (int**)malloc(n * sizeof(int*));
    for(int i = 0;i < n;i++)
    {
        a[i] = (int*)malloc(sizeof(int) * n);
    }
    return a;
}
void generatematrix(int** a,int n)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            a[i][j] = rand() % 10;
        }
    }
}
void freemat(int** a,int n)
{
    if(a == NULL)
    return;
    for(int i = 0;i < n;i++)
    {
        free(a[i]);
    }
    free(a);
}
void multiplyMatrices(int **matA, int **matB, int **result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
void add(int** a,int** b,int** c,int n)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            c[i][j] = a[i][j] + b[i][j];
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

void mm(int** a,int** b,int** c,int n)
{
    if(n == 1)
    {
        c[0][0] = a[0][0] * b[0][0];
        return;
    }

    int k = n/2;
    int** a11 = allocatematrix(k);
    int** a12 = allocatematrix(k);
    int** a21 = allocatematrix(k);
    int** a22 = allocatematrix(k);
    int** b11 = allocatematrix(k);
    int** b12 = allocatematrix(k);
    int** b21 = allocatematrix(k);
    int** b22 = allocatematrix(k);
    int i,j;
    for(i = 0;i < k;i++)
    {
        for(j = 0;j < k;j++)
        {
            a11[i][j] = a[i][j];
            a12[i][j] = a[i][j+k];
            a21[i][j] = a[i+k][j];
            a22[i][j] = a[i+k][j+k];
            b11[i][j] = b[i][j];
            b12[i][j] = b[i][j+k];
            b21[i][j] = b[i+k][j];
            b22[i][j] = b[i+k][j+k];
        }
    }
    int** c11 = allocatematrix(k);
    int** c12 = allocatematrix(k);
    int** c21 = allocatematrix(k);
    int** c22 = allocatematrix(k);
    int** temp1 = allocatematrix(k);
    int** temp2 = allocatematrix(k);

    mm(a11,b11,temp1,k);
    mm(a12,b21,temp2,k);
    add(temp1,temp2,c11,k);

    mm(a11,b12,temp1,k);
    mm(a12,b22,temp2,k);
    add(temp1,temp2,c12,k);

    mm(a21,b11,temp1,k);
    mm(a22,b21,temp2,k);
    add(temp1,temp2,c21,k);

    mm(a21,b12,temp1,k);
    mm(a22,b22,temp2,k);
    add(temp1,temp2,c22,k);

    for(i = 0;i < k;i++)
    {
        for(j = 0;j < k;j++)
        {
            c[i][j] = c11[i][j];
            c[i][j+k] = c12[i][j];
            c[i+k][j] = c21[i][j];
            c[i+k][j+k] = c22[i][j];
        }
    }
    freemat(a11,k);
    freemat(a12,k);
    freemat(a21,k);
    freemat(a22,k);
    freemat(b11,k);
    freemat(b12,k);
    freemat(b21,k);
    freemat(b22,k);
    freemat(c11,k);
    freemat(c12,k);
    freemat(c21,k);
    freemat(c22,k);
    freemat(temp1,k);
    freemat(temp2,k);
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
    
    add(A11, A22, tempA,newSize);
    add(B11, B22, tempB,newSize);
    strassenMultiply(newSize, tempA, tempB, P1);

    add(A21, A22, tempA,newSize);
    strassenMultiply(newSize, tempA, B11, P2);

    subtract(newSize,B12, B22, tempB);
    strassenMultiply(newSize,A11, tempB, P3);

    subtract(newSize, B21, B11, tempB);
    strassenMultiply(newSize, A22, tempB, P4);

    add(A11, A12, tempA,newSize);
    strassenMultiply(newSize, tempA, B22, P5);

    subtract(newSize, A21, A11, tempA);
    add(B11, B12, tempB,newSize);
    strassenMultiply(newSize, tempA, tempB, P6);

    subtract(newSize, A12, A22, tempA);
    add(B21, B22, tempB,newSize);
    strassenMultiply(newSize, tempA, tempB, P7);

    add(P1, P4, tempA,newSize);
    subtract(newSize, tempA, P5, tempB);
    add(tempB, P7, C11,newSize);

    add(P3, P5, C12,newSize);
    
    add(P2, P4, C21,newSize);

    subtract(newSize, P1, P2, tempA);
    add(tempA, P3, tempB,newSize);
    add(tempB, P6, C22,newSize);

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
void print(int** a,int n)
{
    for(int i = 0;i < n;i++)
    {
        for(int j = 0;j < n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    srand(time(0));
    int n;
    printf("Enter a N x N Matrix of size 2^N\n");
    scanf("%d",&n);
    //printf("Enter choice for matrix multiplication\n1 for iterative\n2 for recursive\n3 for strassen\n");
    int t;
    //scanf("%d",&t);
    int** a = allocatematrix(n);
    int** b = allocatematrix(n);
    int** c = allocatematrix(n);
    generatematrix(a,n);
    generatematrix(b,n);
    clock_t start1,end1,start2,end2,start3,end3;
    start1 = clock();
    multiplyMatrices(a,b,c,n);
    end1 = clock();
    start2 = clock();
    mm(a,b,c,n);
    end2 = clock();
    start3 = clock();
    strassenMultiply(n,a,b,c);
    end3 = clock();
    double timetaken1 = ((double)end1 - start1) / CLOCKS_PER_SEC;
    double timetaken2 = ((double)end2 - start2) / CLOCKS_PER_SEC; 
    double timetaken3 = ((double)end3 - start3) / CLOCKS_PER_SEC;
    printf("Time taken for iterative: %lf\n",timetaken1);
    printf("Time taken for recursive: %lf\n",timetaken2);
    printf("Time taken for strassen: %lf\n",timetaken3);
    freemat(a,n);
    freemat(b,n);
    freemat(c,n);
    return 0;
}