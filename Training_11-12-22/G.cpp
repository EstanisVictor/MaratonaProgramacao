#include <bits/stdc++.h>
using namespace std;

long long arranjo(int n, int p)
{
    if (p > 1)
        return n * arranjo(n - 1, p - 1);
    else
        return n;
}

int main()
{
    long long quant;
    cin >> quant;

    cout << arranjo(quant, 3) << endl;

    return 0;
}