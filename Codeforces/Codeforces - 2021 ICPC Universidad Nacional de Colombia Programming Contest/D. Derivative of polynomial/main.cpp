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
struct term {
    bool single;
    int a;
    int ex;
    term() {
        single = true;
        a = 0;
        ex = 1;
    }
 
    term(bool s, int _a, int _ex) {
        single = s;
        a = _a;
        ex = _ex;
    }
 
    void _to_string() {
        if (single)
            cout << a;
        else
            cout << a << "x" << (abs(ex) > 1 ? "^" + to_string(ex) : "");
    }
 
    term operator+(term &other) {
 
        return term(single, other.a + a, ex);
    }
 
    term d() {
        if (single) {
            return term();
        }
        int w = ex;
        int nex = ex-1;
        int na = w * a;
        return term(nex==0, na, nex);
    }
};
 
int rev(int x) {
    vector<int> d;
    while(x) {
        d.pb(x%10);
        x/= 10;
    }
    int ret = 0;
    int pw = 1;
    nfor(i, (int)d.size()) {
        ret += pw*d[i];
        pw *= 10;   
    }
    return ret;
}
 
int convert(vector<int> d) {
    if (d.empty()) return 0;
    int ret = 0;
    int pw = 1;
    nfor(i, (int)d.size()) {
        ret += pw*d[i];
        pw *= 10;   
    }
    return ret;
}
 
vector<term> getTerms(string s) {
    vector<term> ret;
    int i = 0;
    n = s.size();
    while(i < n) {
        int sign = 0;
        if (i == 0) {
            sign = (s[0] == '-' ? -1 : 1);
            if (sign == -1) i++;
        } else {
            sign = (s[i] == '-' ?  -1 : 1);
            i++;
        }
        int j = i;
        int cur = 0;
        int ex = 0;
        int exsign = 1;
        int pw = 1;
        bool hasCoefficient = false;
        vector<int> curd, exd;
        while(j < n && s[j] != '-' && s[j] != '+') {
            if (s[j] == 'x') {
                hasCoefficient = true;
                pw = 1;
                ex = 1;
                exsign = 1;
                if (curd.empty())
                    curd.pb(1); 
                exd.pb(1);
                if (j+1 < n && s[j+1] == '^') {
                    exd.clear();
                    j+=2;
                    if (j < n && s[j] == '-') {
                         exsign = -1, j++;
                    }
                } else {
                    j++;
                }
 
                continue;
            }
            if (!hasCoefficient)
                curd.pb(s[j] - '0');
            else
                exd.pb(s[j]-'0');
            j++;
        }
        dbg(curd, exd);
        term nt = term(ex == 0, convert(curd)*sign, convert(exd)*exsign);
        ret.pb(nt);
        i = j;
    }
 
    return ret;
}
 
 
int main() {
    fastIO(); 
    string p;
    cin >> p;
    if (p == "0") {
        cout << 0 << endl;
        return 0;
    }
 
    vector<term> ts = getTerms(p);
    // for(int i = 0; i < (int)ts.size(); i++) {
    //     ts[i]._to_string();
    //     cout << " derivada: "; 
    //     ts[i].d()._to_string();
    //     cout << endl;
    // }
    map<int, term> aux;
    for(auto t : ts) {
        term der = t.d();
        if (der.a == 0) continue;
        if (aux.count(der.ex) == 0) {
            aux[der.ex] = der;
        } else {
            aux[der.ex] = aux[der.ex] + der;
        }
    }
 
    if (aux.empty()) {
        cout << 0 << endl;
        return 0;
    }
    bool first = true;
    if (!aux.empty()) {
        bool flag = false;
        for(auto t : aux) {
            if (t.second.a == 0) continue;
            if(!first && t.second.a > 0) cout <<"+";
            t.snd._to_string();
            first = false;
            flag = true;
        }
        if (!flag) {
            cout << 0;
        }
        cout << endl;
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