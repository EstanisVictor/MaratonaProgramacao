#include "bits/stdc++.h"
#include <time.h>
using namespace std;
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

void printVet(int vet[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

int32_t main()
{
    clock_t end, start;

    int arr[] = {23, 41, 64, 85, 31, 72, 67, 49, 25, 12, 97, 13, 60, 85, 12, 30};
    int n = sizeof(arr) / sizeof(int);

    cout << "Before Merge" << endl;
    printVet(arr, n);

    start = clock();
    cout << "\nComplexity MergeSort: " << mergeSort(arr, 0, n - 1) << endl;
    end = clock();

    cout << "\nAfter Merge" << endl;
    printVet(arr, n);

    cout << "Programa Executado em: " << 1000 * (double)(end - start) / (double)(CLOCKS_PER_SEC);
    return 0;
}