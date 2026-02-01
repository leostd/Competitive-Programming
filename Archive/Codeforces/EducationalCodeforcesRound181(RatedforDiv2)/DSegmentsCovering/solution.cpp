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
 
const int MOD = 998244353;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
const string abc = "abcdefghijklmnopqrstuvwxyz";
//#############################
const int MAXN = 200005;

ll n, m; // sizes
vector<ll> acump, acumq, np, nq;
vector<tuple<ll, ll, ll, ll>> aa;

ll sum(ll a, ll b) { return ((a%MOD) + (b%MOD)) % MOD; }   
ll subtract(ll a, ll b) { return ((a%MOD) - (b%MOD) + MOD) % MOD; }
ll mult(ll a, ll b) { return ((a%MOD) * (b%MOD)) % MOD; }
ll mpow(ll a, ll b) {
    ll ret = 1;
    ll y = a;
    while(b) {
        if (b&1) {
            ret = mult(ret, y);
        }

        y = mult(y, y);
        b >>= 1;
    }
    return ret;
}

/* MOD and x should be coprime */
ll inv(ll x) {
    return mpow(x, MOD-2);
}

/*
    VERY IMPORTANT!! DO NOT COMPARE NUMBERS AFTER APPLYING MODULO. COMPARISON OPERATORS (>, <, ETC) DOESN'T WORK
*/

ll memo[MAXN];
map<int, vector<int>> st;
vector<ll> npr, pf;

ll dp(int j) {
    if (j == m+1) return 1;
    if (memo[j] != -1) return memo[j];

    ll base = inv(pf[j-1]);
    ll ans = 0; 
    for(auto i : st[j]) {
        ll l, r, p, q;
        tie(l, r, p, q) = aa[i];
        ll x = mult(base, pf[r]);
        x = mult(x, inv(mult(subtract(q, p), inv(q))));
        x = mult(x, mult(p, inv(q)));
        ll y = dp(r+1);
        ans = sum(ans, mult(x, y));
    }

    return memo[j] = ans;
}

void solve() {
    cin >> n >> m;
    dbg(n, m);
    st.clear();
    aa.assign(n, make_tuple(0, 0, 0, 0));
    
    forn(i, n) {
        ll l, r, p, q;
        cin >> l >> r >> p >> q;
        ll gc = gcd(p, q);
        aa[i] = make_tuple(l,r,p/gc,q/gc);
    }

    fill(memo, memo + (m+2), -1);

    sort(all(aa));
    int idx = 0;
    for(auto [l,r,p,q] : aa) {
        st[l].pb(idx++); 
    }

    // probability of not picking any segment that starts at x
    npr.assign(m+2, 1);
    dbg(npr.size());
    for(auto x : st) {
        for(auto i : x.snd) {
            ll l,r,p,q;
            tie(l,r,p,q) = aa[i];
            dbg(x.fst);
            npr[x.fst] = mult(npr[x.fst], mult(subtract(q, p), inv(q)));  
        }
    }

    // prefix product of the probability. This keeps the probability of not picking any segment 
    // that overlaps with [0, i]
    pf.assign(m+2, 1);
    for1(i, m+1) pf[i] = mult(pf[i], mult(pf[i-1], npr[i]));

    // bottom-up DP
    // dp[j] = probability that the subarray [j..m] 
    // is covered *exactly once* 
    //  given that no segment starts before j is already chosen.

    ll ans = dp(1);

    cout << ans << endl;
}
 
signed main() {
    fastIO(); 
    int t = 1;
    while(t--) {
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

