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

vector<int> digit;
ll memo[201][4][2];
int k, n;

ll dp(int idx, int cnt, int tight) {
    if (idx == n && cnt == k) {
        return 1;
    }
    if (cnt > k || idx >= n){
        return 0;
    }
    if (memo[idx][cnt][tight] != -1){
        return memo[idx][cnt][tight];
    }
    int target = (tight? digit[idx] : 9);
    ll ret = 0;
    // cout << ret << endl;
    for (int x = 0; x <= target; x++) {
        int ntight = (x == digit[idx])? tight : 0;
        ret += dp(idx+1, cnt + (x > 0), ntight);
    }
    // cout << idx << " " << cnt <<" "<< tight << endl;
    // cout << ret << endl;
    memo[idx][cnt][tight] = ret;
    return ret;
}

int main() {

    string s;

    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < s.size(); i++)
        digit.pb(s[i]-'0');

    // cout << n << endl;
    // cout << k << endl;
    memset(memo, -1, sizeof(memo));
    ll ans = dp(0,0,1);
    // cout << to_string(digit) << endl;
    // cout << (to_string(digit) == s) << endl;

    cout << ans << endl;
    return 0;
}