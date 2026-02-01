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
                       //

ll shoelace(vector<pll> points) {
    ll ret = 0;
    for1(i, sz(points)) {
        ll x0 = points[i-1].fst;
        ll x1 = points[i].fst;
        ll y0 = points[i-1].snd;
        ll y1 = points[i].snd;
        ret += (x0*y1 - x1*y0);
    }
    return ret / 2;
}

ll hexToDec(string hex) {
    dbg(hex);
    ll ret = 0;
    ll pw = 1;
    reverse(all(hex));
    for(auto x : hex) {
        ll val;
        if (x == 'a') val = 10;
        else if (x == 'b') val = 11;
        else if (x == 'c') val = 12;
        else if (x == 'd') val = 13;
        else if (x == 'e') val = 14;
        else if (x == 'f') val = 15;
        else val = x - '0';

        dbg(val, pw);
        ret += val * pw;
        pw *= 16;
    }

    dbg(ret);
    return ret;
}

void solve2() {
    string a, c;
    int b;
    vector<pll> points;
    pll cur = mp(0, 0);
    ll ans = 0;
    while(cin >> a >> b >> c) {
        pll np = cur;
        string digits = c.substr(2, string::npos);
        digits.pop_back();
        dbg(digits);
        char op = digits.back();
        digits.pop_back();
        ll y = hexToDec(digits);
        if (op == '1') np.fst += y;
        if (op == '0') np.snd += y;
        if (op == '3') np.fst -= y;
        if (op == '2') np.snd -= y;
        points.pb(np);
        cur = np;
        ans += y;
    }
    ans /= 2LL;

    ans += abs(shoelace(points));

    cout << ans + 1 << endl;
}


void solve1() {
    string a, c;
    int b;
    vector<pll> points;
    pii cur = mp(0,0);
    points.pb(cur);
    ll ans = 0;
    vector<string> gs(40, string(40, '.'));
    while(cin >> a >> b >> c) {
        pii np = cur;
        if (a[0] == 'U') np.fst -= b;
        if (a[0] == 'R') np.snd += b;
        if (a[0] == 'D') np.fst += b;
        if (a[0] == 'L') np.snd -= b;
        points.pb(np);
        cur = np;
        ans += b;
    }
    ans /= 2;
    ans += abs(shoelace(points));
    cout << ans + 1 << endl;
}
 
signed main() {
    fastIO(); 
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

