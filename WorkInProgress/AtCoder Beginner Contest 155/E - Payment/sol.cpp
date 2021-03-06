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
ll memo[MAXN][2], n;
vector<int> digits;

ll dp(int i, bool flag) {
    if (i >= n)
        return 0;

    if (memo[i][flag] != -1)
        return memo[i][flag];
    
    ll a, b;

    // no change expected
    if (flag == 1)
        a = digits[i] + min(dp(i+1, 1), dp(i+1, 0));


    // giving a bigger banknote
    if (flag == 0)
        b = 1 + (10 - digits[i]) + min(dp(i+1,1), max((ll)0, dp(i+1, 0)-2));

    return memo[i][flag] = (flag ? a : b);
}

int main() {
    fastIO();
    string s;
    cin >> s;

    digits = vector<int>(s.size());
    n = s.size();
    REP(i,s.size())
        digits[i] = s[i] - '0';
    memset(memo, -1, sizeof(memo));

    ll ans = min(dp(0,0), dp(0,1));
    cout << ans << endl;
    return 0;
}