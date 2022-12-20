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
const int ORE_ROBOT_COST = 0;
const int CLAY_ROBOT_COST = 1;
const int OBSIDIAN_ROBOT_COST_1 = 2;
const int OBSIDIAN_ROBOT_COST_2 = 3;
const int GEODE_ROBOT_COST_1 = 4;
const int GEODE_ROBOT_COST_2 = 5;
int n, m; // sizes
vector<vector<int>> g; //graph, grid
string inputPattern = "Blueprint %d: Each ore robot costs %d ore. Each clay robot costs %d ore. Each obsidian robot costs %d ore and %d clay. Each geode robot costs %d ore and %d obsidian.\n";
vector<vector<int>> bprint;
vector<int> c;
int ans;

void loadBprint(int i) {
    c = bprint[i];
}

bool can(int ore, int clay, int obsidian, int opt) {
    if (opt == 0) {
        return ore >= c[ORE_ROBOT_COST];
    }

    if (opt == 1) {
        return ore >= c[CLAY_ROBOT_COST];
    }

    if (opt == 2) {
        return ore >= c[OBSIDIAN_ROBOT_COST_1] && clay >= c[OBSIDIAN_ROBOT_COST_2];
    }

    if (opt == 3) {
        return ore >= c[GEODE_ROBOT_COST_1] && obsidian >= c[GEODE_ROBOT_COST_2];
    }

    return false;
}

void bf(int remTime, int ore, int clay, int obsidian, int geode, int oreRobot, int clayRobot, int obsidianRobot, int geodeRobot) {
    if (remTime == 0) {
        ans = max(geode, ans);
        return;
    }

    int nore = ore + oreRobot;
    int nclay = clay + clayRobot;
    int nobsidian = obsidian + obsidianRobot;
    int ngeode = geode + geodeRobot;
    bool flag = false;
    if (can(ore, clay, obsidian, 3)) {
        bf(remTime-1, nore-c[GEODE_ROBOT_COST_1], nclay, nobsidian-c[GEODE_ROBOT_COST_2], ngeode, oreRobot, clayRobot, obsidianRobot, geodeRobot+1);
        flag = true;
    }

    if (!flag && can(ore, clay, obsidian, 0) && ore + oreRobot*remTime < remTime*max({c[ORE_ROBOT_COST], c[CLAY_ROBOT_COST], c[OBSIDIAN_ROBOT_COST_1], c[GEODE_ROBOT_COST_1]})) {
        bf(remTime-1, nore - c[ORE_ROBOT_COST], nclay, nobsidian, ngeode, oreRobot+1, clayRobot, obsidianRobot, geodeRobot);
         
    }

    if (!flag && can(ore, clay, obsidian, 1) && clay + clayRobot*remTime < remTime*c[OBSIDIAN_ROBOT_COST_2]) {
        bf(remTime-1, nore - c[CLAY_ROBOT_COST], nclay, nobsidian, ngeode, oreRobot, clayRobot+1, obsidianRobot, geodeRobot);
    }

    if (!flag && can(ore, clay, obsidian, 2) && obsidian + obsidianRobot*remTime < remTime*c[GEODE_ROBOT_COST_2]) {
        bf(remTime-1, nore-c[OBSIDIAN_ROBOT_COST_1], nclay-c[OBSIDIAN_ROBOT_COST_2], nobsidian, ngeode, oreRobot, clayRobot, obsidianRobot+1, geodeRobot);
    }

    if (!flag)
        bf(remTime-1, nore, nclay, nobsidian, ngeode, oreRobot, clayRobot, obsidianRobot, geodeRobot);
}

//ll bfs() {
//    queue<vector<int>> q;
//    q.push(vector<int>({0, 0, 0, 1, 0, 0}));
//    int vis[24][4][20][20][12][10][4][4];
//
//}

void solve1() {
    ll a = 0;
    forn(i, (int)bprint.size()) {
        loadBprint(i);
        //ll maxGeode = bfs();
        ans = 0;
        bf(24, 0, 0, 0, 0, 1, 0, 0, 0);
        ll maxGeode = ans;
        dbg(maxGeode);
        a += (ll)(i+1) * (ll)maxGeode;
    }

    cout << a << endl;
}

void solve2() {
    ll a = 1;
    forn(i, min((int)bprint.size(), 3)) {
        loadBprint(i);
        ans = 0;
        bf(32, 0, 0, 0, 0, 1, 0, 0, 0);
        dbg(ans);
        a *= ans;
    }

    cout << a << endl;
}
int main() {
    //fastIO(); 
    int bp, oc, cc, obc1, obc2, gc1, gc2;
    while(scanf(inputPattern.c_str(), &bp, &oc, &cc, &obc1, &obc2, &gc1, &gc2) != EOF) {
        vector<int> aux(6);
        aux[ORE_ROBOT_COST] = oc;
        aux[CLAY_ROBOT_COST] = cc;
        aux[OBSIDIAN_ROBOT_COST_1] = obc1;
        aux[OBSIDIAN_ROBOT_COST_2] = obc2;
        aux[GEODE_ROBOT_COST_1] = gc1;
        aux[GEODE_ROBOT_COST_2] = gc2;
        bprint.pb(aux);
    }

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

