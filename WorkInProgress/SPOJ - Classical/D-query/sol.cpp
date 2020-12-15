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

using namespace std;

#define sqr(x) ((x)*(x))
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define RE(i, n) FOR(i,1,n)
#define REP(i,n) FOR(i, 0, (int)(n)-1)
#define fst first
#define snd second
#define lsb(x) ((x)&(-x))

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

int bit[MAXN];
int n;

void update(int idx, int val) {
    while(idx <= n)
        bit[idx] += val, idx += lsb(idx);
}

ll sum(int idx) {
    ll s = 0;
    while(idx > 0) 
        s += bit[idx], idx -= lsb(idx);
    return s;
}

int main() {
    int q;

    scanf("%d", &n);
    vector<int> a(n+1, 0);
    int x,y,z;
    RE(i, n)
        scanf("%d", &a[i]);

    scanf("%d", &q);
    vector<iii> qs;
    int nq = 1;
    iii tp;
    while(nq <= q) {
        scanf("%d %d", &x, &y);
        get<1>(tp) = x;
        get<0>(tp) = y;
        get<2>(tp) = nq++;
        qs.pb(tp);
    }

    sort(qs.begin(), qs.end());
    map<int,int> mark;
    vector<ll> ans(q+1, 0);
    int idx = 1;
    fill(bit, bit+MAXN, 0);

    REP(i, q) {
        //  cout << get<0>(qs[i]) << get<1>(qs[i]) << get<2>(qs[i]) << endl;
        tie(y,x,z) = qs[i];
        //  cout << x << y << z << endl;
        for(;idx<=y; idx++) {
            if (mark.count(a[idx])==0) {
                mark[a[idx]] = idx;
                // cout << idx << endl;
                update(idx, 1);
            } else {
                update(mark[a[idx]], -1);
                mark[a[idx]] = idx;
                // cout << idx << endl;
                update(idx, 1);
            }
        }
         ans[z] = sum(y) - sum(x-1);
    }

    REP(i,qs.size()) {
        printf("%lld\n", ans[i+1]);
    }

    return 0;
}