#include "bits/stdc++.h"
#include <time.h>
using namespace std;

long long countMerge = 0;

void printVet(int vet[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

long long merge(int arr[], int l, int mid, int r)
{
    long long inv = 0;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    int a[n1];
    int b[n2];
    for (int i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (int i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 and j < n2)
    {
        if (a[i] <= b[j])
        {
            arr[k] = a[i];
            k++;
            i++;
        }
        else
        {
            arr[k] = b[j];
            inv += n1 - i;
            k++;
            j++;
        }
    }
    while (i < n1)
    {
        arr[k] = a[i];
        k++;
        i++;
    }
    while (j < n2)
    {
        arr[k] = b[j];
        k++;
        j++;
    }
    return inv;
}

long long mergeSort(int arr[], int l, int r)
{
    long long inv = 0;
    if (l < r)
    {
        int mid = (l + r) / 2;
        inv += mergeSort(arr, l, mid);
        inv += mergeSort(arr, mid + 1, r);
        inv += merge(arr, l, mid, r);
    }
    return inv;
}

void insertionSort(int array[], int size, long long *countInserction)
{
    for (int step = 1; step < size; step++)
    {
        int key = array[step];
        int j = step - 1;
        while (key < array[j] && j >= 0)
        {
            array[j + 1] = array[j];
            --j;
            (*countInserction)++;
        }
        array[j + 1] = key;

        if (*countInserction > 0)
        {
            (*countInserction)++;
        }
    }
}

int main()
{

    // int arr[] = {3, 1, 4, 5, 10, 8, 11, 0, 16, 2, 7, 9, 6, 15, 14, 12};
    int arr[10];
    int size = sizeof(arr) / sizeof(int);

    long long countInserction = 0;

    srand(time(NULL));

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }

    int arr2[size];

    copy(arr, arr + size, arr2);

    cout << "Before Order" << endl;
    printVet(arr, size);

    auto startMerge = std::chrono::high_resolution_clock::now();
    countMerge = mergeSort(arr, 0, size - 1);
    auto endMerge = std::chrono::high_resolution_clock::now() - startMerge;

    int microsecondsMerge = std::chrono::duration_cast<std::chrono::microseconds>(endMerge).count();

    auto startInserction = std::chrono::high_resolution_clock::now();
    insertionSort(arr2, size, &countInserction);
    auto endInserction = std::chrono::high_resolution_clock::now() - startInserction;

    int microsecondsInserction = std::chrono::duration_cast<std::chrono::microseconds>(endInserction).count();

    cout << "\nAfter Order" << endl;
    printVet(arr, size);

    cout << "\nSwap Merge Sort: " << countMerge << endl;
    cout << "Time Merge Sort: " << microsecondsMerge << " mS" << endl;

    cout << "\nSwap Inserction Sort: " << countInserction << endl;
    cout << "Time Inserction Sort: " << microsecondsInserction << " mS" << endl;

    return 0;
}