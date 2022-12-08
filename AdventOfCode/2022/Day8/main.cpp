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

// template<typename A>
// string to_string(vector<A> v);

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

vector<string> sg;
vector<vector<int>> g;
vector<vector<int>> maxPrefixLR, maxPrefixTD, maxSuffixRL, maxSuffixBU;

void parseGrid() {
    string ln;
    while(cin >> ln) {
        sg.pb(ln);
    }
    dbg(sg);
    n = sg.size();
    m = sg[0].size();
    g.assign(n, vector<int>(m, 0));
    forn(i, n) forn(j, m) g[i][j] = sg[i][j] - '0';
    dbg(g);
}

void preCompute() {
    maxPrefixLR.assign(n, vector<int>(m+1, 0));
    maxPrefixTD.assign(m+1, vector<int>(n+1, 0));
    maxSuffixRL.assign(n, vector<int>(m+1, 0));
    maxSuffixBU.assign(m+1, vector<int>(n+1, 0));
    forn(i, n) {
        for1(j, m+1) maxPrefixLR[i][j] = max(maxPrefixLR[i][j-1], g[i][j-1]);
        nfor(j, m) maxSuffixRL[i][j] = max(maxSuffixRL[i][j+1], g[i][j]);
    }

    forn(i, m) {
        for1(j, n+1) maxPrefixTD[j][i] = max(maxPrefixTD[j-1][i], g[j-1][i]);
        nfor(j, n) maxSuffixBU[j][i] = max(maxSuffixBU[j+1][i], g[j][i]);
    }
    dbg(maxPrefixLR);
    dbg(maxSuffixRL);
    // dbg(maxPrefixTD);
    // dbg(maxSuffixBU);
    forn(i, n+1) {
        forn(j, m+1) {
            cout << maxPrefixTD[i][j] << " ";
        }
        cout << endl;
    }
cout << "----------" << endl;
    forn(i, n+1) {
        forn(j, m+1) {
            cout << maxSuffixBU[i][j] << " ";
        }
        cout << endl;
    }
}

ll countVisible() {
    ll ret = 2*n + 2*m - 4; // borders
    dbg("borders", ret);
    dbg(g[2][3], maxSuffixRL[2][3]);
    for1(i, n-1) {
        for1(j, m-1) {
            int h = g[i][j];
            if (h > maxPrefixLR[i][j] || h > maxSuffixRL[i][j+1] || h > maxPrefixTD[i][j] || h > maxSuffixBU[i+1][j]) {
                ret++;
                dbg(i+1, j+1);
            }
        }
    }
    dbg(ret);
    return ret;
}

ll score(int r, int c) {
    if (r == 0 || c == 0 || r == n-1 || c == m-1) return 0;
    dbg(r, c);
    ll l, rr, u, d;
    l = rr = u = d = 0;
    bool lflag, rflag, uflag, dflag;
    for(int i = c-1; i >= 0 && g[r][c] > g[r][i]; i--) {l++, lflag = !(i == 0);}
    for(int i = c+1; i < m && g[r][c] > g[r][i]; i++) {rr++, rflag = !(i == m-1);}
    for(int i = r-1; i >= 0 && g[r][c] > g[i][c]; i--) {u++, uflag = !(i == 0);}
    for(int i = r+1; i < n && g[r][c] > g[i][c]; i++) {d++, dflag = !(i == n-1);}
    l += lflag, rr += rflag, u += uflag, d += dflag;
    dbg(l, rr, u, d);
    return l * rr * u * d;
}


int main() {
    fastIO();
    parseGrid();
    // preCompute();
    // ll ans = countVisible();
    ll ans = 0;
    forn(i, n) {
        forn(j, m) {
            ans = max(ans, score(i, j));
        }
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

