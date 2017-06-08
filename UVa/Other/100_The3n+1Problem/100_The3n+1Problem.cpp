#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main()
{
    //freopen("in", "r", stdin);
    memset(n, -1, sizeof(n));
    int a,b;
    while(scanf("%d %d", &a, &b) != EOF)
    {
        int aaux, baux;
        aaux = min(a,b);
        baux = max(a,b);
        lli maxc = 0, aux = 1;
        for (int i = aaux; i <= baux; ++i)
        {
            int x = i;
            aux = 1;
            while(x != 1)
            {
                aux++;
                if (x % 2 != 0) x = 3*x+1;
                else x = x/2;
            }
            maxc = max(maxc, aux);
        }
        printf("%d %d %lli\n", a, b, maxc);
    }
    return 0;
}