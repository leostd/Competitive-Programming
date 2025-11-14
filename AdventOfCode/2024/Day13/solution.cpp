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

void parseInput(pll &a, pll &b, pll &prize) {
    string s;
    forn(i, 2) cin >> s;
    s.pop_back();
    string sstr = s.substr(2, string::npos);
    dbg(sstr);
    a.fst = stoll(sstr);
    cin >> s;
    sstr = s.substr(2, string::npos);
    a.snd = stoll(sstr);
    forn(i, 3) cin >> s;
    s.pop_back();
    sstr = s.substr(2, string::npos);
    b.fst = stoll(sstr);
    cin >> s;
    sstr = s.substr(2, string::npos); 
    b.snd = stoll(sstr);
    forn(i, 2) cin >> s;
    s.pop_back();
    sstr = s.substr(2, string::npos);
    prize.fst = stoll(sstr);
    cin >> s;
    sstr = s.substr(2, string::npos); prize.snd = stoll(sstr);
    dbg(a, b, prize);
}

void solve2() {
    string s;
    ll ans = 0;
    while(cin >> s) {
        ll costA = 3, costB = 1;
        pll a, b, prize;
        parseInput(a, b, prize);
        ll cur = INF;

        ll curx, cury;
        // a*c0 + b*c1 = x
        // a*c2 + b*c3 = y
        // a*c0*c3 + b*c1*c3 = x*c3
        // a*c2*c1 + b*c1*c3 = y*c1
        // a*(c0*c3 - c2*c1) = x*c3-y*c1
        // a = (x*c3+y*c1) / (c0*c3 - c2*c1)
        // b = (x - a*c0) / c1
        
        ll c0 = a.fst, c1 = b.fst, c2 = a.snd, c3 = b.snd, x = prize.fst+10000000000000LL, y = prize.snd+10000000000000LL;
        dbg(c0, c1, c2, c3, x, y);
        ll num = (x*c3-y*c1);
        ll denom = c0*c3 - c2*c1;
        dbg(num, denom);
        ll aa = num / denom;
        if (num % denom || aa < 0) continue;

        num = x-aa*c0;
        denom = c1;
        ll bb = num / denom;
        if (num % denom || bb < 0) continue;
        ans += costA*aa + costB*bb;
    }
    cout << ans << endl;
}

void solve1() {
    string s;
    ll ans = 0;
    while(cin >> s) {
        ll costA = 3, costB = 1;
        pll a, b, prize;
        parseInput(a, b, prize);
        ll cur = INF;

        ll curx, cury;
        forn(x, 1000) {
            curx = x*a.fst, cury = x * a.snd;
            if (curx > prize.fst || cury > prize.snd) break;
            dbg(x, curx, cury);
            forn(y, 1000) {
                if ((curx + y*b.fst) == prize.fst && (cury+y*b.snd) == prize.snd) {
                    cur = min(cur, costA*x + costB*y);
                } else if (curx+y*b.fst > prize.fst || cury+y*b.snd > prize.snd) break;
            }
        }
        ans += (cur == INF ? 0 : cur);
    }
    cout << ans << endl;
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

