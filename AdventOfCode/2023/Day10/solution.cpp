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
vector<string> g; //graph, grid
                  //
/*
  | is a vertical pipe connecting north and south.
  - is a horizontal pipe connecting east and west.
  L is a 90-degree bend connecting north and east.
  J is a 90-degree bend connecting north and west.
  7 is a 90-degree bend connecting south and west.
  F is a 90-degree bend connecting south and east.
 * */

bool canGoUp(int row, int col) {
    char cur = g[row][col];
    bool flag = cur == '|' || cur == 'L' || cur == 'J';
    if (!flag && cur != 'S') return false;
    row--;
    if (correct(row, col, sz(g), sz(g[0]))) {
        char x = g[row][col];
        return x == '|' || x == '7' || x == 'F';
    }
    return false;
}

bool canGoDown(int row, int col) {
    char cur = g[row][col];
    bool flag = cur == '|' || cur == 'F' || cur == '7';
    if (!flag && cur != 'S') return false;
    row++;
    if (correct(row, col, sz(g), sz(g[0]))) {
        char x = g[row][col];
        return x == '|' || x == 'L' || x == 'J';
    }
    return false;
}

bool canGoLeft(int row, int col) {
    char cur = g[row][col];
    bool flag = cur == '-' || cur == '7' || cur == 'J';
    if (!flag && cur != 'S') return false;
    col--;
    if (correct(row, col, sz(g), sz(g[0]))) {
        char x = g[row][col];
        return x == '-' || x == 'F' || x == 'L';
    }
    return false;
}

bool canGoRight(int row, int col) {
    char cur = g[row][col];
    bool flag = cur == '-' || cur == 'F' || cur == 'L';
    if (!flag && cur != 'S') return false;
    col++;
    if (correct(row, col, sz(g), sz(g[0]))) {
        char x = g[row][col];
        return x == '-' || x == '7' || x == 'J';
    }
    return false;
}
 
signed main() {
    fastIO(); 
    string line;
    while(getline(cin, line)) {
        g.pb(line);
    }
    dbg(g);

    int row, col;
    forn(i, sz(g)) {
        forn(j, sz(g[0])) if (g[i][j] == 'S') row = i, col = j;
    }
    
    vector<vector<int>> dist(sz(g), vector<int>(sz(g[0]), -1));
    dist[row][col] = 0;
    queue<iii> q;
    q.push(mt(row, col, 0));
    while(!q.empty()){
        int a, b, c;
        tie(a,b,c) = q.front(); q.pop();
        if (canGoDown(a,b) && dist[a+1][b] == -1) dist[a+1][b] = c+1, q.push(mt(a+1,b, c+1));
        if (canGoUp(a,b) && dist[a-1][b] == -1) dist[a-1][b] = c+1, q.push(mt(a-1, b, c+1));
        if (canGoLeft(a,b) && dist[a][b-1] == -1) dist[a][b-1] = c+1, q.push(mt(a, b-1, c+1));
        if (canGoRight(a,b) && dist[a][b+1] == -1) dist[a][b+1] = c+1, q.push(mt(a, b+1, c+1));
    }

    int cnt = 0;
    vector<vector<int>> aux(sz(g), vector<int>(sz(g[0]), 0));
    forn(i, sz(g)) {
        bool flag = false, se = false, ne = false;
        char last = '.';
       for (int j = 0; j < sz(g[0]); ++j) {
        if (dist[i][j] != -1) {
        if (g[i][j] == '7' && last == 'L') flag = !flag;
        if (g[i][j] == 'J' && last == 'F') flag = !flag;
        if (g[i][j] == 'F') last = 'F';
        if (g[i][j] == 'L') last = 'L';
        if (g[i][j] == '|') flag = !flag;
        aux[i][j] = 5;
        } else if (flag && g[i][j] == '.') {
            aux[i][j] = 1;
            cnt++;
        }
        } 
    }

  //  forn(i, sz(g[0])) {
  //      bool flag = false;
  //      forn(j, sz(g)) {
  //          if (dist[j][i] != -1) flag = !flag;
  //          if (flag && g[j][i] == '.') {
  //              aux[j][i]++;
  //          }
  //      }
  //  }

    forn(i, sz(g)) {
        forn(j, sz(g[0])) cout << aux[i][j] << " ";
        cout << endl;
    }
    

    int ans = -1;
    forn(i, sz(g)) forn(j, sz(g[0])) ans = max(ans, dist[i][j]);
    cout << ans << endl;
    cout << cnt << endl;
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

