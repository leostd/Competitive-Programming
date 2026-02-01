#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

int n, t, ns[20];
set<vi> ans;

void solve(int idx, int sum, vi ac) {
    if (sum == t) {
        ans.insert(ac);
        return;
    }
    if (sum > t || idx == n)
        return;
    for (int i = idx; i < n; ++i) {
        sum += ns[i];
        ac.push_back(ns[i]);
        solve(i+1, sum, ac);
        ac.pop_back();
        sum -= ns[i];
    }
}

int main() {
    //freopen("in", "r", stdin);
    while(scanf("%d %d", &t, &n), n) {
        for(int i = 0; i < n; ++i)
            scanf("%d", &ns[i]);
        vi a;
        ans.clear();
        sort(ns, ns+n, greater<int>());
        solve(0, 0, a);
        printf("Sums of %d:\n", t);
        if (ans.size() == 0)
            printf("NONE\n");
        else {
            for (auto it = ans.rbegin(); it != ans.rend(); ++it) {
                for (int j = 0; j < (*it).size(); ++j) {
                    if (j < (int)(*it).size()-1)
                        printf("%d+", (*it)[j]);
                    else
                        printf("%d", (*it)[j]);
                }
                printf("\n");
            }
        }
    }
    return 0;
}