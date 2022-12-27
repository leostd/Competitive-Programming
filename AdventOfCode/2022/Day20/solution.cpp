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
const ll DECRYPTION_KEY = 811589153;
const int MIX_TIMES = 10;
vector<vector<int>> g; //graph, grid
vector<int> aux;

// _, 1, _, 2, _, -3, _, 3, _, -2, _, 0, _, 4
// 1, 2, -3, 3, -2, 0, 4
// 2, 1, -3, 3, -2, 0, 4
// 1, -3, 2, 3, -2, 0, 4
// -3, 1, 2, 3, -2, 0, 4
// 

int wrap(int x, int idx) {
    if (x == 0) return 0;
    if (x + idx >= n-1) return 1;
    if (x + idx <= 0) return -1;
    return 0;
}

void move(int idx, vector<pll> &aa) {
    forn(i, n) {
        if (aa[i].snd == idx) {
            idx = i;
            break;
        }
    }
    ll x = aa[idx].fst;
    dbg(idx, x);
    int nidx = ((idx%(n-1)) + (x%(n-1)) + n-1) % (n-1);

    while(idx != nidx) {
        if (idx > nidx) swap(aa[idx], aa[idx-1]), idx--;
        else swap(aa[idx], aa[idx+1]), idx++;
        // dbg(aa);
    }
}

void mix(vector<pll> &a) {
    forn(i, n) move(i, a);
}

void solve1() {
    vector<pll> a;
    int x;
    int ii = 0;
    while(cin >> x) {a.pb(mp(x, ii++));}
    n = a.size();
    dbg(n);
    dbg(a);
    forn(i, n) move(i, a);
    int idx;
    forn(i, (int)a.size()) {
        if (a[i].fst == 0) {
            idx = i;
            break;
        }
    }
    int rest = n - idx;
    int i0 = (1000-rest+n)%n;
    int i1 = (2000-rest+n)%n;
    int i2 = (3000-rest+n)%n;
    ll ans = a[i0].fst + a[i1].fst + a[i2].fst;
    cout << ans << endl;
}


void solve2() {
    vector<pll> a;
    int x;
    int ii = 0;
    while(cin >> x) {a.pb(mp(x*DECRYPTION_KEY, ii++));}
    n = a.size();
    dbg(n);
    dbg(a);
    forn(i, MIX_TIMES) {
        mix(a);
    }
    int idx;
    forn(i, (int)a.size()) {
        if (a[i].fst == 0) {
            idx = i;
            break;
        }
    }
    int rest = n - idx;
    int i0 = (1000-rest+n)%n;
    int i1 = (2000-rest+n)%n;
    int i2 = (3000-rest+n)%n;
    ll ans = a[i0].fst + a[i1].fst + a[i2].fst;
    cout << ans << endl;
}
int main() {
    fastIO();
    // solve1();
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

