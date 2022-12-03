#include <bits/stdc++.h>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

int isPalindrome(string S)
{
    string P = S;

    reverse(P.begin(), P.end());

    if (S == P)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string text;
    getline(cin, text);
    bool veri = false;
    int contador = 0;

    vector<string> tokens;
    string token;
    stringstream ss(text);

    while (getline(ss, token, ' '))
    {
        tokens.push_back(token);
    }

    for (size_t i = 0; i < tokens.size(); i++)
    {
        string temp = tokens[i];

        if (temp.length() < 3)
        {
            cout << i + 1 << " ";
        }
        else if (isPalindrome(temp) == 0)
        {
            cout << i + 1 << " ";
            veri = false;
        }
        else
        {
            veri = true;
            contador++;
        }
    }

    if (veri == true && contador == tokens.size())
    {
        cout << 0;
    }

    return 0;
}
