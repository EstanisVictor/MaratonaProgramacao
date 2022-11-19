#include <bits/stdc++.h>
using namespace std;

int hiper(int n)
{
    int result = 0;
    for (long long j = 2; j*j < n ; j++)
    {

        if (n % j == 0)
        {
            result++;
            break;
        }
    }

    if (result == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    int n;
    cin >> n;
    for (size_t i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        cout << hiper(x) << endl;
    }

    return 0;
}
