#include <bits/stdc++.h>
#define MAXN 100005
#define MOD 1000000007
#define LL long long
using namespace std;



int main() {
    int c[MAXN], p[MAXN];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);
    sort(p, p+n);
    sort(c, c+n);
    LL ans = 1;
    for (int i = n-1, j = 0; i >= 0; i--, j++){
        int idx = (int) (lower_bound(c, c+n, p[i]) - c);
        ans = (ans*(n-idx-j)) % MOD;
    }
    printf("%lli\n", ans);
    return 0;
}