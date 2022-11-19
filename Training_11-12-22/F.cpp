#include <bits/stdc++.h>
using namespace std;

long long trib(int n)
{
    if (n == 0 || n == 1 || n == 2)
        return 0;

    if (n == 3)
        return 1;
    else
        return trib(n - 1) +
               trib(n - 2) +
               (trib(n - 3) * 3);
}

int main()
{
    int n;
    cin >> n;

    cout << trib(n) - 3 << endl;

    return 0;
}