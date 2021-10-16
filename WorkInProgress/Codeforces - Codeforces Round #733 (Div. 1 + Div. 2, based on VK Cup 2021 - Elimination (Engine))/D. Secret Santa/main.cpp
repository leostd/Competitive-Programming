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
vector<vector<int>> g; //graph, grid
 
bool allDiff(vector<int> &v) {
    set<int> u;
    forn(i, n) u.insert(v[i]);

    return (int)u.size() == n;
}

int verify(vector<int> &a, vector<int> &b) {
    int cnt = 0;
    forn(i, n) cnt += a[i] == b[i];

    return cnt;
}

bool notSelf(vector<int> &a) {
    forn(i, n) {
        if (a[i] == i+1)
            return false;
    }

    return true;
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--) {
        n = nxt();
        dbg(n);
        vector<int> w(n), b(n);
        forn(i,n) cin >> w[i], w[i]--;

        set<int> u, rem;
        map<int, int> gives, recFrom;

        forn(i, n) rem.insert(i);
        forn(i, n) {
            if (u.count(w[i]) == 0) {
                gives[i] = w[i];
                recFrom[w[i]] = i;
                u.insert(w[i]);
            } else {  // override current state
                gives[i] = w[i];
                gives.erase(recFrom[w[i]]);
                recFrom[w[i]] = i;
            }
        }
        dbg(gives);
        dbg(recFrom);

        // fill the rest
        set<int> remg, remr;
        forn(i, n) remg.insert(i), remr.insert(i);

        for(auto x : gives) remg.erase(x.fst);
        for(auto x : recFrom) remr.erase(x.fst);

        dbg(remg);
        dbg(remr);

        while(!remg.empty()) {
            int x = *remg.begin();
            int y = *remr.rbegin();

            if (x == y)
                y = *remr.begin();

            if (x == y) {
                int ws = w[x];
                dbg(ws);
                int gw = gives[ws];
                int rw = recFrom[gw];
                int rww = recFrom[ws];
                dbg(rww);
                dbg(gw, rw);
                // override;
                gives[x] = ws;
                gives[recFrom[ws]] = x;
                break;
            }

            gives[x] = y;
            recFrom[y] = x;

            remg.erase(x);
            remr.erase(y);
        }
        
        dbg(gives);
        for(auto x : gives) {
            b[x.fst] = x.snd+1;
        }
    
        cout << u.size() << endl;
        forn(i, n) {
            cout << b[i] << " ";
        }
        cout << endl;

        forn(i, n) w[i]++;
        dbg(allDiff(b));
        dbg(notSelf(b));
        dbg((int)u.size() == verify(b, w));
        dbg(b);
        dbg(w);
        
        #ifdef DEBUG
            cout << "----------------" << endl;
        #endif
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