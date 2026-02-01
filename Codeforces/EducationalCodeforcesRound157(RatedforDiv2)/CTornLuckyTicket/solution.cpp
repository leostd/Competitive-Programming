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
 
signed main() {
    fastIO(); 
    cin >> n;
    map<int, map<int, int>> a;
    string s;
    vector<int> aux, aux2;
    vector<vector<int>> b;
    forn(i, n) {
        cin >> s;
        int sum = 0;
        int len = sz(s);
        vector<int> y;
        for(auto x : s) {
            y.pb(x-'0'); 
            sum += x - '0';
        }
        aux.pb(sum);
        aux2.pb(len);
        dbg(s, sum, len, len%2);
        a[sum][len]++;
        b.pb(y);
    }
    
    ll ans = 0;
    dbg(b);
    for(auto x : a) {
        dbg(x.fst);

        dbg(x.snd);
    }
    forn(i, n) {
        int sum = aux[i];
        int len = aux2[i];
        dbg(sum, len%2, a[sum][len%2]);
        ans += a[sum][len];
        if (len == 5) {
            dbg("here");
            // check len 3
            int last4 = sum - b[i][0];
            int first4 = sum - b[i][4];
            // Colocamos a la izquierda uno de 3
            int targetL = last4 - b[i][0]; 
            ans += a[targetL][3];
            
            // Colocamos a la derecha uno de 3
            int targetR = first4 - b[i][4];
            ans += a[targetR][3];
            dbg(targetL, targetR);

            // check len 1
            int last3 = last4 - b[i][1];
            int first3 = first4 - b[i][3];

            targetL = last3 - b[i][0] - b[i][1];
            ans += a[targetL][1];

            targetR = first3 - b[i][4] - b[i][3];
            ans += a[targetR][1];
        }
        else if (len == 4) {
            // check len 2
            int last3 = sum - b[i][0];
            int first3 = sum - b[i][3];
            int targetL = last3 - b[i][0];
            int targetR = first3 - b[i][3];
            ans += a[targetL][2];
            ans += a[targetR][2];
        }
        else if (len == 3) {
            // check len 1
            int last2 = sum - b[i][0];
            int first2 = sum - b[i][2];
            int targetL = last2 - b[i][0];
            int targetR = first2 - b[i][2];
            ans += a[targetL][1];
            ans += a[targetR][1];
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

