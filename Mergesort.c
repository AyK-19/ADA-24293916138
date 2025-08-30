#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void merge(int a[],int left,int mid,int right)
{
    int i,j,k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *l = (int*)malloc(n1*4);
    int *r = (int*)malloc(n2*4);
    for(i = 0;i < n1;i++)
    l[i] = a[left + i];
    for(j = 0;j < n2;j++)
    r[j] = a[mid + 1 + j];
    i = j = 0;
    k = left;
    while(i < n1 && j < n2)
    {
        if(l[i] < r[j])
        a[k++] = l[i++];
        else
        a[k++] = r[j++];
    }
    while(i < n1)
    a[k++] = l[i++];
    while(j < n2)
    a[k++] = r[j++]; 
    free(l);
    free(r);
}
void mergesort(int a[],int l,int r)
{
    if(l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a,l,m);
        mergesort(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main()
{
    clock_t start,end;
    //int a[] = {4,52,5,6,2,2,5,32,42,56,2,5,36,758,564};
    int n;
    printf("how many random numbers in your array?\n");
    scanf("%d",&n);
    int a[n];
    for(int i = 0;i < n;i++)
    {
        a[i] = rand() % 100000;
    }
    int l = sizeof(a) / sizeof(a[0]);
    start = clock();
    for(int i = 0;i < 1000;i++)
    mergesort(a,0,l-1);
    //for(int i = 0;i < l;i++)
    //printf("%d ",a[i]);
    end = clock();
    double time_taken = ((double) (end - start)) / CLOCKS_PER_SEC / 1000.0;
    printf("\ntime taken is %lf\n",time_taken);
    return 0;
}
