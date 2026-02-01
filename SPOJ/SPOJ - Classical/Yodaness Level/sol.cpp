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

using namespace std;

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
#define fst first
#define snd second
#define lsb(x) ((x)&(-x))

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
const int MAXN = 30005;
int n;

int bit[MAXN];

void update(int idx, int val) {
    while (idx <= n) {
        bit[idx] += val;
        idx += lsb(idx);
    }
}

ll sum(int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += bit[idx];
        idx -= lsb(idx);
    }

    return ret;
}

int main() {
    int t;
    
    cin >> t;

    while(t--) {
        map<string, int> code;
        map<int, string> decode;
        string s;
        vector<string> w;
        vector<int> a;
        
        cin >> n;
        REP(i, n)
            cin >> s, w.pb(s);
        REP(i, n)
            cin >> s, code[s] = i+1, decode[i+1] = s;
        REP(i, n)
            a.pb(code[w[i]]);

        fill(bit, bit+MAXN, 0);
        ll ans = 0;
        for (int i = 0;i < n; i++) {
            ll q = sum(n) - sum(a[i]-1);
            ans += q;
            update(a[i], 1);
        }
        cout << ans << "\n";
    }

    return 0;
}