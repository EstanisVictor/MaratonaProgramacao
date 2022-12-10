#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    while (n != 0)
    {
        int vet[n], maior1 = 0, maior2 = 0;
        for (size_t i = 0; i < n; i++)
        {
            cin >> vet[i];
        }

        for (size_t i = 0; i < n; i++)
        {
            if (vet[i] > maior1)
            {
                maior2 = maior1;
                maior1 = vet[i];
            }
            else
            {
                if (maior2 < vet[i])
                {
                    maior2 = vet[i];
                }
            }
        }
        for (size_t i = 0; i < n; i++)
        {
            if (vet[i] == maior2)
            {
                cout << i + 1 << endl;
            }
        }

        cin >> n;
    }

    return 0;
}
