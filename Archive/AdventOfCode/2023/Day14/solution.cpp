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

void solve1() {
    forn(i, sz(g)) {
        forn(j, sz(g[0])) {
            if (g[i][j] == 'O') {
                int ii = i;
                while(ii >= 0 && g[ii-1][j] == '.') g[ii][j] = '.', g[ii-1][j] = 'O', ii--;
            } 
        }
    }

    ll ans = 0;
    forn(i, sz(g)) {
        forn(j, sz(g[0])) {
            if (g[i][j] == 'O') ans += (sz(g) - i);
        }
    }

    forn(i, sz(g)) {
        forn(j, sz(g[0])) {
            cout << g[i][j];
        }
        cout << endl;
    }
    

    cout << ans << endl;
    return;
}

void solve2() {
    forn(i, sz(g)) {
        forn(j, sz(g[0])) {
            if (g[i][j] == 'O') {
                int ii = i;
                while(ii >= 0 && g[ii-1][j] == '.') g[ii][j] = '.', g[ii-1][j] = 'O', ii--;
            } 
        }
    }

    forn(i, sz(g)) {
        forn(j, sz(g[0])) {
            if (g[i][j] == 'O') {
                int jj = j;
                while(jj >= 0 && g[i][jj-1] == '.') g[i][jj] = '.', g[i][jj-1] = 'O', jj--;
            } 
        }
    }

    nfor(i, sz(g)) {
        forn(j, sz(g[0])) {
            if (g[i][j] == 'O') {
                int ii = i;
                while(ii+1 < sz(g) && g[ii+1][j] == '.') g[ii][j] = '.', g[ii+1][j] = 'O', ii++;
            } 
        }
    }

    forn(i, sz(g)) {
        nfor(j, sz(g[0])) {
            if (g[i][j] == 'O') {
                int jj = j;
                while(jj+1 < sz(g[0]) && g[i][jj+1] == '.') g[i][jj] = '.', g[i][jj+1] = 'O', jj++;
            } 
        }
    }
}
 
signed main() {
    fastIO(); 
    string line;
    while(getline(cin, line)) {
        g.pb(line);
    }

   // solve1();
    
    vector<string> prev;
    ll cnt = 0;
    map<int, int> frq;
    map<vector<string>, int> frq2;
    bool first = false;
    ll aux = 0, csz;
    vector<string> aux2;
    for1(cyc, 200) {
        while(g != prev && cnt < cyc) {
                prev = g;
                solve2();
                cnt++;
            }
            
        ll ans = 0;
        forn(i, sz(g)) {
            forn(j, sz(g[0])) {
                if (g[i][j] == 'O') ans += (sz(g) - i);
            }
        }

        frq[ans]++;
        if (frq2[g] == 1 && !first) {
            first = true;
            cout << "cycle found!" << endl;
            cout << cyc << endl;
            aux = cyc;
            aux2 = g;
        }
        frq2[g]++;

        if (frq2[aux2] == 3 && g == aux2) {
            cout << "Size of the cycle: " << cyc - aux << endl;
            csz = cyc - aux;
        }
        //forn(i, sz(g)) {
        //    forn(j, sz(g[0])) {
        //        cout << g[i][j];
        //    }
        //    cout << endl;
        //}
        if (cyc == 161 || cyc == 162 || cyc == 160) {
            cout << "This is the answer " << ans << " " << cyc<< endl;
        }
    }

    ll rest = 1e9 - aux+1; 
    ll needed = rest % csz + aux;

    cout << "Iterations needed: " << needed << endl;

    
    

    dbg(sz(frq));
    vector<pii> list;
    for(auto x : frq) {
        //cout << x.fst << " " << x.snd;
        list.pb(mp(x.snd, x.fst));
    }

    sort(all(list), greater<pii>());
    for(auto x : list) {
        cout << x.fst << " " << x.snd << endl;
    }

    dbg(sz(frq2));
    vector<int> ls;
    for(auto x : frq2) {
        ls.pb(x.snd);
    }

    cout << "----" << endl;
    sort(all(ls), greater<int>());
    for(auto x : ls) cout << x << endl;
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

