#include <bits/stdc++.h>
using namespace std;

int mdc(int num1, int num2)
{
    if (num1 % num2 == 0)
        return num2;
    else
        return mdc(num2, num1 % num2);
}

int main()
{
    int d, f, l;

    cin >> d;
    cin >> f;
    cin >> l;
    int r = mdc(d, f);

    cout << mdc(r, l);
    return 0;
}
