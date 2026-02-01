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

//                 R, L, D, U
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

ll f(iii st) {
    // R, L, D, U
    set<iii> vis;
    queue<iii> q;
    q.push(st);
    vis.insert(st);
    vector<vector<int>> aux(sz(g), vector<int>(sz(g[0]), 0));
    aux[get<0>(st)][get<1>(st)] = 1;
    dbg(g);
    while(!q.empty()) {
        iii a = q.front(); q.pop();
        dbg(q);
        dbg(a);
        int r, c, d;
        tie(r,c,d) = a;

        int nr, nc, nr0, nc0, d0, nr1, nc1, d1;
        nr = nc = nr0 = nc0 = nr1 = nc1 = d1 = -1;
        if (g[r][c] == '|') {
            if (d == 2 || d == 3) {
                nr = r + dx[d], nc = c + dy[d];
            } else {
                nr0 = r + dx[2], nc0 = c + dy[2], d0 = 2;
                nr1 = r + dx[3], nc1 = c + dy[3], d1 = 3;
            }
        } else if (g[r][c] == '-'){
            if (d == 0 || d == 1) {
                nr = r + dx[d], nc = c + dy[d];
            } else {
                nr0 = r + dx[0], nc0 = c + dy[0], d0 = 0;
                nr1 = r + dx[1], nc1 = c + dy[1], d1 = 1;
            }
        } else if (g[r][c] == '/') {
            if (d == 0) d = 3;
            else if (d == 1) d = 2;
            else if (d == 2) d = 1;
            else if (d == 3) d = 0;
            nr = r + dx[d], nc = c + dy[d];
        } else if (g[r][c] == '\\') {
            if (d == 0) d = 2;
            else if (d == 1) d = 3;
            else if (d == 2) d = 0;
            else if (d == 3) d = 1;
            nr = r + dx[d], nc = c + dy[d];
        } else if (g[r][c] == '.') {
            nr = r + dx[d], nc = c + dy[d];
        }

        if (correct(nr, nc, sz(g), sz(g[0])) && vis.count(mt(nr, nc, d)) == 0) {
            vis.insert(mt(nr, nc, d));
            aux[nr][nc] = 1;
            q.push(mt(nr, nc, d));
        }

        if (correct(nr0, nc0, sz(g), sz(g[0])) && vis.count(mt(nr0, nc0, d0)) == 0) {
            vis.insert(mt(nr0, nc0, d0));
            aux[nr0][nc0] = 1;
            q.push(mt(nr0, nc0, d0));
        }

        if (correct(nr1, nc1, sz(g), sz(g[0])) && vis.count(mt(nr1, nc1, d1)) == 0) {
            vis.insert(mt(nr1, nc1, d1));
            aux[nr1][nc1] = 1;
            q.push(mt(nr1, nc1, d1));
        }
    }

    ll ans = 0;
    for(auto x : aux) {
        for (auto y : x) {
            ans += y;
        }
    }
    
    return ans;
}

signed main() {
    fastIO(); 
    string line;
    while(cin >> line) {
        g.pb(line);
    }
    
    ll ans = -1;

    forn(i, sz(g)) {
        ans = max(ans, f(mt(i, 0, 0)));
    }

    forn(i, sz(g)) {
        ans = max(ans, f(mt(i, sz(g[0])-1, 1)));
    }

    forn(i, sz(g[0])) {
        ans = max(ans, f(mt(0, i, 2)));
    }

    forn(i, sz(g[0])) {
        ans = max(ans, f(mt(sz(g)-1, i, 3)));
    }

    cout << ans << endl;
    

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

