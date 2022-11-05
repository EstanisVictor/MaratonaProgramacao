#include <bits/stdc++.h>

using namespace std;

int main()
{
    int num;
    cin >> num;

    int quadrado = sqrt(num);

    if (quadrado * quadrado == num)
    {
        cout << "Quadrado perfeito" << endl;
        cout << num << endl;
        cout << quadrado << endl;
    }
    else
    {
        cout << "Nao eh quadrado perfeito" << endl;
        while (quadrado * quadrado != num)
        {
            num--;
            quadrado = sqrt(num);
        }
        cout << num << endl;
        cout << quadrado << endl;
    }

    return 0;
}