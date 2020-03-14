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

ll gcd(ll a, ll b) {
    if (a > b) {
        ll aux = a;
        a = b;
        b = aux;
    }
    if (a == 0)
        return b;
    else 
        return gcd(b%a, a);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll divisible_numbers(ll x, vector<ll> s) {
    int n = s.size();
    ll ans = 0;

    for(int bitmask = 1; bitmask < (1 << n); bitmask++) {
        int bits_on = 0;
        ll lcm = 1;
        for (int j = 0; j < n; j++) {
            if (bitmask & (1 << j)) {
                bits_on++;
                if (x/lcm < s[j]/gcd(lcm, s[j])) {
                    lcm = x+1;
                    break;
                }
                lcm *= s[j]/gcd(lcm, s[j]);
            }
        }
        ans += ((bits_on&1)? x/lcm : - x/lcm);
    }

    return ans;  
}

ll divisible_numbers(ll n, ll m, const vector<ll> &s) {
    ll upto_n = divisible_numbers(n-1, s);
    ll upto_m = divisible_numbers(m, s);
    return upto_m - upto_n;
}

int main() {
    ll n, m, a, d;
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> m >> a >> d;

        ll total = m - n + 1;
        
        ll to_exclude = 0;
        vector<ll> subsets;
        subsets.pb(a);
        subsets.pb(a+d);
        subsets.pb(a+2*d);
        subsets.pb(a+3*d);
        subsets.pb(a+4*d);

        ll ans = total - divisible_numbers(n,m,subsets);

        cout << ans << "\n";
    }
    return 0;
}