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

int f(int cur, int x) {
    return cur + (x > cur) - (x < cur);
}

void solve3() {
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    vector<int> dp(3, -1);
    dp[0] = 0;
    forn(i, n) {
        dp[2] = max(f(dp[2], a[i]), f(dp[1], a[i]));
        dp[1] = max(dp[1], dp[0]);
        dp[0] = f(dp[0], a[i]);
    }

    cout << max({dp[1], dp[2]}) << endl;;
}

void solve2() {
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];

    vector<int> inc(n, 0), bin(n, 0);
    dbg(a);
    bin[0] = 1;
    inc[0] = 1;
    for1(i, n) {
        inc[i] = inc[i-1];
        if (a[i] > inc[i]) inc[i]++, bin[i] = 1;
        else if (a[i] < inc[i]) inc[i]--, bin[i] = -1;
    } 

    dbg(inc);
    dbg(a);

    vector<int> mxl(n), mx(n);
    mx[0] = 1;
    for1(i,n) {
        mx[i] = mx[i-1], mxl[i-1];
        if (inc[i] > mx[i]) mx[i] = inc[i], mxl[i] = i;
    }

    int r = n-1;
    bool flag = 0;
    nfor(i, n) {
        if (bin[i] != 1) {
            r = i;
            flag = 1;
            break;
        }
    }

    if (!flag) {
        cout << mx[n-1] - 1 << endl;
        return;
    }

    dbg(bin);
    int cur = mx[r];
    dbg(mx);

    dbg(cur, r, mx[r]);
    
    fore(i, r+1, n){
        dbg("here", i, r, n);
        if (a[i] > cur) cur++;
        else if (a[i] < cur) cur--;
    }

    cout << cur << endl;

}

void solve() {
    cin >> n;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    vector<int> sa = a;
    sort(all(sa));
    if (sa == a) {
        cout << n-1 << endl;
        return;
    }

    vector<int> inc(n, 0), bin(n, 0);
    dbg(a);
    bin[0] = 1;
    inc[0] = 1;
    for1(i, n) {
        inc[i] = inc[i-1];
        dbg(i, a[i], inc[i]);
        if (a[i] > inc[i]) inc[i]++, bin[i] = 1;
        else if (a[i] < inc[i]) inc[i]--, bin[i] = -1;
        dbg(i, inc[i], 2);
    } 

    dbg(inc);
    dbg(a);

    vector<int> ninc = bin;
    for(auto &x : ninc) x = -x;
    int l=0, r=0, cur=0, sum=0;
    int ans = 0, ans2 = 0;
    dbg(ninc);
    forn(i, n) {
        cur += ninc[i];
        dbg(i, cur);
        if (cur < 0) {
            l = i+1;
            r = i+1;
            sum = 0;
            cur = 0;
            continue;
        }

        if (cur >= sum) {
            r = i;
            sum = cur;
            ans = (l > 0 ? inc[l-1] : 0) + inc[n-1] - inc[r];
            dbg(ans, "prev inc");
            if (l > 0) {
                dbg(inc[l-1], inc[r], inc[n-1]);
            }
            dbg(l-1, a[l-1], i+1, n, n-1, a[i+1]);
            if (l > 0 && i < n-1 && inc[l-1] > a[i+1]) ans--;
            else if (l > 0 && i < n-1 && inc[l-1] < a[i+1]) ans++;
            dbg("here, post inc", ans);
            if (ans > ans2) ans2 = ans;
        }
    }
    dbg(l, r);

    cout << ans2 << endl;

}
 
signed main() {
    fastIO(); 
    int t = nxt();
    while(t--) solve3();
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

