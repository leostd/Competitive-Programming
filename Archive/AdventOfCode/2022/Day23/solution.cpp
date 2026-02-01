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

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
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
const int NROUND = 10;

int n, m; // sizes
vector<pii> elves;
set<pii> pos;
bool noMove = false;
int start = 0;

void readInput() {
    string ln;
    vector<string> g;
    while(cin >> ln) {
        g.pb(ln);
    }
    forn(i, (int)g.size()) {
        forn(j, (int)g[0].size()) {
            if (g[i][j] == '#') {
                elves.pb(mp(i, j));
                pos.insert(mp(i, j));
            }
        }
    }
    dbg(pos.size());
    dbg(pos);
}

bool check(int op, ll x, ll y) {
    int northx = x-1, northy = y;
    int southx = x+1, southy = y;
    int eastx = x, easty = y+1;
    int westx = x, westy = y-1;
    int nex = x-1, ney = y+1;
    int nwx = x-1, nwy = y-1;
    int sex = x+1, sey = y+1;
    int swx = x+1, swy = y-1;
    
    if (op == 0) {
        return !pos.count(mp(northx, northy)) && !pos.count(mp(nex, ney)) && !pos.count(mp(nwx, nwy));
    }

    if (op == 1) {
        return !pos.count(mp(southx, southy)) && !pos.count(mp(sex, sey)) && !pos.count(mp(swx, swy));
    }

    if (op == 2) {
        return !pos.count(mp(westx, westy)) && !pos.count(mp(nwx, nwy)) && !pos.count(mp(swx, swy));
    }

    if (op == 3) {
        return !pos.count(mp(eastx, easty)) && !pos.count(mp(nex, ney)) && !pos.count(mp(sex, sey));
    }

    cout << "Something is wrong!" << endl;
    dbg(op, x, y);

    return false;
}

bool propose(ll x, ll y, ll &nx, ll &ny) {
    bool exist = false;
    forn(i, 8) {
        int xx = x + dxK[i];
        int yy = y + dyK[i];
        if (pos.count(mp(xx, yy))) {
            exist = true;
            break;
        }
    }

    if (!exist) return false;

    forn(i, 4) {
        int mv = (start + i) % 4;
        if (check(mv, x, y)) {
            nx = x + dx[mv];
            ny = y + dy[mv];
            return true;
        }

    }

    dbg(x, y, "This Elf can't move");
    return false;
}

void round() {
    map<pii, vector<int>> proposals;
    forn(i, (int)elves.size()) {
        pii e = elves[i];
        ll x = e.fst;
        ll y = e.snd;
        ll nx, ny;
        if (propose(x, y, nx, ny)) {
            proposals[mp(nx, ny)].pb(i);
        }
    }

    for(auto p : proposals) {
        if ((int)p.snd.size() > 1) {
            dbg("More than 1 proposal", p.snd.size());
            continue;

        }

        noMove = false;
        pii e = elves[p.snd[0]];
        ll x = e.fst;
        ll y = e.snd;
        pos.erase(mp(x, y));
        elves[p.snd[0]] = p.fst;
        pos.insert(p.fst);
    }

    start++;
    start %= 4;
}

void drawState() {
    vector<string> g(20, string(20, '.'));
    for(auto e : elves) {
        dbg(e);
        g[e.fst+5][e.snd+5] = '#';
    }

    forn(i, (int)g.size()) {
        forn(j, (int)g[0].size()) {
            cout << g[i][j];
        }
        cout << endl;
    }
}
void solve1() {
    drawState();
    forn(i, NROUND) {
        round();
        drawState();
    }

    ll minX = INF64, maxX = -INF64, minY = INF64, maxY = -INF64;
    for(auto e : elves) {
        ll x = e.fst;
        ll y = e.snd;
        minX = min(minX, x);
        maxX = max(maxX, x);
        minY = min(minY, y);
        maxY = max(maxY, y);
    }
    ll ans = (maxX - minX + 1) * (maxY - minY + 1) - elves.size();
    cout << ans << endl;
}

void solve2() {
    //drawState();

    ll ans = 0;
    noMove = false;
    while(!noMove) {
        noMove = true;
        round();
        ans++;
    }
    cout << ans << endl;
}



int main() {
    fastIO(); 
    readInput();
    //solve1();
   solve2();
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

