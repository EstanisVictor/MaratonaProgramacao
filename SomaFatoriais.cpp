#include <bits/stdc++.h>

using namespace std;

long long fat(long long num)
{

    long long result = 1;
    for (size_t i = num; i >= 2; i--)
    {
        result *= i;
    }
    return result;
}

int main()
{
    long long n, m;

    while (cin >> n && cin >> m)
    {
        if (n == 0)
        {
            n = 1;
        }
        else
        {
            n = fat(n);
        }

        if (m == 0)
        {
            m = 1;
        }
        else
        {
            m = fat(m);
        }
        cout << (n + m) << endl;
    }

    return 0;
}