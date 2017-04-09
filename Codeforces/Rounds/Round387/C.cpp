#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    int n, q;
    int ti, ki, di;
    scanf("%d %d", &n, &q);
    vector<int> s(n+1, 0), aux;
    long long int sum;
    for (int i = 0; i < q; ++i)
    {
        sum = 0;
        aux.clear();
        scanf("%d %d %d", &ti, &ki, &di);
        for (int j = 1; j <= n && ki > 0; j++)
        {
            if (ti >= s[j])
            {
                aux.push_back(j);
                sum += j;
                ki--;
            }
        }
        if (ki == 0)
        {
            cout << sum << "\n";
            for (int j = 0; j < aux.size(); j++)
                s[aux[j]] = ti + di;
        }
        else
            printf("-1\n"); 
    }
    return 0;
}