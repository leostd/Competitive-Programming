#include <bits/stdc++.h>
using namespace std;

int n, s, g[1002];

int memo[1002][1002];

int dp(int x, int k) {
    if (x == n-1 || g[x] == 0)
        return 0;
    if (memo[x][k] != -1) 
        return memo[x][k];
    int a, b;
    a = b = 0x3f3f3f3f;
    if (k && x+g[x] < n)
        a = dp(x+g[x], k-1);
    b = 1 + dp(x+1, k);
    return memo[x][k] = min(a, b);
}

int main() {
    //freopen("in", "r", stdin);
    int t, sc=1, k;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n; ++i)
            scanf("%d", &g[i]);
        memset(memo, -1, sizeof(memo));
        int ans = dp(0, k);
        printf("Scenario #%d:\n", sc++);
        if (ans == n-1)
            printf("Teresa will skip all the strawberries\n");
        else
            printf("Teresa will skip %d strawberries\n", ans);
    }
    return 0;
}