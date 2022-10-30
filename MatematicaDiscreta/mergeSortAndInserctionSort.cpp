#include "bits/stdc++.h"
#include <time.h>
using namespace std;

long long countInserction = 0, countMerge = 0;

void printVet(long long vet[], long long size)
{

    for (long long i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

long long merge(long long arr[], long long l, long long mid, long long r)
{
    long long inv = 0;
    long long n1 = mid - l + 1;
    long long n2 = r - mid;
    long long a[n1];
    long long b[n2];
    for (long long i = 0; i < n1; i++)
    {
        a[i] = arr[l + i];
    }

    for (long long i = 0; i < n2; i++)
    {
        b[i] = arr[mid + i + 1];
    }
    long long i = 0, j = 0, k = l;
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

long long mergeSort(long long arr[], long long l, long long r)
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

long long inserctionSort(int vet2[], int i, int size)
{
    int value = vet2[i];
    int j = i;

    while (j > 0 && vet2[j - 1] > value)
    {
        vet2[j] = vet2[j - 1];
        j--;
        countInserction++;
    }

    vet2[j] = value;

    if (countInserction > 0)
    {
        countInserction++;
    }

    if (i + 1 <= size)
    {
        inserctionSort(vet2, i + 1, size);
    }
    return countInserction;
}

int32_t main()
{

    // long long arr[] = {23, 41, 64, 85, 31, 72, 67, 49, 25, 12, 97, 13, 60, 85, 12, 30};
    long long arr[50];
    long long size = sizeof(arr) / sizeof(long long);

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

    long long microsecondsMerge = std::chrono::duration_cast<std::chrono::microseconds>(endMerge).count();

    auto startInserction = std::chrono::high_resolution_clock::now();
    countInserction = inserctionSort(arr2, 1, size - 1);
    auto endInserction = std::chrono::high_resolution_clock::now() - startInserction;

    long long microsecondsInserction = std::chrono::duration_cast<std::chrono::microseconds>(endInserction).count();

    cout << "\nAfter Order" << endl;
    printVet(arr, size);

    cout << "\nComplexity MergeSort: " << countMerge << endl;
    cout << "Time MergeSort: " << microsecondsMerge << " mS" << endl;

    cout << "\nComplexity InserctionSort: " << countInserction << endl;
    cout << "Time InserctionSort: " << microsecondsInserction << " mS" << endl;

    return 0;
}