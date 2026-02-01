#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

int coins[] = {1,8,27,64,125,216,343,512,729,1000,1331,1728,2197,2744,3375,4096,4913,5832,6859,8000,9261};
lli memo[10005][21];
int money;

lli dp(int m, int c)
{
    if (m == 0)
        return memo[m][c] = 1;
    if (c == 21)
        return 0;
    if (memo[m][c] != -1)   
        return memo[m][c];
    if (m - coins[c] >= 0)
        memo[m][c] = dp(m-coins[c], c) + dp(m, c+1);
    else if (c + 1 < 21 && m - coins[c+1] < 0)
        return 0;
    else
        memo[m][c] = dp(m, c+1);
    return memo[m][c];
}

int main()
{
    memset(memo, -1, sizeof(memo));
    while(scanf("%d", &money) != EOF)
    {
        //memset(memo, -1, sizeof(memo));
        lli ans = dp(money, 0);
        printf("%lli\n", ans);
    }
    return 0;
}
