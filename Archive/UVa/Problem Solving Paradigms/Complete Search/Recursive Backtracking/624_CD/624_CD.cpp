#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n, t, ts[30], maxs;
bool check[30];
vi maxvi;
void solve(int sum, vi ac, int i) {
    if (sum > maxs && sum <= n) {
        maxs = sum; 
        maxvi = ac;
    }
    if (sum > n)
        return;
    for (i; i < t; i++) {
        if (!check[i])
        {
            check[i] = true;
            sum += ts[i];
            ac.push_back(ts[i]);
            solve(sum, ac, i+1);
            sum -= ts[i];
            ac.pop_back();
            check[i] = false;
        }
    }
}
int main() {
   //freopen("in", "r", stdin);
    while(scanf("%d %d", &n, &t) != EOF) {
        for (int i = 0; i < t; ++i)
            scanf("%d", &ts[i]);
        maxs = 0;
        memset(check, 0, sizeof(check));
        vi ac;
        solve(0, vi(), 0);
        for (int i = 0; i < maxvi.size(); ++i)
            printf("%d ", maxvi[i]);
        printf("sum:%d\n", maxs);
    }
    return 0;
}