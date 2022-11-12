#include <bits/stdc++.h>
using namespace std;

long long fatorial(int n)
{
    if (n > 0)
        return n * fatorial(n - 1);
    else
        return 1;
}

long long arranjo(int n, int p)
{
    if (p > 1)
        return n * arranjo(n - 1, p - 1);
    else
        return n;
}

long long combinacao(int n, int p)
{
    return arranjo(n, p) / fatorial(p);
}

int main()
{
    long long quant;
    cin >> quant;

    cout << combinacao(quant, 10) << endl;

    return 0;
}