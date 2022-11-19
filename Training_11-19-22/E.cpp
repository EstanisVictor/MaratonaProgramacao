#include <bits/stdc++.h>
using namespace std;

long long prime(long long n)
{
    int result = 0;
    for (long long j = 2; j <= n / 2; j++)
    {

        if (n % j == 0)
        {
            result++;
            break;
        }
    }

    if (result == 0)
    {
        return n;
    }
    else
    {
        return 0;
    }
}

int main()
{
    long long x, y;
    cin >> x;
    cin >> y;

    long long soma = 0;

    for (long long i = x; i <= y; i++)
    {
        soma += prime(i);
    }

    cout << soma;
    return 0;
}
