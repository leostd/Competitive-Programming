#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#define inf 800000
using namespace std;

int ns[105], n;
int memo[20005][105];

int dp(int a, int c, int p)
{
    if (a < 0)
    {
        if (p == 1) return -a;
        if (p == 2) return inf;
    }
    if (a > 0 && c == n)
        return inf;
    if (c == n || a == 0) return 0;
    if (memo[a][c] != -1) return memo[a][c];
    if (p == 1)
        memo[a][c] = min(dp(a-ns[c], c+1, p), dp(a, c+1, p));
    else if (p == 2)
        memo[a][c] = min(1+dp(a-ns[c], c+1, p), dp(a, c+1, p));
    return memo[a][c];
}

int main ()
{
    int tc;
    int a;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d %d", &a, &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &ns[i]);
        memset(memo, -1, sizeof(memo));
        int ans = dp(a, 0, 1);
        memset(memo, -1, sizeof(memo));
        int ans2 = dp(a+ans, 0, 2);
        printf("%d %d\n", a+ans, ans2);
    }
    return 0;
}