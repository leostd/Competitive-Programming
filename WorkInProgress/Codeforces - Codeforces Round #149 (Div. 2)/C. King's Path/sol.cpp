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

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
#define all(x) (x).begin(), (x).end()
#define fst first
#define snd second

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;

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

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

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


int XMOV[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int YMOV[8] = {1, -1, 0, 0, 1, -1, 1, -1};

//#############################
const int MAXN = 1000005;

map<int, vector<pii>> m;

bool check(int r, int c) {
    return r >= 0 && r < (1e9+1) && c >= 0 && c < (1e9+1);
}

bool allowed(int r, int c) {
    if (m.count(r)){
        for (auto p : m[r]){
            if (c <= p.snd && c >= p.fst)
                return true;
        }
    }

    return false;
}

ll bfs(int sr, int sc,int  tr, int tc) {
    if (sr == tr && sc == tc)
        return 0;

    set<pii> visited;
    visited.insert(mp(sr, sc));
    queue<iii> q;
    q.push(make_tuple(sr,sc,0));
    while(!q.empty()) {
        iii a = q.front();
        q.pop();
        int r, c, mv;
        r = get<0>(a);
        c = get<1>(a);
        mv = get<2>(a);

        for (int i = 0; i < 8; i++) {
            int nr = r + XMOV[i], nc = c + YMOV[i];
            if (nr == tr && nc == tc && allowed(nr, nc))
                return mv + 1;
            
            if (check(nr, nc) && allowed(nr, nc) && !visited.count(mp(nr, nc))){
                visited.insert(mp(nr, nc));
                q.push(make_tuple(nr, nc, mv+1));
            }
        }
    }

    return -1;
    
}

int main() {
    fastIO();
    int r0, c0, r1, c1;
    int n;
    cin >> r0 >> c0 >> r1 >> c1;
    cin >> n;
    int a, b, r;
    for (int i = 0; i < n; i++) {
        cin >> r >> a >> b;
        m[r].pb(mp(a, b));
    }
    ll ans = bfs(r0, c0, r1, c1);

    cout << ans << endl;
    return 0;
}