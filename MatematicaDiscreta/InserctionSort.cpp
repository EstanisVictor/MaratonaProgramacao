#include <iostream>
using namespace std;

int global_count = 0;

void inserctionSort(int vet[], int size)
{
    if (size <= 1)
        return;

    inserctionSort(vet, size - 1);

    for (size_t i = (size - 1); i > 0; i--)
    {
        if (vet[i - 1] > vet[i])
        {
            global_count++;
            swap(vet[i - 1], vet[i]);
        }
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
    int vet[] = {4, 7, 1, 9, 3, 0};
    int size = sizeof(vet) / sizeof(int);

    cout << "Before InserctionSort" << endl;
    printVet(vet, size);

    inserctionSort(vet, size);

    cout << "\nAfter InserctionSort" << endl;
    printVet(vet, size);

    cout << "\nComplexity InserctionSort: " << global_count << endl;
    return 0;
}