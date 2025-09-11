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
    int** a = allocatematrix(4);
    int** b = allocatematrix(4);
    int** c = allocatematrix(4);
    generatematrix(a,4);
    generatematrix(b,4);
    mm(a,b,c,4);
    print(a,4);
    print(b,4);
    print(c,4);
    freemat(a,4);
    freemat(b,4);
    freemat(c,4);
    return 0;
}