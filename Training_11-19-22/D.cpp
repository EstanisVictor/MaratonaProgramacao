#include <bits/stdc++.h>
using namespace std;

int main()
{
    int c, l;

    while (cin >> c && cin >> l)
    {
        int multDif = (c - l) * (c - l);
        int quad = c * l;

        cout << (quad / multDif) << endl;
    }
    return 0;
}
//12100