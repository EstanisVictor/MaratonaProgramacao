#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cont = 0, maior = 0;
    int vet[10];
    vector<int> armazena;

    for (size_t i = 0; i < 10; i++)
    {
        cin >> vet[i];
    }

    for (size_t i = 0; i < 10; i++)
    {
        for (size_t j = i; j < 10; j++)
        {
            if (j < 10)
            {
                if (vet[j] < vet[j + 1] && vet[j + 1] > maior)
                {
                    maior = vet[i + 1];
                    cont++;
                }
            }
        }
        cout << cont << endl;
        armazena.push_back(cont);
        cont = 0;
        maior = 0;
    }

    for (size_t i = 0; i < armazena.size(); i++)
    {
        if (armazena[i] > maior)
        {
            maior = armazena[i];
        }
    }
    cout << "\n"
         << maior;
    return 0;
}
