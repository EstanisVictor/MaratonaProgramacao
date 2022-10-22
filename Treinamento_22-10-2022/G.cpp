#include <bits/stdc++.h>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string q;
    getline(cin, q);
    stringstream ss(q);
    int value, i = 0;
    vector<int> vet;

    while (ss >> value)
    {
        vet.push_back(value);
    }

    sort(vet.begin(), vet.end());

    for (size_t i = 0; i < vet.size(); i++)
    {
        cout << vet[i] << " ";
    }

    cout << "\n";
    while (!vet.empty())
    {
        cout << vet.back() << " ";
        vet.pop_back();
    }

    return 0;
}