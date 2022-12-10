#include <bits/stdc++.h>
using namespace std;

vector<int> vet;

void splitstr(string str, string deli)
{
    int start = 0;
    int end = str.find(deli);
    while (end != -1) {
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
    int soma = 0, maior = -1001, entrada;

    string seqencia;
    getline(cin, seqencia);

    splitstr(seqencia, " ");

    for (size_t i = 0; i < vet.size(); i++)
    {
        soma += vet[i];
        if (soma > maior)
        {
            maior = soma;
        }
    }
    cout << maior;
    return 0;
}
