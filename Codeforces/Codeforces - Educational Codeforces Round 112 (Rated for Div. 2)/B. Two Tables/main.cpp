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

int n, m; // sizes
vector<vector<int>> g; //graph, grid
double W, H;
double w, h;
double x1, x2, yy1, yy2;

bool good(double a, double b) {
    return a >= 0 && a <= b;
}

bool canPlaceRight(double &aux) {
    double nw = W - x2;
    double nh = H;

    double wd = nw - w;
    double hd = nh - h;

    if (wd >= 0  && hd >= 0) {
        aux = 0.0;
        return true;
    }
    
    double nx2 = x2 - abs(wd);
    double nx1 = x1 - abs(wd);

    dbg(nx1, nx2, correct(nx1, nx2, W+1, W+1));
    if (hd < 0 || !correct(nx1, nx2, W+1, W+1))
        return false;
    
    aux = abs(wd);

    return true;
}

bool canPlaceLeft(double &aux) {
    double nw = x1;
    double nh = H;

    double wd = nw - w;
    double hd = nh - h;

    if (wd >= 0  && hd >= 0) {
        aux = 0.0;
        return true;
    }
    
    // dbg(wd);
    double nx2 = x2 + abs(wd);
    double nx1 = x1 + abs(wd);
    // dbg(nx1, nx2, correct(nx1, nx2, W+1, W+1));
    if (hd < 0 || !correct(nx1, nx2, W+1, W+1))
        return false;
    
    aux = abs(wd);

    return true;
}

bool canPlaceAbove(double &aux) {
    double nw = W;
    double nh = H - yy2;

    double wd = nw - w;
    double hd = nh - h;

    if (wd >= 0  && hd >= 0) {
        aux = 0.0;
        return true;
    }

    double ny2 = yy2 - abs(hd);
    double ny1 = yy1 - abs(hd);

    // dbg(ny1, ny2, correct(ny1, ny2, H+1, H+1));
    if (wd < 0 || !correct(ny1, ny2, H+1, H+1))
        return false;
    
    aux = abs(hd);
    return true;
}

bool canPlaceBelow(double &aux) {
    double nw = W;
    double nh = yy1;

    double wd = nw - w;
    double hd = nh - h;
    dbg(wd, hd);
    if (wd >= 0  && hd >= 0) {
        aux = 0.0;
        return true;
    }

    double ny2 = yy2 + abs(hd);
    double ny1 = yy1 + abs(hd);
    // dbg(ny1, ny2, correct(ny1, ny2, H+1, H+1));
    if (wd < 0 || !correct(ny1, ny2, H+1, H+1))
        return false;
    
    aux = abs(hd);

    return true;
}
 
void updateAns(double &aux, double &ans) {
    if (aux < EPS) {
        ans = aux;
    } else {
        ans = min(ans, aux);
    }
}

void solve() {
    cin >> W >> H;
    cin >> x1 >> yy1 >> x2 >> yy2;
    cin >> w >> h;
    dbg(x1, yy1, x2, yy2);
    double aux, ans = INF;
    bool can = false;
    if (canPlaceRight(aux)) {
        updateAns(aux, ans);
        can = true;
    }
    
    if(canPlaceLeft(aux)) {
        updateAns(aux, ans);
        can = true;
    }

    if (canPlaceAbove(aux)) {
        updateAns(aux, ans);
        can = true;
    }

    if (canPlaceBelow(aux)) {
        updateAns(aux, ans);
        can = true;
    }

    if (!can) {
        cout << -1 << endl;
        return;
    }

    cout << setprecision(7) << fixed;
    cout << ans  << endl;
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