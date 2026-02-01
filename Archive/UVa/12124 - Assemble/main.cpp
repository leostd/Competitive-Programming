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

struct Component {
    string type;
    string name;
    ll price;
    ll quality;
};


bool cmp(Component a, Component b) {
    return a.type < b.type;
}

int n, m; // sizes
ll budget;
vector<vector<int>> g; //graph, grid
map<int, vector<pll>> mapByType;

bool f(ll q) {
    ll tmp_budget = 0;

    for(auto v : mapByType){
        // dbg(v.snd);
        auto it = lower_bound(all(v.snd), mp(q, 0LL));
        if (it == v.snd.end())
            return false;
        ll min_price = it->snd;
        while(it != v.snd.end()){
            min_price = min(min_price, it->snd);
            it++;
        }
        tmp_budget += min_price;
    }

    return tmp_budget <= budget;
}

void solve() {
    cin >> n >> budget;
    vector<Component> components(n, Component());
    forn(i, n) {
        cin >> components[i].type >> components[i].name >> components[i].price >> components[i].quality;
    }

    sort(all(components), cmp);
    string aux = components[0].type;
    int cur = 0;
    ll mn = INF64, mx = -1;
    mapByType.clear();
    forn(i, n) {
        if (components[i].type != aux) {
            cur++;
            aux = components[i].type;
            mapByType[cur].pb(mp(components[i].quality, components[i].price));
        } else {
            mapByType[cur].pb(mp(components[i].quality, components[i].price));
        }
        mn = min((ll)mn, components[i].quality);
        mx = max((ll)mx, components[i].quality);
    }

    for(auto &v : mapByType)
        sort(all(v.second));

    ll l = mn, r = mx, mid;
    while(r-l > 1) {
        mid = l + (r-l)/2;
        if (f(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }

    ll ans = (f(r) ? r : l); 
    cout << ans << endl;
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--){
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
*/