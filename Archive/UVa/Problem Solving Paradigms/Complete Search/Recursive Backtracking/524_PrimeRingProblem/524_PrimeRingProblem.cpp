#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bitset<10002> c;
bool check[20];
int n;
set<vi> ans;

void sieve() {
    c.set();
    for (int i = 2; i*i <= 10000; ++i){
        if (c[i]) {
            for (int j = i+i; j <= 10000; j+=i) {
                c[j] = false;
            }
        }
    }
}

void solve(int idx, int prev, vi ac) {
    if (idx == n) {
        if (!c[prev+1])
            return;
        ans.insert(ac);
        for (int i = 0; i < ac.size(); i++){

            printf((i < ac.size()-1? "%d " : "%d"), ac[i]);
        }
        printf("\n");
        return;
    }
    
    for (int i = 2; i <= n; ++i) {
        if (!check[i] && c[i+prev]) {
            check[i] = true;
            ac.push_back(i);
            solve(idx+1, i, ac);
            ac.pop_back();
            check[i] = false;
        }
    }

}
int main() {
    //freopen("in", "r", stdin);
    int cs = 1;
    sieve();
    bool first = true;
    while(scanf("%d", &n) != EOF) {
        vi ac;
        ac.clear();
        ac.push_back(1);
        memset(check, 0, sizeof(check));
        check[1] = true;
        if(!first)
            printf("\n");
        printf("Case %d:\n", cs++);
        solve(1, 1, ac);
        first = false;
    }
    return 0;
}