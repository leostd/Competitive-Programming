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

    ll n, k, x;

    cin >> n >> k;
    vector<ll> a(n+1, 0), neg, pos;

    for (int i = 1; i <= n; i++)
        cin >> x, (x >= 0)? pos.pb(x) : neg.pb(x), a.pb(x);

    sort(pos.begin(), pos.end());
    sort(neg.begin(), neg.end());

    cout << to_string(pos)<< endl;
    cout << to_string(neg)<< endl;

    ll cur = 0;
    for (int i = 1; i < n; i++) {
        if (k <= cur + (n-i)) {
            ll offset = k  - cur;
            cout << "cur: " << cur << endl;
            cout << "offset: " << offset << endl;
            cout << "i: " << i << endl;
            if (a[i] < 0)
                cout << a[i] * a[n-offset];
            else
            {
                cout << a[i] * a[i+offset];
            }
            
            return 0;
        }
        cur = cur + (n-i);
    }


    return 0;
}