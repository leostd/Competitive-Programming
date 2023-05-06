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
 
const int MOD = 998244353;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
 
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<vector<int>> g; //graph, grid


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

ll factorial(ll x) {
    ll ret = 1;
    for1(i, x+1) ret = mult(ret, i);
    return ret;
}

vector<vector<ll>> pascal(int l) {
    vector<vector<ll>> ret(l+1, vector<ll>(l+1, 0));
    ret[1][1] = 1;
    fore(i, 2, l+1) {
        for1(j, i) {
            if (j == 1 || j == i) ret[i][j] = 1;
            else ret[i][j] = sum(ret[i-1][j], ret[i-1][j-1]);
        }
    }
    return ret;
}




vector<ll> fact((int)1e6+5);
vector<ll> factinv((int)1e6+5);
vector<int> isPrime(MAXN, 1);
vector<int> primes;
map<int, ll> fq;
vector<vector<ll>> memo;

void sieve() {
    isPrime[1] = 0;
    fore(p, 2, MAXN) {
        if (isPrime[p]) {
            for(int px = (p << 1); px < MAXN; px+= p) isPrime[px] = false;
        }
    }
}

ll dp(int i, int rem) {
    if (i == (int)primes.size()) return rem == 0;
    
    ll &ret = memo[i][rem];

    if (ret != -1) return memo[i][rem];

    int frq = fq[primes[i]];
    ll a = mult(factinv[frq], dp(i+1, rem));
    ll b = 0;
    if (rem > 0)
        b = mult(factinv[frq-1], dp(i+1, rem-1));

    return ret = sum(a, b);
}


signed main() {
    fastIO(); 
    
    dbg(pow(12, 2));
    sieve();
    fact[1] = fact[0] = 1;
    fore(i, 2, MAXN) fact[i] = mult(fact[i-1], i);
    factinv[0] = 1;

    for1(i, MAXN) factinv[i] = inv(fact[i]);

    cin >> n;
    vector<ll> a(2*n);

    forn(i, 2*n) cin >> a[i], fq[a[i]]++;

    dbg(a);
    int dprime = 0;
    for(auto x : fq) {
        if (isPrime[x.fst]) dprime++, primes.pb(x.fst);
    }

    dbg(primes);
    if (dprime < n) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = fact[n];
    for(auto x : fq) {
        if (!isPrime[x.fst]) ans = mult(ans, factinv[x.snd]);
    }

    memo.assign(2*n+1, vector<ll>(n+1, -1));
    ll sum = dp(0, n);
    dbg(ans);
    dbg(sum);

    ans = mult(ans, sum);


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

