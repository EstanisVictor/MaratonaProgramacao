#include <iostream>

using namespace std;

int main()
{

    int num;
    cin >> num;

    for (size_t i = 0; i < num; i++)
    {
        int f1, f2;
        cin >> f1;
        cin >> f2;

        while (f2 != 0)
        {
            int resto = f1 % f2;
            f1 = f2;
            f2 = resto;
        }

        cout << f1 << "\n";
    }
    return 0;
}