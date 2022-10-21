#include <iostream>
using namespace std;

int global_count = 0;

void merge(int vet[], int temp[], int i, int mid, int f)
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
        }
        else if (temp[left] < temp[right])
        {
            vet[k] = temp[left++];
        }
        else
        {
            vet[k] = temp[right++];
        }
        global_count++;
    }
}

void mergeSort(int vet[], int temp[], int i, int f)
{
    if (i < f)
    {
        int mid = (i + f) / 2;

        mergeSort(vet, temp, i, mid);
        mergeSort(vet, temp, mid + 1, f);

        merge(vet, temp, i, mid, f);
    }
}

int main()
{
    int vet[] = {4, 7, 1, 9, 3, 0};
    int size = sizeof(vet) / sizeof(int);
    int temp[size];

    mergeSort(vet, temp, 0, size - 1);

    for (int i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }

    cout << "\nComplexity MergeSort: " << global_count << endl;
    return 0;
}