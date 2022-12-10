#include <bits/stdc++.h>
using namespace std;

vector<int> vet;

void splitstr(string str, string deli)
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1)
    {
        int c = stoi(str.substr(start, end - start));
        vet.push_back(c);
        start = end + deli.size();
        end = str.find(deli, start);
    }
    int c = stoi(str.substr(start, end - start));
    vet.push_back(c);
}

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<string> result;
    for (size_t i = 0; i < n; i++)
    {
        int time1 = 0, time2 = 0;

        for (size_t j = 0; j < 2; j++)
        {
            string jogo;

            getline(cin, jogo);
            splitstr(jogo, "x");

            if (j == 0)
            {
                time1 += vet[0];
                time2 += vet[1];
            }
            if (j == 1)
            {
                time2 += vet[0];
                time1 += vet[1];
            }
            vet.pop_back();
            vet.pop_back();
        }

        if (time1 > time2)
        {
            result.push_back("Time 1");
        }
        else if (time2 > time1)
        {
            result.push_back("Time 2");
        }
        else
        {
            result.push_back("Penaltis");
        }
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}
