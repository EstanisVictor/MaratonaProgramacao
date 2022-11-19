#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ham;
    cin >> ham;
    int dog;
    cin >> dog;
    int hum;
    cin >> hum;
    int elf;
    cin >> elf;

    double d1 = (double)dog / 7;
    double h1 = (double)hum / (7 * 7);
    double e1 = (double)elf / (7 * 7 * 7);

    if (ham > d1 && ham > h1 && ham > e1)
    {
        cout << "Hamster eh o mais velho.";
    }
    if (d1 >= ham && d1 >= h1 && d1 >= e1)
    {
        cout << "Cachorro eh o mais velho.";
    }
    if (h1 >= ham && h1 >= d1 && h1 >= e1)
    {
        cout << "Humano eh o mais velho.";
    }
    if (e1 >= ham && e1 >= d1 && e1 >= h1)
    {
        cout << "Elfo eh o mais velho.";
    }
    return 0;
}