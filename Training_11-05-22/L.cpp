#include <bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    cin >> n;

    cout <<  floorf(log10(n) * 100) / 100;

    return 0;
}