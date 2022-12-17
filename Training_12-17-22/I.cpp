#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, v[32];
    cin >> n;

    while (n > 0)
    {
        
        for (size_t i = 0; i < 32; i++)
        {
            //lê uma linha inteira sem espaços em branco
            scanf("%1d", &v[i]);
        }

        int d1 = 128, d2 = 128, d3 = 128, d4 = 128;
        int s1 = 0, s2 = 0, s3 = 0, s4 = 0;

        for (size_t i = 0; i < 32; i++)
        {
            if (i <= 7)
            {
                s1 += d1 * v[i];
                d1 = d1 / 2;
            }
            else if (i > 7 && i <= 15)
            {
                s2 += d2 * v[i];
                d2 = d2 / 2;
            }
            else if (i > 15 && i <= 23)
            {
                s3 += d3 * v[i];
                d3 = d3 / 2;
            }
            else
            {
                s4 += d4 * v[i];
                d4 = d4 / 2;
            }
        }

        cout << s1 << "." << s2 << "." << s3 << "." << s4 << endl;

        n--;
    }

    return 0;
}