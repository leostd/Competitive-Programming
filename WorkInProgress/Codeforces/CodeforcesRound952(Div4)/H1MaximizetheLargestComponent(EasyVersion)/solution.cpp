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
vector<string> g; //graph, grid
vector<vector<int>> vis;

void dfs(int r, int c, vector<pii> &component) {
    vis[r][c] = 1;
    component.pb(mp(r, c));

    forn(i, 4) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (correct(nr, nc, n, m) && !vis[nr][nc] && g[nr][nc] == '#') {
            dfs(nr, nc, component);
        }
    }
}

void solve() {
    cin >> n >> m;
    
    string s;
    g.clear();
    vis.assign(n, vector<int>(m, 0));
    forn(i, n) cin >> s, g.pb(s);

    vector<vector<pii>> components;
    forn(i, n) {
        forn(j, m) {
            if (!vis[i][j] && g[i][j] == '#') {
                vector<pii> c;
                dfs(i, j, c);

                components.pb(c);
            }
        }
    }

    map<int, int> cntr, cntc;
    map<int, pii> rc, cc;
    forn(i, sz(components)) {
        for(auto [x,y] : components[i]) {
            if (rc.count(i)) {
                rc[i] = mp(min(rc[i].fst, x), max(rc[i].snd, x));
            } else {
                rc[i] = mp(x, x);
            }

            if (cc.count(i)) {
                cc[i] = mp(min(cc[i].fst, y), max(cc[i].snd, y));
            } else {
                cc[i] = mp(y, y);
            }

            cntr[x]++;
            cntc[y]++;
       }
    }

    dbg(components);
    vector<ll> rsum(n+2), csum(m+2);
    for(auto x : rc) {
        int l = x.snd.fst;
        int r = x.snd.snd;
        if (l-1 >= 0) l--;
        if (r+1 < n) r++;
        rsum[l] += sz(components[x.fst]);
        rsum[r+1] -= sz(components[x.fst]); 
        dbg(x);
        dbg(rsum);
    }

    for(auto x : cc) {
        int l = x.snd.fst;
        int r = x.snd.snd;
        if (l-1 >= 0) l--;
        if (r+1 < m) r++;
        csum[l] += sz(components[x.fst]);
        csum[r+1] -= sz(components[x.fst]);
    }

    for1(i, n) rsum[i] += rsum[i-1];
    for1(i, m) csum[i] += csum[i-1];
    dbg(rsum);
    dbg(csum);


    ll ans = 0;
    forn(r, n) {
        dbg("trying row: ", r);
        dbg(cntr[r]);
        dbg(rsum[r]);
        ll aux = 0;
        aux += m; 
        aux -= cntr[r];
        aux += rsum[r];
        ans = max(ans, aux);
    }

    forn(c, m) {
        dbg("trying col: ", c);
        ll aux = 0;
        aux += n;
        aux -= cntc[c];
        aux += csum[c];

        ans = max(ans, aux);
    }


    cout << ans << endl;
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

