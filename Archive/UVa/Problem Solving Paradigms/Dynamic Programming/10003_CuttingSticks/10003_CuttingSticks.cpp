#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int n,l, memo[55][55], cuts[55];

int dp(int a, int b)
{
    if (b - a == 1)
        return memo[a][b] = 0;
    if (memo[a][b] != -1)
        return memo[a][b];
    int ret = 40000000;
    for (int i = a+1; i < b; i++){
        ret = min(dp(a, i) + dp(i, b), ret);
    }
    return memo[a][b] = cuts[b] - cuts[a] + ret;
}

int main()
{
    while(scanf("%d", &l), l != 0){
        int i = 0;
        cuts[i++] = 0;
        scanf("%d", &n);
        for (;i <= n; i++)
            scanf("%d", &cuts[i]);
        cuts[i] = l;
        memset(memo, -1, sizeof(memo));
        int ans = dp(0, n+1);
        printf("The minimum cutting is %d.\n", ans);
    }
    return 0;
}