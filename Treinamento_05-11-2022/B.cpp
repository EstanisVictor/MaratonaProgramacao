#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int c;
    cin >> c;

    int m;
    cin >> m;

    int sum = 0;

    for (size_t i = 0; i < m; i++)
    {
        int value;
        cin >> value;

        sum += value;
    }

    cout << sum * c;
    return 0;
}