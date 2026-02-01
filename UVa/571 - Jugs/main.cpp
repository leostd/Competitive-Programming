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
#define mt make_tuple
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
typedef tuple<ll, ll, ll> lll;
typedef tuple<ld, ld, ld> ddd;
 
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

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
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
typedef tuple<int, int, string> iis;

int n, m, ca, cb; // sizes
bool vis[2005][2005];
iis nx[2005][2005];

int dp(int a, int b) {
    if (a > ca || b > cb || a < 0 || b < 0) return 0;
    vis[a][b] = true;

    if (b == n)
        return 1;
    
    int pab, pba, fa, fb, ea, eb;
    pab = pba = fa = fb = ea = eb = 0;
    if (!vis[ca][b]) {
        fa = dp(ca, b);
        dbg(a, b, "fill a", ca, b);
    }
    if (!vis[a][cb]) {
        fb = dp(a, cb);
        dbg(a, b, "fill b", a, cb);
    }
    if (!vis[0][b]) {
        ea = dp(0, b);
        dbg(a,b, "empty a", 0, b);
    }
    if (!vis[a][0]) {
        eb = dp(a, 0);
        dbg(a, b, "empty b", a, 0);
    }

    int rema = ca - a;
    int remb = cb - b;

    if (rema >= b) {
        pba = (!vis[a+b][0] ? dp(a+b, 0) : 0);
        if (pba) {
            nx[a][b] = mt(a+b, 0, "pour B A");
            dbg(a, b, "pour b a", a+b, 0);
            return pba;
        }
    }
    else {
        pba = (b-rema >= 0 && !vis[ca][b-rema] ? dp(ca, b-rema) : 0);
        if (pba) {
            nx[a][b] = mt(ca, b-rema, "pour B A");
            dbg(a, b, "pour b a", ca, b-rema);
            return pba;
        }
    }

    if (remb >= a){
        pab = (!vis[0][a+b] ? dp(0, a+b) : 0);
        if (pab) {
            nx[a][b] = mt(0, a+b, "pour A B");
            dbg(a, b, "pour a b", 0, a+b);
            return pab;
        }
    }
    else {
        pab = (a - remb >= 0 && !vis[a-remb][cb] ? dp(a-remb, ca) : 0);
        if (pab) {
            nx[a][b] = mt(a-remb, cb, "pour A B");
            dbg(a, b, "pour a b", a-remb, cb);
            return pab;
        }
    }
    
    if (fa) {
        nx[a][b] = mt(ca, b, "fill A");
        return fa;
    } else if (fb) {
        nx[a][b] = mt(a, cb, "fill B");
        return fb;
    } else if (ea) {
        nx[a][b] = mt(0,b,"empty A");
        return ea;
    } else if (eb) {
        nx[a][b] = mt(a, 0, "empty B");
        return eb;
    }

    return 0;
}
void solve() {
    memset(vis, 0, sizeof(vis));
    forn(i, 2005) forn(j, 2005) nx[i][j] = mt(-1, -1, "");
    dp(0, 0);
    int a, b;
    string mov;
    int curx = 0, cury = 0;
    while(true) {
        dbg(curx, cury);
        if (curx == -1 && cury == -1) break;
        tie(a, b, mov) = nx[curx][cury];
        if (!mov.empty())
            cout << mov << endl;
        curx = a, cury = b;
    }
    cout << "success" << endl;
} 
int main() {
    fastIO(); 
    while(cin >> ca >> cb >> n) {
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