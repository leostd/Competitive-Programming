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
const int MAXN = 102;

int n, m; // sizes
vector<vector<vector<int>>> g[12]; //graph, grid
 
void printMatrix(vector<vector<int>> mat) {
    #ifndef DEBUG
        return;
    #endif
    forn(i, mat.size()) {
        forn(j, mat[0].size()) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << "-------------------------" << endl;
}

int main() {
    fastIO(); 
    int q, c;
    cin >> n >> q >> c;
    forn(i, 12)
        g[i].assign(MAXN, vector<vector<int>>(MAXN, vector<int>()));

    int x, y, s;
    forn(i, n) {
        cin >> x >> y >> s;
        dbg(x,y,s);
        g[0][x][y].pb(s);
    }
    dbg(0);
    // printMatrix(g[0]);

    for1(i, c+1) {
        for1(j, MAXN) {
            for1    (k, MAXN) {
                if (g[i-1][j][k].empty()) continue;

                // g[i][j][k] = g[i-1][j][k]+1 <= c? g[i-1][j][k]+1 : 0;
                int sz = g[i-1][j][k].size();
                dbg(sz);
                forn(l, sz) {
                    g[i][j][k].pb(g[i-1][j][k][l]+1 <= c? g[i-1][j][k][l]+1 : 0);
                }
            }
        }
        dbg(i);
        // printMatrix(g[i]);
    }

    vector<vector<int>> psum[12];
    forn(i, c+1) {
        psum[i].assign(MAXN, vector<int>(MAXN, 0));
    }

    forn(i, c+1) {
        for1(j, MAXN) {
            for1(k, MAXN) {
                // if (g[i][j][k].empty()) {
                //     psum[i][j][k] = psum[i][j][k];
                //     continue;
                // }
                int sz = g[i][j][k].size();
                dbg(sz);
                int sum = 0;
                forn(l, sz) sum += g[i][j][k][l];
                dbg(sum);
                psum[i][j][k] = sum + psum[i][j-1][k] + psum[i][j][k-1] - psum[i][j-1][k-1]; 
            }
        }

        dbg(i);
        // printMatrix(psum[i]);
    }

    int x1,y1,x2,y2;
    forn(i, q) {
        // bright - bottom left corner - top right corner
        cin >> s >> x1 >> y1 >> x2 >> y2;
        int t = s%(c+1);
        dbg(t);
        int x3, y3, x4, y4;
        dbg(x1, y1);
        dbg(x2, y2);    
        // upper left corner
        x3 = x1, y3 = y2;
        dbg(x3, y3);

        // bottom left corner
        x4 = x2, y4 = y1;
        dbg(x4, y4);
        ll sum = psum[t][x2][y2] - psum[t][x4][y4-1] - psum[t][x3-1][y3] + psum[t][x1-1][y1-1];
        // dbg(psum[t][x2][y2], psum[t][x1][y1-1], psum[t][x2-1][y2], psum[t][x3-1][y3-1], sum);
        cout << sum << endl;
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