#include <iostream>
using namespace std;

int global_count = 0;

void ordena(int vet[], int tam)
{
    if (tam <= 1)
        return;

    ordena(vet, tam - 1);

    for (size_t i = (tam - 1); i > 0; i--)
    {
        if (vet[i - 1] > vet[i])
        {
            global_count++;
            swap(vet[i - 1], vet[i]);
        }
    }
}

int main()
{
    int vet[] = {4, 7, 1, 9, 3, 0};
    int tam = sizeof(vet) / sizeof(int);

    ordena(vet, tam);

    for (int i = 0; i < tam; i++)
    {
        cout << "[" << vet[i] << "]";
    }
    cout << "\nSua complexidade: " << global_count << endl;
    return 0;
}