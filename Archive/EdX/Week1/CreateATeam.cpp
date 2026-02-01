#ifdef JUDGE
    #include <fstream>
    std::ifstream cin("team.in");
    std::ofstream cout("team.out");
#else
    #include <iostream>
    using std::cin;
    using std::cout;
#endif
#include <math.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
//debug flag
#define db false
typedef long double ld;
int main (){
    ld r=-1;
    double matrix[3][3];
    const int andr = 0, ptr = 1, pl = 2;
    bool checkj[3], checkk[3];
    int maxk, maxj;
    memset(checkj,false,3);
    memset(checkk,false,3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> matrix[i][j];
            if (db)
                cout << matrix[i][j] << " ";
        }
        if (db)
            cout << "\n";
    }
    if (db)
        cout << std::endl;
    for(int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                if (j != k && j != i && k != i)
                {
                    ld m = (matrix[andr][i] * matrix[andr][i]) + (matrix[ptr][j]*matrix[ptr][j]) + (matrix[pl][k]*matrix[pl][k]);
                    m = sqrt(m);
                    r = std::max(r, m);
                }
            }
        }
    }
    cout.precision(17);
    cout << r << std::endl;
    return 0;
}
