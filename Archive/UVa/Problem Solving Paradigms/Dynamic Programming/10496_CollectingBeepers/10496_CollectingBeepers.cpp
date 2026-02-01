#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string.h>
using namespace std;

int r[11], c[11], ws, rows, cols, n, dist[11][11];
int memo[11][1 << 11];

int dp(int pos, int bitmask)
{
    if (bitmask == (1 << (n+1)) - 1)
        return dist[pos][0];
    if (memo[pos][bitmask] != -1)
        return memo[pos][bitmask];
    int ans = 2e9;
    for (int nxt = 0; nxt <= n; nxt++)
        if (nxt != pos && !(bitmask & (1 << nxt)))
            ans = min(ans, dist[pos][nxt] + dp(nxt, bitmask | (1 << nxt)));
    return memo[pos][bitmask] = ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d %d", &rows, &cols); // size of the grid
        scanf("%d %d", &r[0], &c[0]); // Karel's position
        scanf("%d", &n); // number of beepers
        for (int i = 1; i <= n; i++)
            scanf("%d %d", &r[i], &c[i]);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= n; j++)
                dist[i][j] = abs(r[i] - r[j]) + abs(c[i] - c[j]);
        memset(memo, -1, sizeof(memo));
        int ans = dp(0, 1);
        printf("The shortest path has length %d\n", ans);
    }
    return 0;
}