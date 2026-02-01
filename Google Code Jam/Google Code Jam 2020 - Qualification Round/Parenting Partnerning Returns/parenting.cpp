#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip> 

using namespace std;

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;

string to_string(string s) {
    return '"' + s + '"';
}
    
string to_string(const char* s) {
    return to_string((string) s);
}
    
string to_string(bool b) {
    return (b ? "true" : "false");
}
    
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
    
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

void fastIO() {
    cin.sync_with_stdio(false);
    cin.tie(0);
}


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

//#############################
const int MAXN = 1000005;



int main() {
    int t, tc=1;

    cin >> t;
    while(t--) {
        int n;
        vector<pii> sch;
        vector<pair<pii, int>> idxs;
        map<int, pii> aux;
        
        int s, e;
        cin >> n;
        string ans(n, 'X');
        for(int i = 0;i < n; i++) {
            cin >> s >> e;
            sch.pb(pii(s, e));
            idxs.pb(pair<pii,int>(pii(s,e), i));
            aux[i] = pii(s, e);
        }

        sort(sch.begin(), sch.end());
        sort(idxs.begin(), idxs.end());

        auto it = sch.begin();
        while(it != sch.end()) {
            int idx = (int)(it - sch.begin());
            ans[idxs[idx].snd] = 'C';
            it = upper_bound(sch.begin(), sch.end(), pii(it->snd, 0));
        }

        vector<pair<pii, int>> remaining;
        REP(i,n)
            if (ans[i] == 'X') remaining.pb(pair<pii, int>(aux[i], i));

        sort(remaining.begin(), remaining.end());
        // cout << to_string(remaining) << endl;

        if (!remaining.empty())
            ans[remaining[0].second] = 'J';
        for(int i = 1; i < remaining.size(); i++) {
            pii cur = remaining[i].first;
            pii prev = remaining[i-1].first;
            if (prev.snd > cur.first){
                //overlap
                ans = "IMPOSSIBLE";
                break;
            }
            else {
                ans[remaining[i].snd] = 'J';
            } 
        }
        
        cout << "Case #" << tc++ << ": " << ans << endl;
    }
    return 0;
}