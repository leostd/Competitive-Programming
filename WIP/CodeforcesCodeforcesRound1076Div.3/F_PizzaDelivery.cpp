// time-limit: 2000
// problem-url: https://codeforces.com/contest/2193/problem/F
#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) ((int)x.size())
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for (int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define lsb(x) ((-x) & (x))
#define fst first
#define snd second
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int, int, int> iii;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ld, ld, ld> ddd;

template <typename T> inline T abs(T a) { return ((a < 0) ? -a : a); }
template <typename T> inline T sqr(T a) { return a * a; }
template <class T> T gcd(T a, T b) { return a ? gcd(b % a, a) : b; }
template <class T> T lcm(T a, T b) { return a / gcd(b % a, a) * b; }
template <class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }

string to_string(string s) { return '"' + s + '"'; }

string to_string(const char *s) { return to_string((string)s); }

string to_string(bool b) { return (b ? "true" : "false"); }

template <typename A, typename B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) {
  return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) + ", " +
         to_string(get<2>(t)) + ")";
}

template <typename A> string to_string(priority_queue<A> pq) {
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

template <typename A> string to_string(queue<A> q) {
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

template <typename A> string to_string(A v) {
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
template <typename Head, typename... Tail> void dbg(Head H, Tail... T) {
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

template <typename T> vector<T> make_unique(vector<T> v) {
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
const int dxKn[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dyKn[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dxK[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyK[8] = {1, -1, 0, 0, 1, -1, 1, -1};

const int MOD = int(1e9) + 7;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;
const string abc = "abcdefghijklmnopqrstuvwxyz";
// #############################
const int MAXN = 2000005;

int n, m;              // sizes
vector<vector<int>> g; // graph, grid
int ax, ay, bx, by;
vector<ll> x(MAXN), y(MAXN);
ll memo[MAXN][2];
vector<ll> xs;

ll dist(ll a0, ll b0, ll a1, ll b1) { return abs(a0 - b0) + abs(a1 - b1); }

map<int, vector<ll>> hl;

ll dp(int i, int high) {
  dbg(i, high);
  if (i == sz(xs) - 1)
    return abs(hl[xs[i]][high] - by);

  ll &ret = memo[i][high];
  if (ret != -1)
    return ret;

  ret = INF64;  // answer can exceed 1e10 for large n and coordinates
  ll sweep = hl[xs[i + 1]][1] - hl[xs[i + 1]][0];
  forn(j, 2) {
    dbg(i, j);
    // Land at opposite end (1-j), then sweep to j to visit all points at column
    // i+1
    ll d =
        dist(xs[i], xs[i + 1], hl[xs[i]][high], hl[xs[i + 1]][1 - j]) + sweep;
    dbg(xs[i], xs[i + 1], hl[xs[i]][high], hl[xs[i + 1]][1 - j]);
    dbg(d);
    ret = min(ret, d + dp(i + 1, j));
  }

  return ret;
}

void solve() {
  cin >> n >> ax >> ay >> bx >> by;
  vector<pii> aux(n);

  forn(i, n) cin >> x[i];
  forn(i, n) cin >> y[i];
  forn(i, n) aux[i].fst = x[i], aux[i].snd = y[i];

  aux.insert(aux.begin(), mp(ax, ay));
  aux.pb(mp(bx, by));
  sort(all(aux));

  forn(i, sz(aux)) {
    x[i] = aux[i].fst;
    y[i] = aux[i].snd;
    if (hl.count(x[i]) == 0) {
      hl[x[i]].pb(y[i]), hl[x[i]].pb(y[i]);
    } else {
      hl[x[i]][0] = min(hl[x[i]][0], y[i]);
      hl[x[i]][1] = max(hl[x[i]][1], y[i]);
    }
    if (xs.empty())
      xs.pb(x[i]);
    else if (xs.back() < x[i]) {

      dbg(sz(x), i);
      xs.pb(x[i]);
    }
  }

  // memset(memo, -1, sizeof(memo));
  forn(i, sz(xs) + 3) { forn(j, 2) memo[i][j] = -1; }
  for (auto xx : hl) {
    dbg(xx.fst);
    dbg(xx.snd);
  }
  dbg(xs);
  ll sweep0 = hl[ax][1] - hl[ax][0];
  // To end at (ax, hl[ax][0]): go to hl[ax][1] then sweep down; to end at (ax,
  // hl[ax][1]): go to hl[ax][0] then sweep up
  ll ans = min(abs(ay - hl[ax][1]) + sweep0 + dp(0, 0),
               abs(ay - hl[ax][0]) + sweep0 + dp(0, 1));
  cout << ans << endl;
  hl.clear();
  xs.clear();
}

signed main() {
  fastIO();
  int t = nxt();
  while (t--) {
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
    - Sort input        - Greedy approach               - Split into cases:
   Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/
