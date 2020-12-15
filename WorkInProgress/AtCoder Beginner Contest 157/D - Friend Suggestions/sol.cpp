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


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

//#############################
const int MAXN = 100005;
vector<int> g[MAXN], b[MAXN], c[MAXN];
map<int, int> component, friends;
bool visited[MAXN];

void dfs(int src, int cmp) {
    visited[src] = true; // mark as visited
    component[src] = cmp; // set corresponding conected component
    c[cmp].pb(src); // getting all the nodes of the conected component

    for(int i = 0; i < g[src].size(); i++) {
        if (!visited[g[src][i]]){
            dfs(g[src][i], cmp);
        }
    }
}
int blocks(int src) {
    int ans = 0;
    for (auto x : b[src]){
        if (component[x] == component[src] && find(g[src].begin(), g[src].end(), x) == g[src].end())
            ans++;
    }

    return ans;
}
int main() {
    fastIO();
    int n, m, k;

    cin >> n >> m >> k;

    int n1, n2;
    REP(i, m) {
        cin >> n1 >> n2;
        g[n1].pb(n2);
        g[n2].pb(n1);
    }

    REP(i, k) {
        cin >> n1 >> n2;
        b[n1].pb(n2);
        b[n2].pb(n1);
    }

    int cmp = 0;
    memset(visited, 0, sizeof(visited));
    RE(i, n) {
        if (!visited[i]) {
            dfs(i, cmp);
            cmp++;
        }
    }

    RE(i, n) {
        friends[i] = c[component[i]].size() - g[i].size() - blocks(i) - 1;

        cout << friends[i] << " ";
    }

    cout << endl;


    return 0;
}