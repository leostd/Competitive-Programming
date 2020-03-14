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
const ll MOD = 1000000007;

ll sum(ll a, ll b) {
    return ((a%MOD) + (b%MOD)) % MOD;
}

ll mult(ll a, ll b) {
    return ((a%MOD) * (b%MOD)) % MOD;
}

ll memo[MAXN];
string s;

ll dp(int idx) {
    if (idx == 0 || idx == 1)
        return 1;

    if (memo[idx] != -1)
        return memo[idx];
    
    if (idx > 1 && (s[idx-1] == 'u' || s[idx-1] == 'n') && s[idx-1] == s[idx-2])
        memo[idx] = sum(dp(idx-1), dp(idx-2));
    else
        memo[idx] = dp(idx-1);
    return memo[idx];
}

int main() {

    cin >> s;



    memset(memo, -1, sizeof(memo));
    bool flag = true;
    ll ans;
    for(int i = 0; i < s.size(); i++)
        if (s[i] == 'm' || s[i] == 'w')
            flag = false, ans = 0;
    if (flag){
        memo[0] = memo[1] = 1;
        for (int i = 2; i <= s.size(); i++) {
            memo[i] = memo[i-1];
            if ((s[i-1] == 'u' || s[i-1] == 'n') && s[i-1] == s[i-2]){
                memo[i] = sum(memo[i], memo[i-2]);
            }
        }
        ans = memo[s.size()];
    }
    cout << ans << "\n";

    return 0;
}