/*
    think first, always - c,g,a, alg - r,s,iag?,iabs?
*/

#pragma GCC diagnostic ignored "-Wunused-const-variable"
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <complex>
#include <algorithm>
#include <utility>
#include <functional>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define fst first
#define snd second
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;

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
    
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
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
vector<string> g;
vector<pii> p;
vector<bool> vis;

bool bfs(char x){
    queue<pii> q;
    q.push(mp(0,0));
    vector<vector<bool>> v(200, vector<bool>(200, false));
    v[0][0] = true;
    int n = g.size();
    while(!q.empty()){
        pii a = q.front();
        dbg(a);
        q.pop();
        for(int i = 0;i < 4; i++){
            int nr = a.fst + dx[i];
            int nc = a.snd + dy[i];
            // dbg(correct(nr,nc,n,n));
            if (!correct(nr, nc, n, n))
                continue;
            // else 
            //     cout << g[nr][nc] << " " << x << endl;

            if (g[nr][nc] == 'F')
                return true;

            if (!v[nr][nc] && g[nr][nc] == x){
                v[nr][nc] = true;
                q.push(mp(nr,nc));
            }
        }
    }

    return false;
}

vector<pii> f(vector<int> ch, bool &found){
    if (ch.size() == 2){
        pii aa = p[ch[0]], bb = p[ch[1]];
        char a = g[p[ch[0]].fst][p[ch[0]].snd];
        char b = g[p[ch[1]].fst][p[ch[1]].snd];
        for(int i = 0; i < 2; i++){
            for (int j = 0; j < 2; j++){
                g[aa.fst][aa.snd] = i+'0';
                g[bb.fst][bb.snd] = j+'0';
                bool r0 = bfs(0);
                bool r1 = bfs(1);
                if (!r0 && !r1){
                    vector<pii> ans;
                    if (g[aa.fst][aa.snd] != a)
                        ans.pb(aa);
                    if (g[bb.fst][bb.snd] != b)
                        ans.pb(bb);
                }
            }
        }
    }

    for(int i = 0; i < 4; i++){

    }
}

void bt(vector<int> ch, bool found){
    if (ch.size() == 2){
        bool flag = false;
        vector<pii> ans = f(ch, flag);
        if (flag){
            
        }

    }
}

char inv(char x){
    return (x == '1'? '0' : '1');
}

void solve() {
    int n = nxt();
    string r;
    g.clear();
    forn(i, n)
        cin >> r, g.pb(r);

    // p = vector<pii>({mp(0,1), mp(1,0), mp(n-1, n-2), mp(n-2, n-1)});
    // vis = vector<bool>(4,0);
    vector<pii> ans;
    char a, b, c, d;
    a = g[0][1], b = g[1][0];
    c = g[n-1][n-2], d = g[n-2][n-1];
    if (a == b){
        if (c == d){
            if (a == c)
                ans.pb(mp(n-1, n-2)), ans.pb(mp(n-2, n-1));
            else{
                // do nothing
            }
        } else {
            char tgt = inv(a);
            if (c != tgt)
                ans.pb(mp(n-1, n-2));
            else 
                ans.pb(mp(n-2, n-1));
        }
    } else {
        if (c == d) {
            char tgt = inv(c);
            if (a != tgt)
                ans.pb(mp(0,1));
            else 
                ans.pb(mp(1,0));
        } else {
            char tgt = '0';
            if (a != tgt)
                ans.pb(mp(0,1));
            else 
                ans.pb(mp(1,0));
            tgt = '1';
            if (c != tgt)
                ans.pb(mp(n-1, n-2));
            else 
                ans.pb(mp(n-2, n-1));
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        cout << x.fst + 1 << " " << x.snd + 1<< endl;
    }
    
}

int main() {
    fastIO(); 
    int t = nxt();
    while(t--) {
        solve();
    }
    return 0;
}