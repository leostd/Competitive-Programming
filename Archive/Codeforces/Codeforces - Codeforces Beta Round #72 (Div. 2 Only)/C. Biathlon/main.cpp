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
vector<int> fh, radius, center;
vector<vector<int>> tgt, shs;
map<vector<int>, int> idx;

bool cmp(vector<int> a, vector<int> b) {
    return a[1] < b[1];
}

bool in(int c, int r, int x, int y) {
    double dist = sqr(x-c) + sqr(y);

    return dist <= sqr(r);
}

int hit(int i, int &touched) {
    dbg(i);
    int sx = shs[i][0], sy = shs[i][1];
    vector<int> aux({sx, sx});
    auto it = lower_bound(all(tgt), aux, cmp);
    dbg(*it);

    if (it == tgt.end() || (*it)[0] > sx)
        return -1;

    auto next = it+1;
    int nextid = -1;
    if (next != tgt.end())
        nextid = idx[*next];
    int ret = -1;
    int id = idx[*it];
    // int r = radius[id];
    dbg(id);
    if (in(center[id], radius[id], sx, sy)) {
        ret = id;
    } else {
        return -1;
    }
    dbg(ret);
    if (nextid != -1) {
        dbg(nextid);
        dbg(*next);
    }
    if (nextid != -1 && (*it)[1] == (*next)[0] && sy == 0 && sx == (*it)[1])
        touched = nextid;

    return ret;
}
 
int main() {
    fastIO(); 
    cin >> n;
    tgt.clear();
    tgt.assign(n, vector<int>(2,0));
    fh.clear();
    fh.assign(n, -1);
    radius.clear();center.clear();
    center.assign(n, 0);radius.assign(n, 0);
    forn(i, n) {
        cin >> center[i] >> radius[i];
        tgt[i][0] = center[i] - radius[i];
        tgt[i][1] = center[i] + radius[i];
        idx[tgt[i]] = i;
    }
    dbg(center);
    dbg(radius);
    dbg(tgt);

    cin >> m;
    shs.clear();
    shs.assign(m, vector<int>(2, 0));
    forn(i, m) {
        cin >> shs[i][0] >> shs[i][1];
    }
    dbg(shs);

    sort(all(tgt), cmp);
    dbg(tgt);

    int ont = 0;
    forn(i, m) {
        int touched = -1;
        int h = hit(i, touched);
        if (h != -1) {
            if (fh[h] == -1)
                fh[h] = i+1, ont++;
        }
        if (touched != -1) {
            if (fh[touched] == -1)
                fh[touched] = i+1, ont++;
        }
    }
    dbg(fh);

    cout << ont << endl;
    forn(i, n) {
        cout << fh[i] << " ";
    }
    cout << endl;

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