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
const int MAXN = 2000;

int n, m; // sizes
vector<string> g; //graph, grid
int MAXY = -1;
int MAXX = -1;

bool dropSnow() {
    int cx = 0, cy = 500;
    while(g[0][500] != 'o') {
    //while(cx < MAXX) {
        if (correct(cx+1, cy, MAXN, MAXN) && g[cx+1][cy] != '#' && g[cx+1][cy] != 'o') {
            cx++;
            continue;
        } else if (correct(cx+1, cy-1, MAXN, MAXN) && g[cx+1][cy-1] != '#' && g[cx+1][cy-1] != 'o') {
            cx++;
            cy--;
            continue;
        } else if (correct(cx+1, cy+1, MAXN, MAXN) && g[cx+1][cy+1] != '#' && g[cx+1][cy+1] != 'o') {
            cx++;
            cy++;
            continue;
        } else {
            g[cx][cy] = 'o';
            return true;
        } 
    }
    dbg(cx, cy);
    return false;
}

void draw(pii a, pii b) {
    int x0 = a.fst, x1 = b.fst;
    int y0 = a.snd, y1 = b.snd;
    if (x0 == x1) {
        int mxy = max(y0, y1);
        MAXY = max(MAXY, mxy);
        int mny = min(y0, y1);
        fore(i, mny, mxy+1) g[x0][i] = '#';
    } else if (y0 == y1) {
        int mxx = max(x0, x1);
        int mnx = min(x0, x1);
        MAXX = max(MAXX, mxx);
        fore(i, mnx, mxx+1) g[i][y0] = '#';
    }
}

void draw(vector<pii> lines) {
    dbg(lines);
    for1(i, (int)lines.size()) {
        draw(lines[i-1], lines[i]);
    }
}

int main() {
    fastIO(); 
    g.assign(MAXN, string(MAXN, '.'));
    string ln;
    while(getline(cin, ln)) {
        stringstream ss(ln);
        vector<pii> lines;
        int x, y;
        string s;
        while(ss >> s) {
            if (s == "->") continue;
            int idx = s.find(',');
            x = stoi(s.substr(0, idx));
            y = stoi(s.substr(idx+1, string::npos));
            dbg(x, y);
            lines.pb(mp(y, x));
        }
        draw(lines);        
    }
    forn(i, MAXN) {
        forn(j, MAXN) {
            cout << g[i][j];
        }
        cout << endl;
    }
    
    forn(i, MAXN) {
        g[MAXX+2][i] = '#';
    }
    int ans = 0;
    while(dropSnow()) {
        ans++;
    }
    forn(i, MAXN) {
       forn(j, MAXN) {
           cout << g[i][j];
       }
       cout << endl;
    }

    dbg(MAXX, MAXY);
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

