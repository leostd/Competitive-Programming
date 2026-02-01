#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;
lli memo[30][150];

lli dp(int n, int x) {
    if (x <= 0)
    {
        lli ans = 1;
        for (int i = 0; i < n; ++i)
            ans *= 6;
        return ans;
    }
    if (n == 0 && x > 0) 
        return 0;
    if (memo[n][x] != -1)
        return memo[n][x];
    memo[n][x] = 0;
    for (int i = 1; i <= 6; i++)
        memo[n][x] += dp(n-1, x-i);
    return memo[n][x];
}
lli gcd(lli a, lli b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    lli r = a % b;
    return gcd(b, r);
}
int main() {
    int n, x;
    while(scanf("%d %d", &n, &x), n+x) {
        lli w=1;
        memset(memo, -1, sizeof(memo));
        lli ans = dp(n, x);
        for(int i = 0; i < n; i++)
            w *= 6;
        lli g = gcd(w, ans);
        w /= g;
        ans /= g;
        if (!ans) printf("0\n");
        else if(ans == w) printf("1\n");
        else printf("%lli/%lli\n", ans, w);
    }
    return 0;
}