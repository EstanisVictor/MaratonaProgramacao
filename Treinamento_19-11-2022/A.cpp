#include <bits/stdc++.h>
using namespace std;

int cong(int x, int y, int n)
{
    if (n > 1)
    {
        if ((x - y) % n == 0 || (y % n == x % n))
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    int x, y, n;

    while (cin >> x && cin >> y && cin >> n)
    {

        cout << cong(x, y, n) << endl;
    }

    return 0;
}
