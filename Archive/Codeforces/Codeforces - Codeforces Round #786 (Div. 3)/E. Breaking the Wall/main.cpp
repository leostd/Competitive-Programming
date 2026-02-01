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

 
inline int f(vector<int> x) {
    map<int, vector<int>> idx;
    forn(i, n) idx[x[i]].pb(i);
    auto it = idx.begin();
    int ans = 0;
    if (it->snd.size() > 1) {
        int num = it->fst;
        ans += (num/2) + (num%2);
        ans *= 2;
    } else {
        int num = it->fst;
        ans += (num/2) + (num%2);
        it++;
        num = it->fst;
        ans += (num/2) + (num%2);
    }

    return ans;
}

int destroy2(int a, int b) {
    return (a+b) / 3 + ((a+b) % 3 != 0);
}

int g(vector<int> &x) {
    int ret = INF;
    for1(i, n) {
        ret = min(ret, destroy2(x[i-1], x[i]));
    }

    return ret;
}

bool check(vector<int> &x) {
    int cnt = 0;
    forn(i, 3) cnt += x[i] <= 0;

    return cnt < 2;
}

int destroy3(vector<int> &x) {
    int cnt = 0;
    if (x[1] < x[0] || x[1] < x[2]) 
        return min(destroy2(x[1], x[0]), destroy2(x[2], x[1]));
    int mx = max(x[0], x[2]);
    int mn = min(x[0], x[2]);
    int c = x[1]-mx;
    if (c >= mn) {
        mx -= mn;
        x[1] -= 2*mn;
        int md = min(x[1], mx);
        return mn + md/2 + (md%2);
    } else {
        mx -= c;
        x[1] -= 2*c;
        mn -= c;
        return c + min(destroy2(mn, x[1]), destroy2(x[1], mx));
    }
}

int h(vector<int> &x) {
    int ret = INF;
    for(int i = 2; i < n; i++) {
        vector<int> aux;
        aux.insert(aux.end(), {x[i-2], x[i-1], x[i]});
        dbg(aux);
        ret = min(ret, destroy3(aux));
    }

    return ret;
}



int main() {
    fastIO(); 
    cin >> n;
    vector<int> a(n);
    generate(all(a), nxt);
    dbg(a);

    int aa = f(a);
    int b = g(a);
    int c = h(a);

    cout << min(aa, min(b, c)) << endl;
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