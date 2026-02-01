#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define pb push_back
#define sz(x) ((int)x.size())
string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

void solve() {
    int n;
    cin >> n;
    set<int> st;
    int x;
    int tot = (1 << 21) - 1;
    vector<int> aux;
    forn(i, n) {
        cin >> x;
        aux.pb(x);
        st.insert(x);
        tot &= x;
    }

    if (st.count(tot) == 0) {
        cout << -1 << endl;
        return;
    }

    vector<int> ans;
    forn(i, (int)aux.size()) {
        ans.pb(aux[i]);
        ans.pb(tot);
    }

    cout << ans.size() << endl;
    for(auto w : ans) {
        cout << w << " ";
    }
    cout << endl;

}

signed main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}
