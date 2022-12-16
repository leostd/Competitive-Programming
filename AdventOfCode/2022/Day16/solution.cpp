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
int cnt;
map<string, int> id;
map<int, string> decode;
map<int, vector<int>> g;
map<int, ll> rate;
ll ans;
vector<vector<ll>> d;
vector<int> vis;
vector<vector<int>> paths;

void dfs(int parent, int curNode, int remTime, ll acum, vector<int> &path) {
    //dbg(parent, curNode, remTime, acum);
    //dbg(path);
   if (remTime == 0) {
        return;
    }
    vis[curNode] = 1;
    //path.pb(curNode);
    //paths.pb(path);
    if (rate[curNode] != 0 && remTime > 0) {
       // dbg("open");
        remTime--;
        acum += remTime * rate[curNode];
        path.pb(curNode);
        vector<int> aux = path;
        aux.pb(acum);
        paths.pb(aux);
        ans = max(ans, acum);
    }

    
    forn(x, n) {
        if (!vis[x] && remTime >= d[curNode][x] && rate[x] > 0) {
            dfs(curNode, x, remTime - d[curNode][x], acum, path);
        }
    }

    vis[curNode] = 0;
    path.pop_back();
}

bool intersect(int i, int j) {
    vector<int> pa = paths[i], b = paths[j];
    if(!pa.empty())
        pa.pop_back();
    set<int> aux(all(pa));
    forn(x, (int)b.size()-1) {
        if (aux.count(b[x])) return true;
    }
    return false;
}

ll compute(int i, int j) {
    return paths[i].back() + paths[j].back();

}

void filter() {
    map<set<int>, vector<int>> best;
    forn(i, (int)paths.size()) {
        vector<int> aux = paths[i];
        aux.pop_back();
        set<int> st(all(aux));
        if (best.count(st)) {
            if (best[st].back() < paths[i].back()) {
                best[st] = paths[i];
            }
        } else {
            best[st] = paths[i];
        }
    }

    paths.clear();
    for(auto x : best) {
        paths.pb(x.snd);
    }
}

void read() {
    string line;
    cnt = 0;
    id.clear();
    decode.clear();
    while(getline(cin, line)) {
        dbg(line);
        stringstream ss(line);
        string cur;
        ss >> cur;
        ss >> cur;
        dbg(cur, "node");
        int node;
        if (!id.count(cur)) {
            node = cnt;
            id[cur] = node;
            decode[node] = cur;
            cnt++;
        } else {
            node = id[cur];
        }
        while(cur.substr(0, 4) != "rate") ss >> cur;
        cur = cur.substr(5, string::npos);
        cur.pop_back();
        dbg("rate", cur);
   rate[node] = stoll(cur);
        while(cur.substr(0, 5) != "valve") ss >> cur;
        while(ss >> cur) {
            if (cur.back() == ',') cur.pop_back();
            dbg(cur);
            int adjacentNode;
            if (!id.count(cur)) {
                adjacentNode = cnt;
                id[cur] = adjacentNode;
                decode[adjacentNode] = cur;
                cnt++;
            } else {
                adjacentNode = id[cur];
            }
            g[node].pb(adjacentNode);
        } 
    }
}

void bfs(int curNode) {
    queue<pii> q;
    q.push(mp(curNode, 0));
    vector<ll> dist(n, INF);
    dist[curNode] = 0;
    while(!q.empty()) {
        pii a = q.front();
        q.pop();
        int cur = a.fst, w = a.snd;
        for(auto x : g[cur]) {
            if (dist[x] > w+1) {
                dist[x] = w+1;
                q.push(mp(x, w+1));
            }
        }
    }
    d[curNode] = dist;
}

int main() {
    fastIO(); 
    
    read();
   // dbg(g);
    dbg(decode);
    dbg(rate);
    for(auto x : g) {
        dbg(x.fst, x.snd);
    }
    ans = 0;
    n = id.size();
    d.assign(n, vector<ll> (n, INF));
    forn(i, n) {
        bfs(i);
    }
    
    dbg(d);
    vis.assign(n, 0);
    vector<int> path;
    dfs(-1, id["AA"], 26, 0, path);
    cout << ans << endl;
    sort(all(paths));
    paths.resize(unique(all(paths)) - paths.begin());
    filter();
    m = paths.size();
    forn(i, m) {
        forn(j, m) {
            if (i == j) continue;
            if (!intersect(i, j)){
               // dbg(paths[i], paths[j]);
                ans = max(ans, compute(i, j));
            }
        }
    }
    cout << paths.size() << endl;
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

