#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>
using namespace std;

typedef pair<int, int> ii;

int memo[11000][105];
ii items[105];
int n, m;

int dp(int w, int it)
{
    if (w > m && m < 1800)
        return -10000;
    if (w > m + 200)
        return -10000;
    if (it == n){
        if (w > m && w <= 2000)
            return -10000;
        return 0;
    }
    if (memo[w][it] != -1)
        return memo[w][it];
    else
    {
        memo[w][it] = max(dp(w, it+1), items[it].second + dp(w+items[it].first, it+1));
        return memo[w][it];
    }
}

int main()
{
    while(scanf("%d %d", &m, &n) != EOF)
    {
        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < n; i++)
            scanf("%d %d", &items[i].first, &items[i].second);
        int ans = dp(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}