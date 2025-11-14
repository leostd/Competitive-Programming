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
vector<vector<int>> g; //graph, grid
vector<int> a, b;

ld f(ld x) {
    dbg(x);
    
    ld error = 0;
    for1(i, n+1) {
        ld cur = (ld)i / x;
        if (cur < a[i]) error += abs(a[i] - cur);
        if (cur > b[i]) error += abs(b[i] - cur);
    }
    return error;
}

ld ternary_search(ld l, ld r) {
    double eps = 1e-9;              //set the error limit here
    while (r - l > EPS) {
        dbg(r, l, r-l, r-l > EPS);
        ld m1 = l + (r - l) / 3;
        ld m2 = r - (r - l) / 3;
        ld f1 = f(m1);      //evaluates the function at m1
        ld f2 = f(m2);      //evaluates the function at m2
        if (f1 > f2) l = m1;
        else r = m2;
    }
    if (f(l) != 0 && f(r) != 0) return -1;
    return (f(l) < EPS ? l : r);
}



void solve() {
    cin >> n;
    //vector<int> a(n), b(n);
    a.assign(n, 0);
    b.assign(n, 0);
    forn(i, n) cin >> a[i] >> b[i];
    dbg(a);
    dbg(b);
    //ld l = 0, r = 1e9, mid;
    //forn(ig, 100) {
    //    mid = (r+l) / 2.0;
    //    int guess = f(mid, a, b);
    //    if (guess == -1) 
    //        r = mid-1;
    //    else if (guess == -2)
    //         l = mid+1;


    //}

    //if (!f(l, a, b) && !f(r, a, b)) {
    //    cout << -1 << endl;
    //    return;
    //}

    //ld ans = (f(l, a, b) ? l : r);
    //ld ans = ternary_search(0,INF);
    ld l, r;
    if (a[0] == 0) r = INF;
    else r = 1.0/a[0];
    if (b[0] == 0) l = INF;
    else l = 1.0/b[0];
    dbg(l, r);
    for1(i, n) {
        ld nl, nr;
        if (a[i] > EPS) nr = (ld)(i+1) / (ld)a[i];
        else nr = INF;
        if (b[i] > EPS) nl = (ld)(i+1) / (ld)b[i];
        else nl = INF;
        ld mn = min(r, nr);
        ld mx = max(l, nl);
        dbg(mn, mx);
        dbg(i+1, nl, nr);
        if (mn < mx) {
            cout << -1 << endl;
            return;
        }
        r = mn;
        l = mx;
        dbg(i+1, l, r);
    }
    cout << setprecision(10) << fixed << l << endl;
}
 
signed main() {
    fastIO(); 
    int t = nxt();
    int tc = 1;
    while(t--) {
        cout << "Case #" << tc++ << ": ";
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

    Checklist:
    - I/O make sense?   - Exclusion/inclusion           - Is a known sequence?
    - Reverse           - Brute force approach          - DP
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/

