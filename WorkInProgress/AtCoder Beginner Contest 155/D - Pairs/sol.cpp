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

ll div_floor(ll a, ll b) {
	return a / b - (((a ^ b) < 0) and a % b);
}
ll div_ceil(ll a, ll b) {
	return a / b + (((a ^ b) >= 0) and a % b);
}


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

//#############################
const int MAXN = 1000005;
ll n, k, x;
vector<ll> a;
bool isNeg;
int neg, pos, zero;
vector<ll> poss, negs;

ll f(ll x) {
    ll count = 0;
    for(int i = 0; i < n; i++){
        if (a[i] == 0 && x >= 0){
                count += n-1;
        }
        else if(a[i] > 0) {
            // a[i] * z <= x ==> z <= x / a[i]
            ll z = int(upper_bound(a.begin(), a.end(), div_floor(x, a[i])) - a.begin());
            if (z > i)
                count += z - 1;
            else
                count += z;
        } else if (a[i] < 0) {
            // a[i] * z <= x ==> z >= x / a[i]

            ll z = int(lower_bound(a.begin(), a.end(), div_ceil(x, a[i])) - a.begin());

            if (z <= i)
                count += n - z -1;
            else
                count += n - z;
        }
    }


    return count / 2;
}

int main() {
    fastIO();
    cin >> n >> k;
    a = vector<ll>(n, 0);
    neg = pos = zero = 0;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    ll l(-1e18-1), r = (1e18+1);
    while (abs(r - l) >= 1) {
        ll mid = l + (r - l) / 2;
        ll guess = f(mid);
        if (guess >= k)
            r = mid;
        else
            l = mid+1;
    }

    cout << r << endl;

    return 0;
}