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
int k;
int memo[MAXN];

vector<int> primes;
int isPrime[MAXN], spf[MAXN];
vector<int> primeIdx;
void sieve(int maxn = MAXN) {
   memset(isPrime, 1, sizeof(isPrime));
   isPrime[1] = false;
   for1(i, maxn) spf[i] = i;
   // Check if make sense to iterate until sqrt(maxn)
   for(int p = 2; p < maxn; p++) {
       if (isPrime[p]) {
           primes.pb(p);
           spf[p] = p;
           for(int px = p+p; px < maxn; px += p) {
               spf[px] = min(spf[px], p);
               isPrime[px] = 0;
           }
       }
   }
}

map<int, int> factorize(int x) {
    map<int, int> ret;
    
    while(x > 1) {
        ret[spf[x]]++;
        x /= spf[x];
    }

    return ret;
}

int intPow(int a, int b) {
    int ret = 1;
    int y = a;
    while(b) {
        if (b&1) ret *= y;
        y *= y;
        b >>= 1;
    }
    return ret;
}


int dp(int x) {
    dbg(x);
    if (x == 1) return 0;
    int &ret = memo[x];
    if (ret != -1) return ret;

    memo[x] = INF;
    for(int y = 1; y*y <= x && y <= k; y++) {
        if (x % y == 0) {
            memo[x] = min(memo[x], dp(x/y) + 1);

            if (x/y != y && x/y <= k) {
                memo[x] = min(memo[x], dp(y) + 1);
            }
        }
    }

    return memo[x];
}

void solve() {
    int x, y;
    cin >> x >> y >> k;

    map<int, int> fx = factorize(x), fy = factorize(y);
    int toDiv = 1, toMul = 1;
    for(auto f : fx) {
        if (fy.count(f.fst)) {
            int diff = fy[f.fst] - fx[f.fst]; 
            if (diff < 0) toDiv *= intPow(f.fst, abs(diff));
            else toMul *= intPow(f.fst, diff);
        } else {
            toDiv *= intPow(f.fst, f.snd);
            if (f.fst > k) {
                cout << -1 << endl;
                return;
            }

        }

        
    }

    dbg(fx);
    dbg(fy);
    for(auto f : fy) {
        if (!fx.count(f.fst)) {
            toMul *= intPow(f.fst, f.snd);
            if (f.fst > k) {
                cout << -1 << endl;
                return;
            }
        }

        
    }

    dbg(toDiv, toMul);
    
    memset(memo, -1, sizeof(memo));
    int dp1 = dp(toDiv);
    int dp2 = dp(toMul);
    dbg(dp1, dp2);

    if (dp1 == -1 || dp2 == -1 || dp1 >= INF || dp2 >= INF) {
        cout << -1 << endl;
        return;
    }

    cout << dp1 + dp2 << endl;
    
}
 
signed main() {
    fastIO(); 
    sieve();
    int t = nxt();
    while(t--) solve();
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

