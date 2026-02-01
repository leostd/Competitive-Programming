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
#include <time.h>
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

class Matrix {
public:
    
    Matrix(int _n, int _m, bool identity = false) {
        nrow = 2;
        ncol = 2;
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                m[i][j] = 0;
            }
        }
        if (identity) {
            for(int i = 0; i < nrow; i++) {
                m[i][i] = 1;
            }
        }
    }
    
    void set(int i, int j, ll num) {
        m[i][j] = num;
    }

    ll get(int i, int j) {
        return m[i][j];
    }

    void print() {
        for(int i = 0; i < nrow; i++) {
            for(int j = 0; j < ncol; j++) {
                cout << m[i][j] << " ";
            }
            cout << endl;
        }
    }

    const pair<int, int> dim() {
        return make_pair(nrow, ncol);
    }

    inline Matrix sum(Matrix &b) {
        assert(b.dim() == dim());

        Matrix c(nrow, ncol);
        for(int i = 0; i < nrow; i++) {
            for(int j = 0; j < ncol; j++) {
                c.set(i,j, m[i][j] + b.get(i, j));
            }
        }

        return c;
    }

    bool isSquare() {
        return nrow == ncol;
    }

    inline Matrix pow(int p) {
        Matrix ret(nrow, ncol, true);
        Matrix y = *this;

        while(p) {
            if (p&1) {
                ret = ret * y;
            }

            y = y*y;
            p >>= 1;
        }

        return ret;
    }

    inline Matrix mult(Matrix &b) {
        pair<int, int> adim = dim();
        pair<int, int> bdim = b.dim();

        Matrix c(adim.first, bdim.second);
        for(int i = 0; i < adim.first; i++) {
            for(int j = 0; j < bdim.second; j++) {
                for(int k = 0; k < adim.first; k++) {
                    c.set(i,j, c.get(i, j) + m[i][k] * b.get(k, j));
                }   
            }
        }

        return c;
    }

    inline Matrix modMult(Matrix &b, ll &mod) {
        pair<int, int> adim = dim();
        pair<int, int> bdim = b.dim();

        Matrix c(adim.first, bdim.second);
        for(int i = 0; i < adim.first; i++) {
            for(int j = 0; j < bdim.second; j++) {
                for(int k = 0; k < adim.first; k++) {
                    c.set(i,j, ((c.get(i, j)) + ((m[i][k]) * (b.get(k, j)%mod))%mod)%mod);
                }   
            }
        }

        return c;
    }

    inline Matrix modPow(int p, ll mod) {

        Matrix ret(nrow, ncol, true);
        Matrix y = *this;

        while(p) {
            if (p&1) {
                ret = ret.modMult(y, mod);
            }
            y = y.modMult(y, mod);
            p >>= 1;
        }

        return ret;
    }
    
    const Matrix operator+(Matrix &b) {
        return sum(b);
    }

    const Matrix operator*(Matrix &b) {
        return mult(b);
    }

    bool operator==(Matrix &b) {
        if (b.dim() != dim()) return false;

        for(int i = 0; i < nrow; i++) {
            for(int j = 0; j < ncol; j++) {
                if (m[i][j] != b.get(i, j))
                    return false;
            }
        }

        return true;
    }

private:
    ll m[2][2];
    int nrow;
    int ncol;
};



int n, m;

Matrix a(2, 2), b(2, 1);
void solve() {
    ll p = (1 << m);
    dbg(n, p);
    Matrix c = a.modPow(n-1, p);
    printf("%lld\n", (c.get(0,0) + c.get(0,1))%p);
}
int main() {
    time_t start, end;
    // fastIO(); 
    
    time(&start);
    a.set(0, 1, 1);
    a.set(1, 0, 1);
    a.set(1, 1, 1);
    while(scanf("%d %d", &n, &m) != EOF) {
        solve();
    }
    time(&end);
    double exec_time = double(end-start);
    #ifdef DEBUG
        cout << "Time taken by the program: " << fixed << setprecision(10) << exec_time;
        cout << " seconds" << endl; 
    #endif
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