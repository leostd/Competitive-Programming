#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

int n, t, ns[20];
vvi ans;

void solve(int idx, int sum, vi ac) {
    if (sum == t) {
        ans.push_back(ac);
        return;
    }
    
    for (int i = idx+1; i < n; ++i) {
        sum += ns[i];
        ac.push_back(ns[i]);
        solve(i, sum, ac);
        ac.
    }
}

int main() {
    while(scanf("%d %d", &t, &n), n) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &ns[i]);
        vi a;
        ans.clear();
        sort(ns, ns+n, greater<int>());
        solve(0, 0, a);
        if (ans.size() == 0)
            printf("NONE\n");
        else {
            printf("Sums of %d:\n", t);
            for (int i = 0; i < ans.size(); ++i) {
                for (int j = 0; j < ans[i].size(); ++j) {
                    if (j < (int)ans[i].size()-1)
                        printf("%d+", ans[i][j]);
                    else
                        printf("%d", ans[i][j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}