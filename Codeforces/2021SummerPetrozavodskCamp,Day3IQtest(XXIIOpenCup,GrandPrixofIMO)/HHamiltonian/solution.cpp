#include<bits/stdc++.h>
using namespace std;
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define pb push_back
#define sz(x) ((int)x.size())
#define fst first
#define snd second
#define mp make_pair
typedef pair<int, int> pii;
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

vector<vector<int>> g;

int memo[11][1<<11];
int n, m;

int dp(int i, int mask, int b) {
    if (__builtin_popcount(mask) == n-1) {
        forn(j, sz(g[i])) {
            if (g[i][j] == b && (mask & (1 << b)) == 0) return 1;
        }
        return 0;
    }
    int &ret = memo[i][mask];
    if(ret != -1) return ret;
    ret = 0;
    forn(j, sz(g[i])) {
        if ((1 << g[i][j]) & mask) continue;
        ret += dp(j, mask | (1 << g[i][j]), b);
    }
    return ret;
}


signed main() {
    cin >> n;
    g.assign(min(n, 20), vector<int>());
    cin >> m;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].pb(y);
        g[y].pb(x);
    }

    //set<pii> ans;
    //forn(i, n) {
    //    forn(j, n) {
    //        if (isHamiltonian(i, j)) {
    //            cout << i << " " << j;
    //            ans.insert(mp(min(i, j), max(i, j)));
    //        }
    //    }
    //}
    //cout << ans.size() << endl;
    //for(auto x : ans) {
    //    cout << x.fst << " " << x.snd << endl;
    //}
    memset(memo, -1, sizeof(memo));
    cout << dp(1, 1, 0) << endl;
}
