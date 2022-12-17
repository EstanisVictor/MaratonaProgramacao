#include <bits/stdc++.h>
using namespace std;

int verify(int vet[], int l)
{
    for (size_t i = 0; i < l; i++)
    {
        for (long long j = l; j > i; j--)
        {
            if (vet[i] == vet[j])
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int l, temp;
    cin >> l;
    cin >> temp;
    while (l != 0)
    {
        int temps[l];

        for (size_t i = 0; i < l; i++)
        {
            cin >> temps[i];
        }

        cout << verify(temps, l) << "\n";

        cin >> l;
        cin >> temp;
    }

    return 0;
}
