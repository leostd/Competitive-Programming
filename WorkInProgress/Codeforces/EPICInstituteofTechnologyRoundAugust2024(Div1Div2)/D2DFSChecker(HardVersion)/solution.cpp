#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) ((int)x.size())
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define lsb(x) ((-x)&(x))
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

template<typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) +  ", " + to_string(get<2>(t)) + ")"; }

template<typename A>
string to_string(priority_queue<A> pq) {
    bool first = true;
    string res = "{";
    int sz = pq.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}

template<typename A>
string to_string(queue<A> q) {
    bool first = true;
    string res = "{";
    int sz = q.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;

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
const string abc = "abcdefghijklmnopqrstuvwxyz";
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<set<int>> g; //graph, grid
vector<int> subtreeSize, par, p, vis, idx;

int szDfs(int root) {
    vis[root] = 1;

    int ret = 0;
    for(auto v : g[root]) {
        if (!vis[v]) {
            ret += szDfs(v)+1;
        } 
    }

    return subtreeSize[root] = ret;
}

bool check(int x) {
    dbg(x);
    if (x == 1) return idx[x] == 1;

    int a = idx[x];
    int b = idx[x] + subtreeSize[x];
    int c = idx[par[x]];
    int d = idx[par[x]] + subtreeSize[par[x]];
    dbg(a,b,c,d);

    return a > c && a <= d && b >= a && b <= d; 
}

bool check2(int x) {
    if (x == 1) return idx[x] == 1;


}

void solve() {
    int q;
    cin >> n >> q;
    par.assign(n+1, 0);
    p.assign(n+1, 0);
    subtreeSize.assign(n+1, 0);
    g.assign(n+1, set<int>());
    idx.assign(n+1, 0);
    vis.assign(n+1, 0);
    par[1] = -1; // root of the tree
    fore(i, 2, n+1) cin >> par[i], g[par[i]].insert(i);
    for1(i, n+1) cin >> p[i], idx[p[i]] = i;

    dbg(p);
    dbg(par);
    dbg(g);

    szDfs(1);
    dbg(subtreeSize);


    set<int> misplaced;
    for1(i, n+1) {
        if (!check(i)) misplaced.insert(i);
    }
    dbg(misplaced);
    forn(i, q) {
        int x, y;
        cin >> x >> y;
        dbg(x, y);
        dbg("antes", p, idx);
        swap(idx[p[x]], idx[p[y]]);
        swap(p[x], p[y]);
        dbg("despues", p, idx);
        bool yes = true;
        bool c1 = check(p[x]);
        bool c2 = check(p[y]);
        if (!c1) misplaced.insert(p[x]);
        else if(!misplaced.empty()) misplaced.erase(p[x]);
        if (!c2) misplaced.insert(p[y]); 
        else if (!misplaced.empty()) misplaced.erase(p[y]);
    
        dbg("first checks passed");
        c1 = !g[p[x]].empty() && check(*g[p[x]].begin());
        c2 = !g[p[x]].empty() && check(*g[p[x]].rbegin());
        bool c3 = !g[p[y]].empty() && check(*g[p[y]].begin());
        bool c4 = !g[p[y]].empty() && check(*g[p[y]].rbegin());

        dbg("second checks passed");
        dbg("starting to process p[x] children");
        dbg(misplaced);
        dbg(g[p[x]], p[x]);
        if (!c1 && !g[p[x]].empty()) misplaced.insert(*g[p[x]].begin());
        else if (!misplaced.empty() && !g[p[x]].empty()) misplaced.erase(*g[p[x]].begin());
        dbg("check min child");
        dbg(misplaced);
        if (!c2 && !g[p[x]].empty()) misplaced.insert(*g[p[x]].rbegin());
        else if (!misplaced.empty() && !g[p[x]].empty()) misplaced.erase(*g[p[x]].rbegin());
        dbg("check max child");
        dbg(misplaced);
        dbg("processed p[x] children");

        if (!c3 && !g[p[y]].empty()) misplaced.insert(*g[p[y]].begin());
        else if (!misplaced.empty() && !g[p[y]].empty()) misplaced.erase(*g[p[y]].begin());
        if (!c4 && !g[p[y]].empty()) misplaced.insert(*g[p[y]].rbegin());
        else if (!misplaced.empty() && !g[p[y]].empty()) misplaced.erase(*g[p[y]].rbegin());

        dbg("processed p[y] children");
      //  for(auto v : g[p[x]]) {
      //      bool c3 = check(v);
      //      if (!c3) misplaced.insert(v);
      //      else misplaced.erase(v);
      //  }
      //  for(auto v : g[p[y]]) {
      //      bool c3 = check(v);
      //      if (!c3) misplaced.insert(v);
      //      else misplaced.erase(v);
      //  }

        cout << (misplaced.empty() ? "YES" : "NO") << endl;
    }
}
 
signed main() {
    fastIO(); 
    int t = nxt();
    while(t--) solve();
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
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/
