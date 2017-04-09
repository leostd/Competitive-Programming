#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

typedef long long int lli;

int coins[] = {1, 5, 10, 25, 50};
lli memo[30005][5];

lli dp(int m, int c)
{
    if (m < 0 || c > 4)
        return 0;
    if (m == 0)
        return 1;
    if (memo[m][c] != -1)
        return memo[m][c];
    memo[m][c] = dp(m, c+1) + dp(m - coins[c], c);
    return memo[m][c];
}

int main()
{
    int m;
    memset(memo, -1, sizeof(memo));
    while(scanf("%d", &m) != EOF)
    {
        lli ans = dp(m, 0);
        if (ans != 1)
            printf("There are %lli ways to produce %d cents change.\n", ans, m);
        else
            printf("There is only 1 way to produce %d cents change.\n", m);
    }
    return 0;
}