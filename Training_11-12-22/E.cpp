#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, q;
    cin >> a;
    cin >> q;

    double acertar = (double)1 / a;

    double result1 = 1, result2 = 1;

    for (size_t i = 0; i < q; i++)
    {
        result1 *= acertar;
    }

    cout << result1;

    return 0;
}