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

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

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

vector<pii> generals(int x0, int y0, int x1, int y1) {
    vector<pii> r;
    if (x0>x1)
        swap(x0, x1), swap(y0, y1);

    for (int i = x0; i <= x1; i++)
        r.pb(mp(i, y0));

    for (int i = x1; i >= x0; i--)
        r.pb(mp(i, y1));
    
    if (y0 > y1) {
        for (int i = y0-1; i > y1; i--)
            r.pb(mp(x0, i));

        for (int i = y1+1; i < y0; i++)
            r.pb(mp(x1, i));
    }
    else {
        for (int i = y0+1; i < y1; i++)
            r.pb(mp(x0, i));

        for (int i = y1-1; i > y0; i--)
            r.pb(mp(x1, i));
    }

    return r;
}

int main() {
    fastIO(); 
    int x0,y0,x1,y1;
    cin >> x0 >> y0 >> x1 >> y1;

    // debug_out(x0, y0);
    // debug_out(x1, y1);
    
    int n = nxt();
    int x, y, r;
    int dist;
    vector<pii> g = generals(x0,y0,x1,y1);
    vector<bool> h(g.size(), false);
    sort(all(g));
    // debug_out(g);
    // debug_out(n);

    forn(i, n){
        cin >> x >> y >> r;
        // debug_out(x, y, r);
        forn(j,g.size()) {
            dist = sqr(x-g[j].fst) + sqr(y-g[j].snd);
            // debug_out(g[j], dist, sqr(r));
            if (dist <= sqr(r))
                h[j] = true;
        }
        // debug_out("---\n");
    }

    int ans = 0;
    
    forn(i,h.size()) {
        // cout << h[i] << " ";
        ans += (h[i] == 0);
    }

    cout <<endl << ans << endl;
    return 0;
}