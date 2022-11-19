#include <bits/stdc++.h>
using namespace std;

int main()
{
    int quant;
    cin >> quant;
    int soma = 0;

    for (size_t i = quant; i > 1; i--)
    {
        for (size_t j = i - 1; j >= 1; j--)
        {
            soma++;
        }
    }

    cout << soma << endl;

    return 0;
}