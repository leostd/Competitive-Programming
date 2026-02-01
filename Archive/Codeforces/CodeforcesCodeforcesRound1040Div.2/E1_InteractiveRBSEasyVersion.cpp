// time-limit: 2000
// problem-url: https://codeforces.com/contest/2130/problem/E1

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
const int MAXN = 1000005;

int n, m; // sizes

int query(vector<int> &a) {
  string q = "?";

  q += " " + to_string(sz(a));
  for (auto x : a)
    q += " " + to_string(x);

  cout << q << endl;
  ll ans;
  cout.flush();
  cin >> ans;

  return ans;
}

int g(int l, int r) {
  vector<int> idx;
  fore(i, l, r + 1) idx.pb(i);
  return query(idx);
}

int h(int l, int r, int &id1, int &id2) {
  if (l >= r)
    return 0;

  if (r - l == 1) {
    id1 = l;
    id2 = r;
    return 1;
  }

  int mid = (l + r) / 2;
  int ls = g(l, mid);
  if (ls > 0) {
    return h(l, mid, id1, id2);
  }

  return h(mid, r, id1, id2);
}

map<int, char> ch(int x, int y, int l, int r) {
  vector<int> aux;
  aux.pb(x);
  aux.pb(r);
  aux.pb(y);
  aux.pb(r);
  aux.pb(l);
  aux.pb(r);

  ll qq = query(aux);

  dbg(qq);

  map<int, char> ret;
  if (qq == 6) {
    ret[x] = '(';
    ret[y] = '(';
  }
  if (qq == 2) {
    ret[x] = '(';
    ret[y] = ')';
  }
  if (qq == 3) {
    ret[x] = ')';
    ret[y] = '(';
  }
  if (qq == 1) {
    ret[x] = ')';
    ret[y] = ')';
  }

  return ret;
}

void solve() {
  cin >> n;
  string ans(n + 1, 'x');
  pii x = (g(1, n) == 0) ? mp(n, 1)
                         : mp(-1, -1); // corner case - first character must be
                                       // ) and last one must be (

  int l, r;
  l = r = -1;
  if (x.fst == -1) {
    int aux = h(1, n, l, r);
  } else {
    l = x.fst;
    r = x.snd;
  }

  dbg(l, r);

  ans[l] = '(';
  ans[r] = ')';
  vector<int> na;
  for1(i, n + 1) {
    if (i == l || i == r)
      continue;
    na.pb(i);
  }

  while (sz(na) > 1) {
    int a0 = na.back();
    na.pop_back();
    int a1 = na.back();
    na.pop_back();

    map<int, char> aux = ch(a0, a1, l, r);

    for (auto xx : aux) {
      ans[xx.fst] = xx.snd;
    }
  }

  if (sz(na)) {
    vector<int> qaux = {l, na[0]};
    int qans = query(qaux);
    if (qans) {
      ans[na[0]] = ')';
    } else
      ans[na[0]] = '(';
  }

  ans.erase(ans.begin());
  cout << "! ";
  cout << ans << endl;
  cout.flush();
}

signed main() {
  // fastIO();
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
