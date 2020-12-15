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
const int MAXN = 1000005;

int main() {
    vector<int> g[2005];
    int n,x,y;
    cin >> n >> x >> y;

    for(int i = 1; i < n; i++){
        g[i].pb(i+1);
        g[i+1].pb(i);
    }

    g[x].pb(y);
    g[y].pb(x);

    ll ans[2005];
    memset(ans, 0, sizeof(ans));
    bool mark[2005];
    queue<pii> q;
    for(int node = 1; node <= n; node++) {
        q.push(pii(node,0));
        // cout << "node: " << node << endl;
        memset(mark, 0, sizeof(mark));
        mark[node] = true;
        while(!q.empty()){
            int j = q.front().snd;
            // for(int i = 0; i < q.size(); i++){
            //     cout << q.front().fst << " ";
            //     q.push(q.front());
            //     q.pop();
            // }
            // cout << endl;
            int src = q.front().fst; q.pop();

            for(auto w : g[src]){
                if (!mark[w]){
                    mark[w] = true;
                    ans[j+1]++;
                    q.push(pii(w, j+1));
                }
            }   
        }
    }
    int i = 1;
    // cout << "---" << endl;
    while(i < n){
        cout << ans[i]/2 << endl;
        i++;
    }
    

    return 0;
}