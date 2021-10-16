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
 
bool isPossible(int r, int c, vector<vector<int>> &gr) {
    int h = gr.size();
    int w = gr[0].size();
    forn(i, 8) {
        int nr = r + dxK[i];
        int nc = c + dyK[i];
        if (!correct(nr, nc, h, w)) continue;

        if (gr[nr][nc] == 1) return false;
    }

    return true;
}

int fillGrid(vector<vector<int>> &gr) {
    // first row
    int h, w;
    h = gr.size();
    w = gr[0].size();
    int ret = 1;
    int r, c;
    for(int i = 0; i < w; i++) {
        r = 0;
        c = i;
        if (gr[r][c] == 1) continue;
        if (correct(r, c, h, w) && isPossible(r, c, gr))
            gr[r][c] = 1, ret++;
    }

    // last column
    for(int i = 1; i < h; i++) {
        r = i;
        c = w-1;
        if (gr[r][c] == 1) continue;
        if (correct(r, c, h, w) && isPossible(r, c, gr))
            gr[r][c] = 1, ret++;
    }

    // last row
    for(int i = w-2; i >= 0; i--) {
        r = h-1;
        c = i;
        if (gr[r][c] == 1) continue;
        if (correct(r, c, h, w) && isPossible(r, c, gr))
            gr[r][c] = 1, ret++;
    }

    // first column
    for(int i = h-2; i >= 0; i--) {
        r = i;
        c = 0;
        if (gr[r][c] == 1) continue;
        if (correct(r, c, h, w) && isPossible(r, c, gr))
            gr[r][c] = 1, ret++;
    }

    return ret;
}

void printMatrix(vector<vector<int>> &gr) {
    int n = gr.size();
    int m = gr[0].size();
    forn(i, n) {
        forn(j, m) {
            cout << gr[i][j];
        }
        cout << endl;
    }
}

int main() {
    fastIO(); 
    int t = nxt();
    dbg(t);
    while(t--) {
        int h, w;
        cin >> h >> w;
        dbg(h, w);
        vector<vector<int>> g(h, vector<int>(w, 0));
        vector<vector<int>> o1, o2;
        o1 = o2 = g;
        o1[0][0] = 1;
        o2[0][1] = 1;
        int f1 = fillGrid(o1);
        int f2 = fillGrid(o2);
        dbg(f1, f2);
        if (f1 > f2) {
            printMatrix(o1);
        } else {
            printMatrix(o2);
        }
        cout << endl;
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