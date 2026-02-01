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

int parent[1000];
vector<tuple<double, int,int>> edg;

int uf_find(int x){
    edg.clear();
    if (x == parent[x])
        return x;
    return parent[x] = uf_find(parent[x]);
}

void uf_union(int x, int y){
    int rootx = uf_find(x);
    int rooty = uf_find(y);

    if (rootx != rooty){
        parent[rooty] = rootx;
    }
}

void init() {
    forn(i, 1000)
        parent[i] = i;
}

double dist(int x, int y, int x1, int y1) {
    return sqrt(sqr(x-x1) + sqr(y-y1));
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--) {
        int s = nxt(), p = nxt();

        vector<pii> points(p, mp(0,0));
        forn(i,p)
            cin >> points[i].fst >> points[i].snd;

        forn(i, p){
            fore(j, i+1, p){
                edg.push_back(make_tuple(dist(points[i].fst, points[i].snd, points[j].fst, points[j].snd), i, j));
            }
        }

        // debug_out(points);
        sort(all(edg));
        forn(j, edg.size()){
            double x;
            int y, z;
            tie(x,y,z) = edg[j];
            // debug_out(x, y, z);
        }
        vector<tuple<double, int, int>> mst;
        // Picture it. If we have s satellites we will have a connected component, connected by radio
        // and a connected component connected by satellite. It will be enough only one edge from component
        // to another to comply with the problem statement. 
        // By definition, given a graph with N nodes, an MST will have N-1 edges. In this case, we will have N - (S-1)
        // There will be N - S cities connected by radio. MST for that component will have N - S - 1 edges. Given that we need to
        // connect both components, we need another edge, so we end up with N-S edges.
        int cur = 0;
        double ans = 0;
        init();
        while(mst.size() < p - s){
            int x, y, z;
            // debug_out(mst.size(), p-s, cur);
            tuple<double, int, int> aux = edg[cur++];
            tie(x, y, z) = aux; 
            // debug_out(x, y, z);
            if (uf_find(get<1>(aux)) != uf_find(get<2>(aux))){
                uf_union(get<1>(aux), get<2>(aux));
                ans = get<0>(aux);
                mst.push_back(aux);
            }
        }
        cout << setprecision(2) << fixed;
        cout << ans << endl;
    }
    return 0;
}