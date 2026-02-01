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
 
const int MOD =  998244353;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
 
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<ll> fact;
 
// 1 2 3 4 -> 0 1 2 3 -> 0 0 1 2 -> 0 0 0 1 -> 0 0 0 0
// 1 2 5 3 -> 0 1 4 2 -> 0 0 3 1 -> 0 0 2 0
// 4 1 2 3 4 -> 3 0 1 2 3 -> 2 0 0 1 2 -> 1 0 0 0 1

// 1 2 2 3 -> 0 1 1 2 -> 0 0 0 1
// Nice:
// 1 2 3 2
// 2 3 1 2 
// 1 3 2 2
// 2 3 2 1
// 3 2 2 1
// 3 2 1 2
// 3 1 2 2

//1 1 2
// Not nice:
//2 1 1
//1 2 1


ll mod_mult(ll a, ll b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

ll mod_pow(ll a, ll b) {
    ll ret = 1;
    ll y = a;
    while(b) {
        if (b&1) {
            ret = mod_mult(ret, y);
        }
        y = mod_mult(y, y);
        b >>= 1;
    }

    return ret;
}

ll mod_fact(ll a) {
    if (fact[a] != -1)
        return fact[a];

    fact[0] = 1;
    for1(i, a+1) {
        fact[i] = mod_mult(fact[i-1], i);
    }

    return fact[a];
}

ll mod_inv(ll a) {
    return mod_pow(a, MOD-2);
}

ll mod_comb(ll a, ll b) {
    if (a < b)
        return 0;
    return mod_mult(mod_fact(a), mod_inv(mod_fact(a-b)));
}

inline void solve() {
    cin >> n;
    vector<ll> a(n, 0LL);
    fact.assign(n+2, -1);
    mod_fact(n+1);
    map<ll, int> f;
    forn(i, n) cin >> a[i], f[a[i]]++;
    sort(all(a));

    ll mx = a[n-1];
    ll smx = a[n-2];
    ll diff = mx - smx;

    ll ans = 0;
    if (diff == 0) {
        ans = mod_fact(n);
    } else if (diff == 1) {
        ans = mod_fact(n);
        forn(i, n) {
            ll l = i;
            ll cur = 0;
            if (l >= f[smx]) {
                ll aux = mod_comb(l, f[smx]);
                dbg(smx, f[smx], l, aux, mod_comb(l, l-f[smx]));
                ll reml = l - f[smx];
                ll rem_nums = n-1-f[smx];
                // ll aux2 = mod_comb(rem_nums, reml);
                ll aux2 = mod_fact(rem_nums);
                dbg(reml, rem_nums, aux2);
                aux = mod_mult(aux, aux2);
                dbg(aux);
                cur = aux % MOD;
            }
            ans = ((ans%MOD) - (cur%MOD) + MOD)%MOD;
        }
    } else if (diff > 1) {
        ans = 0;
    }

    cout << ans << endl;
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--)
        solve();
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