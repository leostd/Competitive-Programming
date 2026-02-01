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
const ld E = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
const string abc = "abcdefghijklmnopqrstuvwxyz";
//#############################
const int MAXN = 1000005;

int n, M; // sizes
vector<vector<ll>> g; //graph, grid
 

// [L , R) Segment tree
#define NEUTRAL INF64
#define oper min
struct segTree {
    int n;
    vector<ll> t;
    segTree(int _n) {
        n = _n;
        t.assign(4*n+5, NEUTRAL);
    }

    void _upd(int cur, int s, int e, int idx, ll val) {
        //dbg(cur, s, e, idx, val);
        if (s+1 == e){t[cur] = val; return;}
        int mid = (s + e) / 2;
        if (idx < mid) _upd(2*cur, s, mid, idx, val);
        else _upd(2*cur+1, mid, e, idx, val);
        t[cur] = oper(t[2*cur], t[2*cur+1]);
        //dbg(t);
    }
    

    ll _query(int cur, int s, int e, int l, int r) {
        dbg(cur, s, e, l, r);
        if (s >= r || e <= l) return NEUTRAL;
        if (s >= l && e <= r) return t[cur];
        int mid = (s + e) / 2;
        return oper(_query(2*cur, s, mid, l, r), _query(2*cur+1, mid, e, l, r));
    }
    void upd(int idx, ll val){_upd(1, 0, this->n, idx, val);}
    ll query(int l, int r){return _query(1, 0, this->n, l, r);}
};


#define oper min
#define NEUT 1e18
struct STree { // segment tree for min over integers
	vector<ll> st;int n;
	STree(int n): st(4*n+5,NEUT), n(n) {}
	void upd(int k, int s, int e, int p, ll v){
		if(s+1==e){st[k]=v;return;}
		int m=(s+e)/2;
		if(p<m)upd(2*k,s,m,p,v);
		else upd(2*k+1,m,e,p,v);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	ll query(int k, int s, int e, int a, int b){
		if(s>=b||e<=a)return NEUT;
		if(s>=a&&e<=b)return st[k];
		int m=(s+e)/2;
		return oper(query(2*k,s,m,a,b),query(2*k+1,m,e,a,b));
	}
	void upd(int p, ll v){upd(1,0,n,p,v);}
	ll query(int a, int b){return query(1,0,n,a,b);}
}; // usage: STree rmq(n);rmq.init(x);rmq.upd(i,v);rmq.query(s,e);


ll get(vector<ll> &v, int d) {
    segTree st(sz(v));
    dbg("get");
    st.upd(0, 1);
    dbg("after first upd");
    for1(i, sz(v)) {
        // considerar el actual (i-esimo) y el minimo anterior, que este maximo a distancia d 
        ll cur = st.query(max(i-d-1, 0), i);
        // actualizar la posicion actual con el resultado +1
        st.upd(i, cur+v[i]+1);
    }
    dbg("querying result");
    return st.query(sz(v)-1, sz(v));
}

void solve() {
    int k, d;
    cin >> n >> M >> k >> d;
    g.assign(n, vector<ll>(M, 0));

    forn(i, n) forn(j, M) cin >> g[i][j];
    dbg(g);
    vector<ll> ans(n);
    forn(i, n) ans[i] = get(g[i], d);
    for1(i, n) ans[i] += ans[i-1];

    ll r=1e18;
    fore(i, 0, n) if (i+k-1 < n) r = min(r, ans[i+k-1] - (i ? ans[i-1] : 0));
    cout << r << endl;

}
signed main() {
    fastIO(); 
    int t= nxt();
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

