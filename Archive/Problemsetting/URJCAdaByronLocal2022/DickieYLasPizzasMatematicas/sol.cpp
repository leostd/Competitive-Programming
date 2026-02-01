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
 
const int MOD = int(1e3) + 9;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
 
//#############################
const int MAXN = 1000005;
ll fact[2000];
ll ww[1500], hh[1500], cat[1500];

int n, m; // sizes
vector<vector<int>> g; //graph, grid

ll mod_sum(ll a, ll b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

ll mod_mult(ll a, ll b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

ll mod_pow(ll a, ll b) {
    ll ret = 1;
    ll y = a;
    while (b) {
        if (b&1) {
            ret = mod_mult(ret, y);
        }
        y = mod_mult(y, y);
        b >>= 1;
    }

    return ret;
}

ll mod_inv(ll a) {
    return mod_pow(a, MOD-2);
}

ll mod_fact(ll x) {
    if (x == 1) return 1;

    if (fact[x] != -1)
        return fact[x];
    
    fact[x] = mod_mult(x, mod_fact(x-1));

    return fact[x];
}

int h(ll x) {
    ll num = mod_mult(x, x+1);
    ll den = mod_inv(2);
    ll tot = mod_mult(num, den);

    return mod_sum(tot, 1);
}

int w(int x) {
    if (cat[x] != -1)
        return cat[x];
    
    ll num = 4*(x-1)+2;
    ll den = mod_inv(mod_sum(x, 1));
    ll prev = w(x-1);
    ll aux = mod_mult(num, den);
    // if (x == 4) {
    //     dbg(num, den, prev, aux, );
    // }
    return cat[x] = mod_mult(aux, prev);
}

ll memo[1500][1500];
ll dp(int i, int c) {
    // dbg(i, c);
    
    if (c < 0)
        return -INF;
    
    if (i == n)
        return 0;
        
    if (memo[i][c] != -1) {
        return memo[i][c];
    }

    memo[i][c] = max(dp(i+1, c), dp(i+1, c-ww[i]) + hh[i]);
    // dbg(i, memo[i][c]);
    return memo[i][c];
}
 
int main() {
    fastIO(); 
    int c;
    cin >> n >> c;
    ll x;
    memset(fact, -1, sizeof(fact));
    mod_fact(1001);
    dbg(mod_fact(4));
    forn(i, n) {
        cin >> x;
        hh[i] = h(x);
        // dbg(x, hh[i]);
    }

    memset(cat, -1, sizeof(cat));
    cat[0] = 1;
    cat[1] = 1;
    w(1000);
    forn(i, n) {
        cin >> x;
        ww[i] = w(x);
        // dbg(x, ww[i]);
    }

    forn(i, n) {
        cout << hh[i] << " " << ww[i] << endl;
    }

    memset(memo, -1, sizeof(memo));
    ll ans = dp(0, c);
    dbg(w(744));
    dbg(w(4));
    cout << ans << endl;

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