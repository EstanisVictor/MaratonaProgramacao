#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y;
    cin >> x;
    cin >> y;

    for (int i = y; i >= x; i--)
    {
        if (i % 3 == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}
