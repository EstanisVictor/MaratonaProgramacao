#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, c;
    cin >> l;
    cin >> c;
    char mat[l][c];

    for (size_t i = 0; i < l; i++)
    {
        
        for (size_t j = 0; j < c; j++)
        {
            cin >> mat[i][j];
        }
        
    }
    
    int l1, c1, l2, c2;

    for (size_t i = 0; i < l; i++)
    {
        
        for (size_t j = 0; j < c; j++)
        {
            if(mat[i][j] == 'f'){
                l1 = i;
                c1 = j;
            }
            if (mat[i][j] == 'p')
            {
                l2 = i;
                c2 = j;
            }
            
        }
        
    }

    

    return 0;
}
