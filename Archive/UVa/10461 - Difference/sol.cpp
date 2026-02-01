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
#define endl "\n"

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

int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};
int KXMOV[8] = {};
int KYMOV[8] = {};
int FXMOV[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int FYMOV[8] = {1, -1, 0, 0, 1, -1, 1, -1};

//#############################
const int MAXN = 1000005;
bool vis1[600], vis2[600];
vector<ll> a;

int dependency(int src, const vector<vector<int>> &dependant){
    vis1[src] = true;
    int res = a[src];
    for(int i = 0; i < dependant[src].size(); i++){
        if (!vis1[dependant[src][i]]){
            res += dependency(dependant[src][i], dependant);
        }
    }

    return res;
}


int main() {
    int v, e;
    int c = 1;
    vector<vector<int>> depends, dependant;
    while(cin >> v >> e && (v || e)) {
        // cout << v << " " << e << endl;
        depends = vector<vector<int>>(v+1, vector<int>());
        dependant = vector<vector<int>>(v+1, vector<int>());
        a = vector<ll> (v, 0); 
        generate(all(a), nxt);


        // cout << to_string(a) << endl;

        int src, dst;
        for(int i = 0; i < e; i++){
            src = nxt(), dst = nxt();
            // cout << src << " " << dst << endl;
            depends[src-1].pb(dst-1);
            dependant[dst-1].pb(src-1);
        }

        ll total_time = 0;
        for(int i = 0; i < v; i++)
            total_time += a[i];

        // cout << "total_time: " << total_time << endl;

        int q = nxt();
        
        // cout << q << endl;
        int x;
        cout << "Case #" << c++ << ":\n";
        while(q--) {
            x = nxt();
            x--;
            memset(vis1, 0, sizeof(vis1));
            ll dependencies_time = dependency(x, dependant);
            ll max_time = total_time - dependencies_time;
            // cout << to_string(dependant[x]);
            // debug_out(dependencies_time, total_time, max_time);

            ll min_time = -a[x];
            memset(vis1, 0, sizeof(vis1)); 
            min_time += dependency(x, depends);
            // cout << min_time << " " << max_time << endl;
            // debug_out(min_time, max_time);
            cout << max_time - min_time << endl;
        }    
        
        cout << endl;

    } 

    return 0;
}