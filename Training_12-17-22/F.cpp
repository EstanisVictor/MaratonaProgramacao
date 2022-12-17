#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ordem;
    cin >> ordem;

    int mat[ordem][ordem];

    for (size_t i = 0; i < ordem; i++)
    {
        for (size_t j = 0; j < ordem; j++)
        {
            if (i == j)
            {
                mat[i][j] = 1;
            }
            else
            {
                mat[i][j] = 0;
            }
        }
    }

    for (size_t i = 0; i < ordem; i++)
    {
        for (size_t j = 0; j < ordem; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
