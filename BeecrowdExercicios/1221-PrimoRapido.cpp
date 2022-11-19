#include <iostream>

using namespace std;

int main()
{

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;

        bool primo = true;

        for (long long j = 2; j * j < x; j++)
        {
            if (x % j == 0)
                primo = false;
        }

        if (primo)
            cout << "Prime" << endl;
        else
            cout << "Not Prime" << endl;
    }
    return 0;
}