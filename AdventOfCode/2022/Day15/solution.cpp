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
const int ROW = 2000000;
const int NROWS = 4000000;
int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<int> cr, cc, rr, br, bc;
vector<pii> sg;

ll dist(ll x0, ll y0, ll x1, ll y1) {
    return abs(x0-x1) + abs(y0-y1);
}



bool intersect(pii a, pii b) {
    ll mx = max(a.fst, b.fst);
    ll mn = min(a.snd, b.snd);

    return mx <= mn;
}

void myunion(pii &a, pii b) {
    a.snd = max(a.snd,b.snd);
}

void getSegments(int idx, ll row) {
    ll h0 = cr[idx] - rr[idx];
    ll h1 = cr[idx] + rr[idx];
    ll w0 = cc[idx] - rr[idx];
    ll w1 = cc[idx] + rr[idx];
    if (row < h0 || row > h1) return; 

    bool flag = br[idx] == row;
    ll diff = abs(row-cr[idx]);
    ll l = w0 + diff;
    ll right = w1 - diff;

    //if (l == bc[idx]) l++;
    //else if (right == bc[idx]) right--;
    if (l <= right)
    sg.pb(mp(l,right));
}

vector<pii> getUnion() {
    //dbg(sg);
    vector<pii> un;
    un.pb(sg[0]);
    int cur = 0;
    for1(i, (int)sg.size()) {

        if (intersect(un[cur], sg[i])) myunion(un[cur], sg[i]);
        else {
                un.pb(sg[i]);
                cur++;
            }
    }
    //dbg(un);

    return un;
}

ll solve(ll row) {
    //dbg(row);
    ll ret = 0;
    sg.clear();
    forn(i, (int)cr.size()) {
        getSegments(i, row);
    }

    sort(all(sg));
    vector<pii> aux = getUnion();
    //for(auto x : aux) ret += x.snd - x.fst + 1;
    if (aux.size() > 1 && aux[1].fst > aux[0].snd+1) {
        ll ans = row + 4000000LL * ((ll)aux[0].snd+1);
        cout << "Tunning frequency: " << ans << endl;
    }
    return ret;
}
 
int main() {
    //fastIO(); 
    ll r,c,radiusr,radiusc;
    while(scanf("Sensor at x=%lld, y=%lld: closest beacon is at x=%lld, y=%lld\n", &c, &r, &radiusc, &radiusr) != EOF) {
        cr.pb(r);
        cc.pb(c);
        br.pb(radiusr);
        bc.pb(radiusc);
        rr.pb(dist(r, c, radiusr, radiusc));
    }

    dbg(cr);
    dbg(cc);
    dbg(br);
    dbg(bc);
    dbg(rr);
   
    //ll ans = solve(ROW);
    forn(i, NROWS+1) {
        solve(i);
    }
    //cout << ans << endl;
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

