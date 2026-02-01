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


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

//#############################
const int MAXN = 1000005;

int n;

bool cmp(pii x, pii y) {
    if(x.fst == y.fst)
        return x.snd < y.snd;
    
    return x.fst > y.fst;
}

int main() {
    int t = nxt();
    while(t--) {
        n = nxt();
        vector<int> ans(n+1, 0);
        vector<pii> a;
        queue<pii> q;
        q.push(mp(1,n));
        set<pii> visited;
        visited.insert(mp(1,n));
        while(!q.empty()){
            pii x = q.front();
            q.pop();

            pii y = mp(x.snd - x.fst + 1, (x.snd + x.fst)/2);
            a.pb(y);
            pii l, r;
            // cout << x.fst << " " << x.snd << endl;
            int mid = (x.fst + x.snd) / 2;
            // cout << mid << endl;
            if(x.fst == x.snd)
                continue;
            
            if (mid-1 >= x.fst && x.fst >= 1){
                l = mp(x.fst, mid-1);
                if (!visited.count(l))            
                    q.push(l), visited.insert(l);
            }
            if (mid+1 <= x.snd && x.snd <= n){
                r = mp(mid+1, x.snd);
                if (!visited.count(r))
                    q.push(r), visited.insert(r);
            }
        }
        sort(all(a), cmp);
        // cout << to_string(a) << endl;
        int j = 1;
        for(auto p : a){
            ans[p.snd] = j++;  
        }
        
        for (int i = 1; i <= n; i++)
            cout << ans[i] << " ";
        cout << endl;
    }


    return 0;
}