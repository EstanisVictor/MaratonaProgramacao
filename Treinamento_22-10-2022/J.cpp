#include <bits/stdc++.h>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<string> vet;
    vector<string> concat;

    for (size_t i = 0; i < t; i++)
    {
        int m;
        cin >> m;

        cin.ignore();

        string palavras, t, a;

        getline(cin, palavras);

        stringstream ss(palavras);

        while (ss >> t)
        {
            vet.push_back(t);
        }

        sort(vet.begin(), vet.end());

        for (size_t i = 0; i < vet.size(); i++)
        {
            a += vet[i];
        }
        concat.push_back(a);
        vet.clear();
    }

    for (size_t i = 0; i < concat.size(); i++)
    {
        cout << concat[i] << "\n";
    }

    return 0;
}