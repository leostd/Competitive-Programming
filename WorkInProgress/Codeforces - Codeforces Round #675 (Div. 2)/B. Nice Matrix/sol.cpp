/*
    think first, always - c,g,a, alg - r,s,iag?,iabs?
*/

#pragma GCC diagnostic ignored "-Wunused-const-variable"
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

// This can be improved. The median of these values will be
// the one generating the minimum cost.
ll getMinCost(vector<ll> a){
    ll aux = INF64;
    for(auto x : a){
        ll cost = 0;
        for (auto y : a){
            cost += abs(x - y);
        }
        aux = min(aux, cost);
    }
    
    return aux;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> g(n, vector<ll>(m, 0));
    forn(i, n)
        forn(j, m)
            cin >> g[i][j];
    
    dbg(g);

    ll ans = 0;
    forn(i, n/2) {
        forn(j, m/2) {
            vector<ll> a({g[i][j], g[n-i-1][j], g[i][m-j-1], g[n-i-1][m-j-1]});
            dbg(a);
            ans += getMinCost(a);
        }
    }
    if (n % 2){
        for(int i = 0; i < m/2; i++){
            vector<ll> a({g[n/2][i], g[n/2][m-i-1]});
            dbg(a);
            ans += getMinCost(a);
        }            
    }

    if (m % 2){
        for(int i = 0; i < n/2; i++){
            vector<ll> a({g[i][m/2], g[n-i-1][m/2]});
            ans += getMinCost(a);
        }  
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