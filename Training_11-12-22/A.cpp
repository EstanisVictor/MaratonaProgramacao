#include <bits/stdc++.h>
#include <string.h>
using namespace std;

long long fatorial(int n)
{
    if (n > 0)
        return n * fatorial(n - 1);
    else
        return 1;
}

int main()
{

    int n;
    cin >> n;

    string str = to_string(fatorial(n));
    int soma = 0;
    for (size_t i = 0; i < str.length(); i++)
    {
        soma += int(str[0] - 48);
    }

    cout << soma;
    return 0;
}