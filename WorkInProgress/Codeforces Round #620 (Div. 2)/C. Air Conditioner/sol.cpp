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

pii intersect(int a1, int b1, int a2, int b2) {
    pii ans;
    ans.fst = max(a1, a2);
    ans.snd = min(b1, b2);

    return ans;
}

int main() {
    int q,n,m;
    cin >> q;

    while(q--) {
        cin >> n >> m;

        vector<iii> c, nc;
        map<int, pair<int, int>> filter;
        bool flag = true;
        int x,y,z;
        REP(i,n){
            cin >> x >> y >> z, c.pb(tie(x,y,z));
            // if (filter.count(x)){
            //     filter[x] = intersect(filter[x].fst, filter[x].snd, y,z);
            //     flag = !(filter[x].fst > filter[x].snd);
            // }
            // else{
            //     filter[x] = pii(y,z);
            // }
        }

        // if (!flag){
        //     cout << "NO\n";
        //     continue;
        // }

        // c.clear();
        // for (auto x: filter) {
        //     c.pb(iii(x.fst, x.snd.fst, x.snd.snd));
        // }

        
        flag = true;
        sort(c.begin(), c.end());
        int cur_tmp_a = m, cur_tmp_b = m, cur_time = 0;
        for(int i = 0; i < n; i++) {
            tie(x,y,z) = c[i];  
            int pa, pb; // possible range;
            pa = cur_tmp_a - (x - cur_time); 
            pb = cur_tmp_b + (x - cur_time);
            pii nw = intersect(pa, pb, y, z);
            // cout << i << ": " << to_string(nw) << endl;
            // cout << i << ": " << cur_time << " " << cur_tmp_a << " " << cur_tmp_b << endl;
            // cout << i << ": " << x << " " << y << " " << z << endl;
            if (nw.snd < nw.fst){
                cout << "NO\n";
                flag = false;
                break;
            }
            cur_tmp_a = nw.fst;
            cur_tmp_b = nw.snd;
            cur_time = x;
        }
        if (flag)
            cout << "YES\n";
    }
    return 0;
}