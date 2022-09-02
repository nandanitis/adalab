#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int low, int mid, int high)
{
    int i, j, k;
    int b[10000];
    i = low;
    j = mid + 1;
    k = low;
    while ((i <= mid) && (j <= high))
    {
        if (a[i] < a[j])
        {
            b[k] = a[i];
            i++;
            k++;
        }
        else
        {
            b[k] = a[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    for (i = low; i <= high; i++)
        a[i] = b[i];
}

void mergesort(int c[],int low,int high)
{
    int mid;
    mid = (low + high) / 2;
    if (low < high)
    {
        mergesort(c, low, mid);
        mergesort(c, mid + 1, high);
        merge(c, low, mid, high);
    }
}

int main()
{
    clock_t st, en;
    int n, i;
    printf("Enter the size of the array : ");
    scanf("%d", &n);
    int a[n];
    for (i = 0; i < n; i++)
    {
        a[i] = rand()%1000;
    }
    st = clock();
    mergesort(a, 0, n - 1);
    en = clock();
    printf("The sorted array elements are\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    float u;
    u = (en - st);
    printf("The total time taken by merge sort in seconds is %f", u);
    return 0;
}