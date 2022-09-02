#include<bits/stdc++.h>
#include <windows.h>
#include <unistd.h>
#include <time.h>
#include<iostream>

using namespace std;

int partition(int a[], int low, int high)
{
    int i = low + 1, j = high, key = a[low], b[10000], temp;
    while (1)
    {
        Sleep(1);
        while (a[i] <= key && i < high)
            i++;
        while (a[j] > key)
            j--;
        if (i < j)
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
        else
        {
            temp = a[low];
            a[low] = a[j];
            a[j] = temp;
            return j;
        }
    }
}
void quicksort(int a[], int low, int high)
{
    int j;
    if (low < high)
    {
        j = partition(a, low, high);
        quicksort(a, low, j - 1);
        quicksort(a, j + 1, high);
    }
}
int main()
{
    int n, a[10000], i;
    cout << endl
         << "Enter array size : ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 1000;
    }

    clock_t start = clock();
    quicksort(a, 0, n - 1);
    clock_t endd = clock();
    cout << endl
         << "array after sorting" << endl;
    for (i = 0; i < n; i++)
    {
        cout << " " << a[i];
    }
    cout << endl
         << "total time is" << (double)(endd - start) / CLK_TCK;
}