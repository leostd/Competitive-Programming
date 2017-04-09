#include <bits/stdc++.h>
#define modulo 1000000007
using namespace std;

int a, b, p1, p2, t;
int memo[2005][2005];

int dp(int x, int y, int v)
{
    if (x < 0 || y < 0)
        return 0;
    if (v == 0) // free stress victory
    {
        if (x == 1 && y == 0)
            return 1;
        if (y >= x)
            return 0;
    }
    else //stressful victory
    {
        if (x > y && y != b)
            return 0;
        if (x == 0 && y == 0)
            return 1;
        
    }
    if (memo[x][y] != -1)
        return memo[x][y];
    memo[x][y] = (dp(x-1, y, v) + dp(x, y-1, v)) % modulo;
    return memo[x][y];
}

int main()
{
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
    {
        scanf("%d-%d", &a, &b);
        memset(memo, -1, sizeof(memo));
        int freev = dp(a, b, 0);
        memset(memo, -1, sizeof(memo));
        int stressv = dp(a, b, 1);
        printf("Case #%d: %d %d\n", i+1, freev, stressv);
    }
    return 0;
}