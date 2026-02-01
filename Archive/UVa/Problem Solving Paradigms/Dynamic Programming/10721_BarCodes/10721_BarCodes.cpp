#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

typedef long long int lli;

lli memo[55][55];
int n, k, m;

lli dp(int t, int e)
{
    lli &ret = memo[t][e];
    if (ret != -1LL)
        return ret;
    if (t == 0 && e == 0)
        return ret = 1LL;
    if (t == 0 || e == 0)
        return ret = 0LL;
    else{
        ret = 0;
        for (int i = 1; i <= m; i++){
            if (t - i < 0) break;
                ret += dp(t-i, e-1); // making a i units bar
        }
        return ret;
    }
}

int main()
{
    while(scanf("%d %d %d", &n, &k, &m) != EOF)
    {
        for (int i = 0; i < 55; i++)
            for (int j = 0; j < 55; j++)
                memo[i][j] = -1LL;
        lli ans = dp(n, k);
        //printf("%lli\n", ans);
        cout << ans << "\n";
    }
    return 0;    
}