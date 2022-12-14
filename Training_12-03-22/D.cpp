#include <bits/stdc++.h>
#include <vector>
using namespace std;

int inserctionSort(double vet[], int i, int size)
{
    double value = vet[i];
    int j = i;

    while (j > 0 && vet[j - 1] < value)
    {
        vet[j] = vet[j - 1];
        j--;
    }

    vet[j] = value;

    if (i + 1 <= size)
    {
        inserctionSort(vet, i + 1, size);
    }
}

int main()
{
    int ins, n;
    cin >> ins;
    cin >> n;

    string nomes[ins];
    double tam[ins];
    double copia[ins];

    int size = sizeof(tam) / sizeof(double);

    vector<string> time;

    for (size_t i = 0; i < ins; i++)
    {
        cin >> nomes[i];
        cin >> tam[i];
        copia[i] = tam[i];
    }

    inserctionSort(tam, 1, size - 1);

    for (size_t i = 0; i < ins; i++)
    {
        
        for (size_t j = 0; j < ins; j++)
        {
            if(copia[i] == tam[j]){
                
            }
        }
        
    }
    

    return 0;
}
/*
5 3
Marcos 1.5
Joao 1.6
Marcelo 2.0
Heitor 1.8
Jose 1.7
*/