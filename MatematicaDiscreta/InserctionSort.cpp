#include <iostream>
using namespace std;

int global_count = 0;

void printVet(int vet[], int size)
{

    for (int i = 0; i < size; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << endl;
}

int inserctionSort(int vet[], int i, int size)
{
    int value = vet[i];
    int j = i;

    while (j > 0 && vet[j - 1] > value)
    {
        vet[j] = vet[j - 1];
        j--;
        global_count++;
    }

    vet[j] = value;

    if (global_count > 0)
    {
        global_count++;
    }

    if (i + 1 <= size)
    {
        inserctionSort(vet, i + 1, size);
    }
    return global_count;
}

int main()
{
    int vet[] = {23, 41, 64, 85, 31, 72, 67, 49, 25, 12, 97, 13, 60, 85, 12, 30};
    int size = sizeof(vet) / sizeof(int);

    cout << "Before InserctionSort" << endl;
    printVet(vet, size);

    global_count = inserctionSort(vet, 1, size - 1);

    cout << "\nAfter InserctionSort" << endl;
    printVet(vet, size);

    cout << "\nComplexity InserctionSort: " << global_count << endl;
    return 0;
}