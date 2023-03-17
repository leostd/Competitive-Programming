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
vector<vector<int>> g; //graph, grid
string abc = "abcdefghijklmnopqrstuvwxyz";

char nextChar(char x) {
    int idx = x-'a';
    if (idx == (int)abc.size()-1) return 'a';
    return abc[idx+1];
}


// a->b->c->d->b
bool hasCycle(map<char, char> f, char src, char dst) {
    f[src] = dst;
    int sz = f.size();
    //forn(i, sz+1) {
    //    if (!f.count(src)) return false;
    //    src = f[src];
    //}
    unordered_set<char> vis;
    int cyc = 0;
    while(vis.count(src) == 0) {
        vis.insert(src);
        if (!f.count(src)) return false;
        src = f[src];
    }
    
    int bg = src;
    cyc++;
    src = f[src];
    if (f.size() == 26) {
        while(src != bg) {
            src = f[src];
            cyc++;
        }
    }
    dbg(cyc);
    //cout << "DEBUG: " << src << " " << dst << endl;
    if (cyc == 26) return false;
        
    return true;
}
map<char, char> getMap(string ps) {

    dbg(ps);
    map<char, char> f;
   // if (ps[0] != 'a') {
   unordered_set<char> vis;
   char cur = 'a';
        forn(i, (int)ps.size()) {
            char x = cur;
            //cout << "DEBUG: " << x << " " << ps[i] << endl;
            while (hasCycle(f, ps[i], x) || vis.count(x)) x = nextChar(x); 
            f[ps[i]] = x;
            vis.insert(x);
            if (cur == x)
            cur = nextChar(cur);
        }
        return f;
    //}

   // if (ps.size() == 1 && ps[0] == 'a') {
   //     f['a'] = 'b';
   //     return f;
   // }
   // char lstc=ps[0];
   // int aux = '.';
   // forn(i, (int)ps.size()) {
   //     if ((int)(ps[i]-'a') == i){ 
   //         char x = nextChar(ps[i]);
   //         //cout << "DEBUG: " << x << endl;
   //         f[ps[i]] = x; 
   //         lstc = f[ps[i]];
   //         //cout << "DEBUG: " << i << " " << ps[i] << " " << nextChar(ps[i]) << endl;
   //         string help;
   //         help.pb(ps[i]);
   //         help.pb(nextChar(ps[i]));
   //         dbg(help);
   //     }
   //     else {
   //         dbg(i, "here");
   //             aux = i;
   //             break;
   //         }
   // }
   // if (aux == '.') return f;
   // f[ps[aux]] = 'a';
   // fore(i, aux+1, (int)ps.size()) {
   //     char x = nextChar(lstc);
   //     while(hasCycle(f, ps[i], x)) x = nextChar(x);
   //     f[ps[i]] = x;
   //     lstc = nextChar(lstc);
   // }
    dbg(f);
    return f;
}

void solve() {
    cin >> n;
    string s;
    cin >> s;
    set<char> st;
    string ans;
    string ps;
    forn(i, n) {
        if (st.count(s[i])) continue;
        st.insert(s[i]);
        ps.pb(s[i]);
    }
    map<char, char> f = getMap(ps);
    dbg(f);
    forn(i, n) ans.pb(f[s[i]]);
        cout << ans << endl;
}
int main() {
    fastIO();
    
    int t = nxt();
    while(t--) {
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
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/

