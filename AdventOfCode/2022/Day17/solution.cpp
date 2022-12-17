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

int n, m; // sizes
string jet = ">>><<><>><<<>><>>><<<>>><<<><<<>><>><<>>";
int curFigure, curMove;
vector<string> g;
vector<vector<pii>> figures;
set<vector<ll>> keys;
int maxH;


vector<pii> addHLine() {
    vector<pii> ret;
    forn(i, 4) {
        ret.pb(mp(maxH+3, 2+i));
    }

    return ret;
}

vector<pii> addVLine() {
    vector<pii> ret;
    forn(i, 4) {
        ret.pb(mp(maxH+3+i, 2));
    }

    return ret;
}

vector<pii> addCross() {
    vector<pii> ret;
    ret.pb(mp(maxH+3, 3));
    forn(i, 3) {
        ret.pb(mp(maxH+3+1, 2+i));
    }
    ret.pb(mp(maxH+3+2, 3));

    return ret;
}

vector<pii> addSquare() {
    vector<pii> ret;
    ret.pb(mp(maxH+3, 2));
    ret.pb(mp(maxH+3, 3));
    ret.pb(mp(maxH+4, 2));
    ret.pb(mp(maxH+4, 3));

    return ret;
}

void check();

vector<pii> addCorner() {
    dbg(maxH);
    vector<pii> ret;
    forn(i, 3) {
        ret.pb(mp(maxH+3, 2+i));
    }
    forn(i, 2) {
        ret.pb(mp(maxH+3+i+1, 4));
    }

    return ret;
}

bool cmpc(pii a, pii b) {
    return a.snd <= b.snd;
}

vector<pii> addFigure(int type) {
    vector<pii> ret;
    if (type == 0) ret = addHLine();
    if (type == 1) ret = addCross();
    if (type == 2) ret = addCorner();
    if (type == 3) ret = addVLine();
    if (type == 4) ret = addSquare();
    return ret;
}

void moveRight(vector<pii> &p) {
    // first check if can be moved
    nfor(i, (int)p.size()) {
        int r = p[i].fst;
        int nc = p[i].snd +1;
        if (g[r][nc] != '.' || nc >= 7) return;
    }

    // then move
    forn(i, (int)p.size()) {
        p[i].snd++;
    }
}

void moveLeft(vector<pii> &p) {

    forn(i, (int)p.size()) {
        int r = p[i].fst;
        int nc = p[i].snd - 1;
        if (g[r][nc] != '.' || nc < 0) return;
    }

    forn(i, (int)p.size()) {
        p[i].snd--;
    }
}

bool canMoveDown(vector<pii> p) {
    forn(i, (int)p.size()) {
        int nr = p[i].fst-1;
        int c = p[i].snd;
        if (nr < 0 || g[nr][c] != '.') return false;
    }

    return true;
}

void moveDown(vector<pii> &p) {
    forn(i, (int)p.size()) {
        p[i].fst--;
    }
}

bool move(vector<pii> &p) {
    dbg(curMove);
    cout << jet[curMove] << endl;
    if (jet[curMove] == '>') moveRight(p);
    else if (jet[curMove] == '<') moveLeft(p);

    curMove++;
    curMove %= (int) jet.size();
    if (!canMoveDown(p)) return false;

    moveDown(p);
    return true;
}

int getMaxH() {
    int ret = 0;
    forn(i, n) {
        forn(j, 7) {
            if (g[i][j] != '.') ret = max(ret, i);  
        }
    }
    return ret+1;
}

void draw(vector<pii> p) {
    forn(i, (int)p.size()) {
        g[p[i].fst][p[i].snd] = '#';
    }
}

void printG() {
    nfor(i, (int)g.size()) {
        forn(j, (int)g[0].size()) {
            cout << g[i][j];
        }
        cout << endl;
    }
}

void addFigure() {
    check();
    vector<pii> p = addFigure(curFigure++);
    curFigure %= 5; 
    while(true) {
        bool moved = move(p);
        if (!moved) break;
    }

    figures.pb(p);
    draw(p);
    maxH = getMaxH();
    //printG();
    //cout << endl << endl;
}

vector<ll> getSimpleKey() {
    vector<ll> ret;
    ret.pb(curFigure);
    ret.pb(curMove);

    return ret;
}

vector<ll> getKey();

void check() {
    vector<ll> key = getKey();
    if (keys.count(key)) {
        dbg(key);
        cout << "Pattern found! - Current Max Height: " << maxH << " figures: " << figures.size() << endl;
    }
    keys.insert(key);
}

vector<ll> getKey() {
    vector<ll> h;
    forn(i, 7) {
        bool flag = false;
        nfor(j, (int)g.size()) {
            if (g[j][i] == '#') {
                h.pb(j);
                flag = true;
                break;
            }
        }
        if (!flag) h.pb(0);
    }
    

    ll mn = *min_element(all(h));
    forn(i, 7) h[i] -= mn;
    vector<ll> key;
    vector<ll> simpleKey = getSimpleKey();
    key.insert(key.end(), all(h));
    key.insert(key.end(), all(simpleKey));

    return key;
}


int main() {
    fastIO();
    n = 10000;
    g.assign(n, string(7, '.'));
    maxH = 0;
    cin >> jet;
    dbg(jet);
    const ll ROCKS = 5000;
    ll x = 0;
    forn(i, ROCKS) {
        addFigure();
        //vector<ll> key = getKey();
        //if (s.count(key)) {
        //    cycle = i;
        //    cycleH = maxH;
        //}
    }
    printG();
    cout << maxH << endl;
    //cout << cycle << " " << cycleH << endl;
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
// {5, 5, 7, 5, 4, 2, 0, 3, 28}
// 102 63
// 155 98   diff: 53 35
// 208 133  diff: 53 35
// 261 168
//
// 141 * 53 + 102 + 2;
//
// REAL ONE!
// {1, 2, 1, 0, 1, 1, 3, 3, 5063}
//
// 4055 2573
// 6784 4293  -- diff 2729 1720
//
// 1000000000000 - 2573 = 999999997427
// 999999997427/1720 = 581395347
// 999999997427%1720 = 587 
// 4880 = 587 + 4293
// 7687 - 6784 = 903
//
// Answer = 581395347 * 2729 + 4055 + 903 = 1586627906921
//
//
//
