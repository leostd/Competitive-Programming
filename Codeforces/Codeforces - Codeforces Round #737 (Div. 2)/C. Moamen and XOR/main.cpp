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
 
const int MOD = 1000000007;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
 
//#############################
const int MAXN = 1000005;

int n, m, k; // sizes
vector<vector<int>> g; //graph, grid
ll memo[200005][2];

ll mod_mult(ll a, ll b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

ll mod_sum(ll a, ll b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

ll mod_exp(ll a, ll b) {
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

ll mod_inv(ll a) {
    return mod_exp(a, MOD-2)%MOD;
}

ll mod_sub(ll a, ll b) {
    return ((a%MOD) - (b%MOD) + MOD) % MOD;
}

ll aux;
ll inv2, pow2n;

ll dp(int i, int isGreater) {
    // dbg(i, isGreater);
    if (i == 0)
        return !isGreater;

    ll &ret = memo[i][isGreater];
    if (ret != -1) {
        return ret;
    }

    if (n % 2 == 0) {
        if (isGreater)
            ret = mod_exp(pow2n, i-1);
        else {
            ll a = mod_mult(mod_sub(mod_mult(pow2n, inv2), 1), mod_sum(dp(i-1, 0), dp(i-1, 1)));
            // ll b = mod_mult(mod_sub(mod_mult(mod_exp(2, n), mod_inv(2)), 1), dp(i-1, 1));
            // dbg(a, b);
            // ret = mod_sum(a, dp(i-1, 1));
            ret = a;
        }
    } else {
        if (isGreater)
            ret = 0;
        else {
            ll a = mod_mult(pow2n, inv2);
            ret = mod_mult(mod_sum(a, 1), dp(i-1, 0));
        }
    }

    return ret;
}

ll valid;

bool isValid(vector<int> arr) {
    ll andexp = arr[0], xorexp = arr[0];
    for1(i, n) {
        andexp &= arr[i];
        xorexp ^= arr[i];
    }

    return andexp >= xorexp;
}

void bf(vector<int> arr) {
    if ((int)arr.size() == n) {
        valid += isValid(arr);
        return;
    }

    for(int x = 0; x < (1 << k); x++) {
        arr.pb(x);
        bf(arr);
        arr.pop_back();
    }
}


int main() {
    fastIO(); 
    int t;
    cin >> t;
    dbg(mod_exp(12, 2));
    dbg(mod_exp(2, 10));
    dbg(mod_exp(2, 200000));
    inv2 = mod_inv(2);
    while(t--) {
        cin >> n >> k;
        pow2n = mod_exp(2, n);
        dbg(n, k);
        memset(memo, -1, sizeof(memo));
        ll x = dp(k, 0);
        ll y = dp(k, 1);
        ll ans = mod_sum(x, y);
        vector<int> v;
        valid = 0;
        // bf(v);
        // dbg(valid, ans);
        dbg(x, y);
        // assert(valid == ans);
        cout << ans << endl;
    }
    memset(memo, -1, sizeof(memo));
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