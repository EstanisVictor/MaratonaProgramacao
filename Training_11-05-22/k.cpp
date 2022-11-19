#include <bits/stdc++.h>

using namespace std;

int divisor(int n, int count)
{
    int grupo = 0;
    while (count * grupo != n)
    {
        count++;
        grupo = n / count;
        cout << count << endl;
    }
    return count;
}
/*
****INCOMPLETO****
*/
int main()
{
    int n;
    cin >> n;

    int m, cont1 = 0, cont2 = 0;
    cin >> m;

    cout << "Teste: " << divisor(n, 2);
    return 0;
}
