#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, soma = 0;
    int d1 = 0, d2 = 0, d3 = 0;

    while (cin >> a && cin >> b && cin >> c)
    {
        d1 = a;
        d2 = b;
        d3 = c;
        while (a != b && a != c && b != c)
        {
            a+=a;
            b+=b;
            c+=c;

            if((a+b+c)){

            }
            soma++;
        }
        cout << soma << endl;
    }
    return 0;
}
