#include <iostream>
using namespace std;

void merge(int vet[], int temp[], int i, int mid, int f, int *p)
{
    for (size_t k = i; k <= f; k++)
    {
        temp[k] = vet[k];
    }

    int left = i;
    int right = mid + 1;

    for (size_t k = i; k <= f; k++)
    {
        if (left > mid)
        {
            vet[k] = temp[right++];
        }
        else if (right > f)
        {
            vet[k] = temp[left++];
            (*p)++;
        }
        else if (temp[left] < temp[right])
        {
            vet[k] = temp[left++];
        }
        else
        {
            vet[k] = temp[right++];
        }
    }
}

void mergeSort(int vet[], int temp[], int i, int f, int *p)
{
    if (i < f)
    {
        int mid = (i + f) / 2;

        mergeSort(vet, temp, i, mid, p);
        mergeSort(vet, temp, mid + 1, f, p);

        merge(vet, temp, i, mid, f, p);
    }
}

void printVet(int vet[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

int main()
{
    int global_count = 0;
    int *p = &global_count;

    int vet[] = {23, 41, 64, 85, 31, 72, 67, 49, 25, 12, 97, 13, 60, 85, 12, 30};
    int size = sizeof(vet) / sizeof(int);
    int temp[size];

    cout << "Before Merge" << endl;
    printVet(vet, size);

    mergeSort(vet, temp, 0, size - 1, p);

    cout << "\nAfter Merge" << endl;
    printVet(vet, size);

    cout << "\nComplexity MergeSort: " << *p << endl;
    return 0;
}