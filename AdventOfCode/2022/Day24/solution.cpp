#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
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
 
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<vector<vector<int>>> g; //graph, grid
int ans;
                               
int move(char x) {
    if (x == '>') return 0;
    if ( x == '<' ) return 1;
    if (x == 'v') return 2;
    if (x == '^') return 3;
    dbg("This must be an error");
    //dbg(x);
    cout << x << endl;
    return -1;
}

void readInput() {
    string ln;
    vector<string> gr;
    while(cin >> ln) gr.pb(ln);

    n = gr.size();
    m = gr[0].size();
    
    g.assign(n, vector<vector<int>>(m, vector<int>()));

    for1(i, n-1) {
        for1(j, m-1) {
            if (gr[i][j] != '.') {
                g[i][j].pb(move(gr[i][j]));
            }
        }
    }

    forn(i,m) {
        g[0][i].pb(-1);
        g[n-1][i].pb(-1);
    }

    forn(i, n) {
        g[i][0].pb(-1);
        g[i][m-1].pb(-1);
    }

    g[n-1][m-2].clear();
    g[0][1].clear();
    dbg(gr);
    dbg(g);
}

void update(vector<vector<vector<int>>> &ng, int r, int c, int mv) {
    int nr, nc;
    if (mv == 0) {
        nr = r, nc = c + 1;
        if (nc == m-1) nc = 1;
    }

    if (mv == 1) {
        nr = r, nc = c-1;
        if (nc == 0) nc = m-2;
    }

    if (mv == 2) {
        nr = r+1, nc = c;
        if (nr == n-1) nr = 1;
    }

    if (mv == 3) {
        nr = r-1, nc = c;
        if (nr == 0) nr = n-2;
    }

    ng[nr][nc].pb(mv);
}

void drawG() {
    forn(i, n) {
        forn(j, m) {
            cout << to_string(g[i][j]) << " ";
        }
        cout << endl;
    }
}

void updateG() {
    vector<vector<vector<int>>> ng(n, vector<vector<int>>(m, vector<int>()));
    for1(i, n-1) {
        for1(j, m-1) {
            forn(k, (int)g[i][j].size()) {
                update(ng, i, j, g[i][j][k]);
            }
        }
    }
    g = ng;

    forn(i,m) {
        g[0][i].pb(-1);
        g[n-1][i].pb(-1);
    }

    forn(i, n) {
        g[i][0].pb(-1);
        g[i][m-1].pb(-1);
    }
    g[n-1][m-2].clear();
    g[0][1].clear();

    drawG();
}

int bfs(pii src, pii dst, int t0) {
    queue<vector<int>> q;
    q.push(vector<int>({src.fst, src.snd, t0}));
    set<vector<int>> vis;
    while(!q.empty()) {
        updateG();
        int sz = q.size();
        forn(i, sz) {
            vector<int> a = q.front();
            q.pop();
            int r, c, t;
            r = a[0], c = a[1], t = a[2];
            dbg(r, c, t);
            if (r == dst.fst && c == dst.snd) {
                return t;
            }
            forn(j, 4) {
                int nr = r + dx[j];
                int nc = c + dy[j];
                vector<int> v({nr, nc, t+1});
                if (correct(nr, nc, n, m) && g[nr][nc]. empty() && !vis.count(v)) {
                    q.push(vector<int>(v));
                    vis.insert(v);
                }
            }
            vector<int> aux({r,c,t+1});
            if (!vis.count(vector<int>(aux)) && g[r][c].empty()) {
                vis.insert(vector<int>(aux));
                q.push(vector<int>(aux));
            }
        }
    }

    return -1;

}

void solve1() {
    dbg(n, m);
    queue<vector<int>> q;
    q.push(vector<int>({0, 1, 0}));
    set<vector<int>> vis;
    while(!q.empty()) {
        updateG();
        int sz = q.size();
        bool found = false;
        forn(i, sz) {
            vector<int> a = q.front();
            q.pop();
            int r, c, t;
            r = a[0], c = a[1], t = a[2];
            dbg(r, c, t);
            if (r == n-1 && c == m-2) {
                ans = t;
                found = true;
                break;
            }
            forn(j, 4) {
                int nr = r + dx[j];
                int nc = c + dy[j];
                vector<int> v({nr, nc, t+1});
                if (correct(nr, nc, n, m) && g[nr][nc]. empty() && !vis.count(v)) {
                    q.push(vector<int>(v));
                    vis.insert(v);
                }
            }
            vector<int> aux({r,c,t+1});
            if (!vis.count(vector<int>(aux)) && g[r][c].empty()) {
                vis.insert(vector<int>(aux));
                q.push(vector<int>(aux));
            }
        }
        if (found) break;
    }

    cout << ans << endl;
}
 
void solve2() {
    pii src = mp(0, 1);
    pii dst = mp(n-1, m-2);
    int ans = bfs(src, dst, 0);
    ans = bfs(dst, src, ans+1);
    ans = bfs(src, dst, ans+1);
    cout << ans << endl;
}
int main() {
    fastIO(); 
    readInput();
    //solve1();
    solve2();
    
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

