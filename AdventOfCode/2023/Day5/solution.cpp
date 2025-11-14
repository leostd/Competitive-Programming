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
const int NMAPS = 7;
int n, m; // sizes
vector<vector<int>> g; //graph, grid
vector<pll> seeds;
map<string, vector<pair<pll, pll>>> maps;


pll intersect(pll a, pll b) {
    ll mn = min(a.snd, b.snd);
    ll mx = max(a.fst, b.fst);
    dbg(mn >= mx, mp(mx, mn) == a);
    if (mn >= mx) return mp(mx, mn);
    return mp(-1, -1);
}

pll remap(pll a, pll b, pll c) {
    ll diff = a.fst - b.fst;
    ll len = a.snd - a.fst;
    return mp(c.fst + diff, c.fst+ diff + len);
}

signed main() {
    fastIO(); 
    string line;
    getline(cin, line);
    stringstream sseeds(line);
    string ign;
    ll seed;
    sseeds >> ign;
    ll len;
    while(sseeds >> seed >> len){
        seeds.pb(mp(seed, seed+len));
    } 
    ll dst, src, x;
    string a, b, c;
    cin >> a >> b;

    vector<string> aux;
    string cur = a;
    aux.pb(a);
    while(cin >> a >> b) {
        if (b == "map:") {
            cur = a;
            aux.pb(a);
            continue;
        }

        cin >> c;
        dst = stoll(a), src = stoll(b), x = stoll(c);
        maps[cur].pb(mp(mp(src, src+x), mp(dst, dst+x)));
    }

    forn(i, sz(aux)) {
        cur = aux[i];
        sort(all(maps[cur]));
        vector<pair<pll, pll>> cmap = maps[cur];
        vector<pll> nseeds;
        forn(j, sz(seeds)) {
            pll cseed = seeds[j];
            vector<pll> intersected, rem;
            bool flag = false;
            forn(k, sz(cmap)) {
                pll csrc = cmap[k].fst;
                pll cdst = cmap[k].snd;
                pll intersection = intersect(cseed, csrc);
                if (intersection.fst != -1) {
                    intersected.pb(intersection);
                    pll remp = remap(intersection, csrc, cdst);
                    nseeds.pb(remp);
                }
            }
            sort(all(intersected));
            if (intersected.empty()) {
                nseeds.pb(cseed);
                continue;
            }
            if (sz(intersected) && intersected[0].fst - 1 > cseed.fst) {
                nseeds.pb(mp(cseed.fst, intersected[0].fst-1));
            }

            if (sz(intersected) > 1 && intersected.back().snd+1 < cseed.snd) {
                nseeds.pb(mp(intersected.back().snd+1, cseed.snd));
            }

            for1(k, sz(intersected)) {
                if (intersected[k-1].snd + 1 < intersected[k].fst) {
                    nseeds.pb(mp(intersected[k-1].snd+1, intersected[k].fst-1));
                }
            }
        }
        dbg(seeds);
        dbg(nseeds);
        seeds = nseeds;
    }

    ll ans = INF64;
    sort(all(seeds));

    ans = seeds[0].fst;
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

