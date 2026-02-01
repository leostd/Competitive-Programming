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
int n;
vector<ll> a, b, c;
map<int, vector<ll>> m;
ll memo[MAXN][3];

ll dp(int i, int act) {
    if (i == -1)
        return 0;

    if (memo[i][act] != -1)
        return memo[i][act];
    
    memo[i][act] = max(dp(i-1, (act+1)%3) + m[(act+1)%3][i], dp(i-1, (act+2)%3) + m[(act+2)%3][i]);
    return memo[i][act];
}

int main() {
    cin >> n;
    int x,y,z;
    for (int i = 0; i < n; i++)
        cin >> x >> y >> z, a.pb(x), b.pb(y), c.pb(z);
    m[0] = a;
    m[1] = b;
    m[2] = c;
    memset(memo, -1, sizeof(memo));
    ll ans = dp(n-1, 0);
    memset(memo, -1, sizeof(memo));
    ans = max(ans, dp(n-1, 1));
    memset(memo, -1, sizeof(memo));
    ans = max(ans, dp(n-1, 2));
    cout << ans << endl;
    return 0;
}