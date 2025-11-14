#include <algorithm>
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
vector<vector<int>> a;

void init() {
    cin >> n >> m;
    a.assign(n+m+1, vector<int>(2));
    forn(i, n+m+1) cin >> a[i][0];
    forn(i, n+m+1) cin >> a[i][1];
}

vector<int> bruteForce() {
    vector<int> ret;
    forn(i, n+m+1) {
        int nn = n, mm = m;
        int ans = 0;

        forn(j, n+m+1) {
            if (j == i) continue;
            if (a[j][0] > a[j][1] && nn) {
                nn--;
                ans += a[j][0];
            } else if (a[j][1] > a[j][0] && mm) {
                mm--;
                ans += a[j][1];
            } else if (nn == 0) {
                mm--;
                ans += a[j][1];
            } else if (mm == 0) {
                nn--;
                ans += a[j][0];
            } 
        }
        ret.pb(ans);
    }
    return ret;
}

vector<int> solve2() {
    // 0 prog - 1 tester
    vector<int> ans(n+m+1);
    int nn = n, mm = m;
    vector<int> forcedTester, forcedProg;
    int idx = INF;
    forn(i, n+m) {
        if (a[i][0] > a[i][1]) {
            dbg("here prog", nn);
            if (nn > 0) {
                nn--;
                if (nn == 0) {
                    dbg("run out of prog positions");
                    idx = i;
                }
                ans[i] = 0;
            } else {
                forcedTester.pb(i);
                ans[i] = 1;
            }
        } else {
            if (mm > 0) {
                mm--;
                if (mm == 0) {
                    dbg("run out of tester positions");
                    idx = -i;
                }
                ans[i] = 1;
            } else {
                forcedProg.pb(i);
                ans[i] = 0;
            }
        }
    }
 
    dbg(forcedProg);
    dbg(forcedTester);
    ll sum = 0;
    int flag = -1; // 1 = forcedProg, 0 = forcedTester
    forn(i, n+m) {
        sum += a[i][ans[i]]; 
    }
    vector<int> aans;
 
    dbg("initial sum", sum);
    dbg("idx", idx);
 
    int aux=-1;
    
    if (idx < 0 && !forcedProg.empty()) {
        aux = forcedProg[0];
        flag = 1;
    } else if (idx >= 0 && !forcedTester.empty()){
        aux = forcedTester[0];
        flag = 0;
    } 
    
    dbg(aux, flag);
 
    idx = abs(idx);
    ll curSum;
    forn(i, n+m) {
        curSum = sum - a[i][ans[i]];
        if (i <= idx) {
            if (flag == 1 && ans[i] == 1) {
                curSum = curSum - a[aux][0] + a[aux][1];
                curSum += a[n+m][0];
            } else if (flag == 0 && ans[i] == 0) {
                curSum = curSum - a[aux][1] + a[aux][0];
                curSum += a[n+m][1];
            } else {
                curSum += a[n+m][ans[i]];
            } 
        } else {
            curSum += a[n+m][ans[i]];
        }
        aans.pb(curSum);
    }
    aans.pb(sum);
    for (auto x : aans) {
        cout << x << " ";
    }
    cout << endl;
    return aans;
    
}
 
signed main() {
    fastIO(); 
    int t = nxt();
    while(t--) {
        init();
        vector<int> correct = bruteForce();
        vector<int> maybe = solve2();

        dbg(n, m);
        dbg(a);
        dbg(correct);
        dbg(maybe);
        assert(correct == maybe);
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

