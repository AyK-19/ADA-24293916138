#include <stdio.h>
#include <stdlib.h>
int fibo_iterative(int n)
{
    if(n <= 1)
    {
        return 0;
    }
    int a = 0,b = 1,c = 0;
    for(int i = 2;i <= n;i++)
    {
        c = a+b;
        a=b;
        b=c;
    }
    return c;
}
int fibo_recursive(int n)
{
    if(n == 0)
    return 0;
    if(n == 1)
    return 1;
    else
    return fibo_recursive(n-1) + fibo_recursive(n-2);
}
int fibo_topdown_recursive(int a[],int n)
{
    if(n<=1)
    {
        return 0;
    }
    if(a[n]!=0)
    {
        return a[n];
    }
    else
    {
        a[n] = fibo_topdown_recursive(a,n-1) + fibo_topdown_recursive(a,n-2);
    }
}
int fibo_topdown(int n)
{
    int* a = (int*)calloc(n+1,sizeof(int));
    if(a == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }
    int result = fibo_topdown_recursive(a,n);
    return result;
}
int fibo_bottomup(int n)
{
    int a[n];
    a[0] = 0, a[1] = 1;
    for(int i = 2;i <=n;i++)
    {
        a[i] = a[i-1] + a[i-2];
    }
    return a[n];
}
int main()
{
    printf("Enter\n1 for iterative\n2 for recursive\n3 for topdown\n4 for bottomup\n");
    int x,n,result;
    scanf("%d",&x);
    printf("Enter the value of n\n");
    scanf("%d",&n);
    if(x == 1)
    result = fibo_iterative(n);
    if(x == 2)
    result = fibo_recursive(n);
    if(x == 3)
    result = fibo_topdown(n);
    if(x == 4)
    result = fibo_bottomup(n);
    printf("nth fibonacci is:%d\n",result);
    return 0;
}