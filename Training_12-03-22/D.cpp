#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int ins, n;
    cin >> ins;
    cin >> n;

    vector<string> nomes;
    vector<double> tam;

    for (size_t i = 0; i < ins; i++)
    {
        string s;
        getline(cin, s);

        double d;
        cin >> d;

        nomes.push_back(s);
        tam.push_back(d);
    }

    return 0;
}
