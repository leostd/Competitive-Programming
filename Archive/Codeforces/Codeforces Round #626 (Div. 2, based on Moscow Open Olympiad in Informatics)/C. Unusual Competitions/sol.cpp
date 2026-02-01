// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("O3") 
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

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
    fastIO();
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    int open = 0, close = 0;
    vector<int> balance(n+1, 0);

    for (int i = 0; i < n; i++)
        open += s[i] == '(', close += s[i] == ')';
    
    if (open != close){
        cout << -1 << endl;
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        balance[i] = balance[i-1] + (s[i-1] == ')'? -1 : 1);
    }

    int i = 1, j = 1;
    int ans = 0;
    // cout << to_string(balance) << endl;
    while(i < n) {
        while(i < n && balance[i] >= 0)
            i++;
        if(i >= n)
            break;
        j = i;
        while(j < n && balance[j] < 0)
            j++;
        ans += j-i+1;
        i = j;
    }
    cout << ans << endl;
    return 0;
}