#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long int lli;

int nums[205], qs[11];
int n, q, st = 1, d, m;
lli memo[205][205][14];

lli dp (int x, int sum, int y)
{
    if (y == m && sum == 0)
        return 1;
    if (y == m || x == n)
        return 0;
    if (memo[x][sum][y] != -1)
        return memo[x][sum][y];
    memo[x][sum][y] = dp(x+1, (sum+nums[x])%d, y+1) + dp(x+1, sum%d, y);
    return memo[x][sum][y];
}

int main()
{
    while(scanf("%d %d", &n, &q), n || q)
    {
        for (int i = 0; i < n; i++)
            scanf("%d", &nums[i]);
        printf("SET %d:\n", st++);
        for (int i = 0; i < q; i++)
        {
            scanf("%d %d", &d, &m);
            memset(memo, -1, sizeof(memo));
            lli ans = dp(0, 0, 0);
            printf("QUERY %d: %lli\n", i+1, ans);
        }
    }
    return 0;
}