#pragma GCC diagnostic ignored "-Wunused-const-variable"

#ifdef MAC
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
#else
#include <bits/stdc++.h>
#endif
 
using namespace std;
 
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define fst first
#define snd second
#define endl "\n"
 
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;
 
template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return a / gcd (a, b) * b; }
template<class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }
 
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
 
void dbg() { cout << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T) {
    cout << " " << to_string(H);
    dbg(T...);
}
 
#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif
 
void fastIO() {
    cin.sync_with_stdio(false);
    cin.tie(0);
}
 
template<typename T>
vector<T> make_unique(vector<T> v) {
    sort(all(v));
    return v.resize(unique(all(v)) - v.begin());
}
 
int nxt() {
    int x;
    cin >> x;
    return x;
}
 
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int dxKn[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int dyKn[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
const int dxK[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyK[8] = {1, -1, 0, 0, 1, -1, 1, -1};
 
const int MOD = int(1e9) + 7;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
 
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<vector<int>> g; //graph, grid
 
void discountMatchings(map<int, int> &fl, map<int, int> &fr, int &matchings, int &lqnt, int &rqnt) {
    for(auto l : fl) {
        if (fr.count(l.fst)){
            dbg(l.snd, fr[l.fst]);
            int mat = min(l.snd, fr[l.fst]);
            dbg(mat);
            matchings += mat;
            fl[l.fst] -= mat;
            fr[l.fst] -= mat;
            lqnt -= mat;
            rqnt -= mat;
        }
    }
}

int cntElemns(map<int, int> &f) {
    int ret = 0;
    for(auto x : f)
        ret += x.snd;
    
    return ret;
}

void turn(map<int, int> &f, int &ans, int &matchings, map<int, int> &f2, int diff) {
    dbg(diff);

    for(auto &s : f) {
        if (s.snd > 1) {
            int pos = s.snd/2;
            int mn = min(diff, pos);
            matchings += mn;
            diff -= mn;
            ans += mn;
            s.snd -= 2*mn;
        }
    }

    dbg(diff);
    if (diff == 0)
        return;

    for(auto it = f.begin(); it != f.end() && diff; ++it) {
        if (it->snd > 0) {
            int mn = min(diff, it->snd);
            f[it->fst] -= mn;
            f2[it->fst] += mn;
            ans += mn;
            diff -= mn;
        }
    }
}

void solve() {
    int l, r;
    cin >> n >> l >> r;
    dbg(n, l, r);
    vector<int> lc(l, 0), rc(r, 0);
    map<int, int> fl, fr;
    forn(i, n) {
        if (i < l)
            cin >> lc[i], fl[lc[i]]++;
        else
            cin >> rc[i-l], fr[rc[i-l]]++;
    }

    int matchings = 0;
    int d1 = l - n/2, d2 = r - n/2;
    discountMatchings(fl, fr, matchings, l, r);
    dbg(matchings);
    
    int ans = 0;
    dbg(fl);
    dbg(fr);
    if (l > r) {
        turn(fl, ans, matchings, fr, d1);
        dbg(cntElemns(fl), cntElemns(fr));
        ans += cntElemns(fr);
    } else if (r > l) {
        turn(fr, ans, matchings, fl, d2);
        dbg(cntElemns(fl), cntElemns(fr));
        ans += cntElemns(fl);
    } else {
        dbg(cntElemns(fr), cntElemns(fl));
        ans += l;
    }

    cout << ans << endl;
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--) {
        solve();
    }
    return 0;
}

/*
    RECALL CORNER CASES - e.g. n = 1, n = 0
    WRITE SOME STUFF

    think first, always - 
    1. concretely
    2. graphically 
    3. abstractly
    4. algebraically

    Checklist:
    - I/O make sense?   - Exclusion/inclusion           - Is a known sequence?
    - Reverse           - Brute force approach          - DP
    - Sort input        - Greedy approach
    - Check diagonals   - Divide and Conquer approach
*/