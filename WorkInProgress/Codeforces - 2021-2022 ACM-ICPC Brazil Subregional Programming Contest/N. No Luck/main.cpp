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

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
    return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " + to_string(get<2>(t)) + ")";
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
const int MAXN = 100005;

int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<iii> ps;
vector<int> y;
ll t[MAXN];
// vector<ll> t;

inline int lsb(int x) {
    return (-x)&x;
}

inline void update(int x, int v) {
    while(x < MAXN) {
        t[x] += v;
        x += lsb(x);
    }
}
inline ll query(int x) {
    ll ret = 0;
    while(x) {
        ret += t[x];
        x -= lsb(x);
    }
    return ret;
}

ll ans[MAXN];
vector<int> lidx[MAXN], ridx[MAXN];

int main() {
    fastIO(); 
    cin >> n >> m; 
    // t.assign(MAXN, 0);
    ps.assign(m, iii());
    y.assign(n, 0);
    forn(i, n){
        cin >> y[i];
        update(y[i], 1);
        dbg(query(y[i]));
    }
    int a,b,c;
    forn(i, m) {
        cin >> a >> b >> c;
        ps[i] = tie(a,b,c);
    }

    // forn(i, MAXN) {
    //     lidx[i].clear();
    //     ridx[i].clear();
    // }
    forn(i,m) {
        int l,r,p;
        l = get<0>(ps[i]);
        r = l + get<2>(ps[i]);
        p = get<1>(ps[i]);
        if (y[l-1] >= p) continue;
        ans[i] = 0;
        lidx[l].pb(i);
        ridx[r].pb(i);
        dbg(lidx[l], l);
        dbg(ridx[r], r);
    }
    ll aux = n;
    nfor(i,n) {
        int cur = y[i];
        dbg(cur);
        int nn = ridx[i+1].size();
        int mm = lidx[i+1].size();
        forn(j, nn) {
            int idx = ridx[i+1][j];
            int p = get<1>(ps[idx]);
            ll q = aux - query(p-1);
            dbg(p, q);
            ans[idx] += q;
        }
        forn(j, mm) {
            int idx = lidx[i+1][j];
            int p = get<1>(ps[idx]);
            ll q = aux - query(p-1);
            dbg(p,q);
            ans[idx] -= q;
        }
        update(y[i], -1);
        aux--;
    } 
    forn(i, m) {
        cout << ans[i] << endl;
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