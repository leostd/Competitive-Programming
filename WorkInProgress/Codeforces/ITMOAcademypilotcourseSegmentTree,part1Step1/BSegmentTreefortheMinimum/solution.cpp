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


struct segtree{
    int size;
    vector<long long> sums, mins;
 
    void init(int n) {
        size = 1;
        while(size < n)
            size *= 2;
        sums.assign(2*size, 0LL);
        mins.assign(2*size, 0LL);
    }
 
   // void set(int i, long long v, int x, int lx, int rx){
   //     if (rx - lx == 1) {
   //         sums[x] = v;
   //         return;
   //     }
 
   //     int mid = (lx + rx) / 2;
   //     if (i < mid) {
   //         set(i, v, 2*x+1, lx, mid);
   //     } else {
   //         set(i, v, 2*x+2, mid, rx);
   //     }
   //     sums[x] = sums[2*x+1] + sums[2*x+2];
   // }
   //

    void set(int i, ll v, int x, int lx, int rx) {
        if (rx - lx == 1) {
            mins[x] = v;
            sums[x] = 1;
            return;
        }

        int mid = (lx + rx) / 2;
        if (i < mid)
            set(i, v, 2*x+1, lx, mid);
        else
            set(i, v, 2*x+2, mid, rx);
        int lft = 2*x+1;
        int rgt = 2*x+2;
        if (mins[lft] < mins[rgt]) mins[x] = mins[lft], sums[x] = sums[lft];
        else if (mins[rgt] < mins[lft]) mins[x] = mins[rgt], sums[x] = sums[rgt];
        else mins[x] = mins[lft], sums[x] = sums[lft] + sums[rgt];

    }
 
    void set(int i, long long v) {
        dbg(i, v);
        set(i, v, 0, 0, size);
    }
 
    long long sum(int l, int r, int x, int lx, int rx) {
        if (lx >= r || l >= rx) return 0;
        if (lx >= l && rx <= r) return sums[x];
        int mid = (lx + rx) / 2;
        long long s1 = sum(l, r, 2*x+1, lx, mid);
        long long s2 = sum(l, r, 2*x+2, mid, rx);
 
        return s1 + s2;
    }
 
    long long sum(int l, int r) {
        return sum(l, r, 0, 0, size);
    }

    pll getMin(int l, int r, int x, int lx, int rx) {
        dbg(l, r, x, lx, rx);
        if (lx >= r || l >= rx) return mp(INF64, 0);
        if (lx >= l && rx <= r) return mp(mins[x], sums[x]);
        int mid = (lx + rx) / 2;
        pll m1 = getMin(l, r, 2*x+1, lx, mid);
        pll m2 = getMin(l, r, 2*x+2, mid, rx);

       if (m1.fst < m2.fst) return m1;
       else if (m2.fst < m1.fst) return m2;
       else return mp(m1.fst, m1.snd + m2.snd);
    }

    pll getMin(int l, int r) {
        dbg(l, r);
        return getMin(l, r, 0, 0, size);
    }
};
 
signed main() {
    fastIO(); 

    cin >> n >> m;
    dbg(n, m);

    segtree st;
    st.init(n);
    vector<int> a(n);
    int v;
    forn(i, n) {
        cin >> a[i];
        dbg(i, a[i]);
        st.set(i, a[i]);
        dbg(i, a[i]);
    }
    dbg(a);

    int q;
    while(m--) {
        cin >> q;
        int l, r, idx;
        if (q == 1) {
            cin >> idx >> v;
            st.set(idx, v);
        } else {
            cin >> l >> r;
            dbg(l, r);
            pll ans = st.getMin(l, r);
            cout << ans.fst << " " << ans.snd << endl;
        }
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

