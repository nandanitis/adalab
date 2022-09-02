#include <iostream>
#include <time.h>
#include <windows.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;   // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
    int s = clock();
    heapSort(a, n);
    int e = clock();
    cout << "Sorted array is \n";
    printArray(a, n);
    cout << "\nTime: " << (double)(e - s) / CLOCKS_PER_SEC << "s";
}
