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
double memo[3005][3005];
int n;
vector<double> p;

double dp(int i, int h) {
    if (i == 0 && h == 0)
        return 1;
    if (i == 0)
        return 0;
    if (i < h)
        return 0;
    if (memo[i][h] < 0)
        return memo[i][h];
    return memo[i][h] = p[i]*dp(i-1,h-1) + (1-p[i])*dp(i-1, h);
}

int main() {
    cin >> n;
    double x=-1;
    p.pb(x);
    for (int i = 0;i < n; i++)
        cin >> x, p.pb(x);
    memset(memo, 0.00, sizeof(memo));
    memo[0][0] = 1.00;
    // for (int j = 1; j <= n; j++)
    //     memo[0][j] = 0.00;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= i; j++){
            memo[i][j] = p[i]*memo[i-1][j-1] + (1-p[i])*memo[i-1][j];
        }
    }
    x = 0.00;
    for (int i = n; i >= n/2+1; i--) {
        // cout << memo[n][i] << endl;
        x += memo[n][i];
    }
    cout.precision(12);
    cout << x << endl;
    return 0;
}