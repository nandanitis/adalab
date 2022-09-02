#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;
void SelectionSort(int a[], int n)
{
    int Min, temp;
    for (int i = 0; i < n - 1; i++)
    {
        Min = i;
        for (int j = i + 1; j < n; j++)
        {
            Sleep(1);
            if (a[j] < a[Min])
            {
                Min = j;
            }
        }
            temp = a[Min];
            a[Min] = a[i];
            a[i] = temp;
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand()%1000;
    int s = clock();
    SelectionSort(a, n);
    int e = clock();
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\nTime: " << (double)(e - s) / CLOCKS_PER_SEC << "s";
    return 0;
}