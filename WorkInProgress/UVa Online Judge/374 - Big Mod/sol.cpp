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
#define all(x) (x).begin(), (x).end()
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

template<typename T>
vector<T> make_unique(vector<T> v) {
    sort(all(v));
    return v.resize(unique(all(v)) - v.begin());
}

int nxt() {
    int x;
    cin >> x;
    return x;
}


int XMOV[4] = {0, 0, 1, -1};
int YMOV[4] = {1, -1, 0, 0};

class ModularArithmetic {
    ll mod;

    ModularArithmetic(ll _mod): mod(_mod) {};

public: 
    // a*b % mod = ((a%mod) * (b%mod)) % mod
    // O(1)
    static ll mult(ll a, ll b, ll m){
        return ((a%m) * (b%m)) % m;
    }

    ll mult(ll a, ll b) {
        return ((a%mod) * (b%mod)) % mod;
    }

    // a^b % mod
    // O(log(b))
    static ll pow(ll a, ll b, ll m) {
        if (b == 0){
            return 1;
        }
        else if (b % 2 == 0){
            return mult(pow(a,b/2,m), pow(a,b/2,m), m);
        }
        else{
            return mult(pow(a,b-1,m), a, m);
        }
    }

    ll pow(ll a, ll b){
        if (b == 0){
            return 1;
        }
        else if (b % 2 == 0){
            return mult(pow(a,b/2), pow(a, b/2));
        }
        else{
            return mult(pow(a, b-1), a);
        }
    }
};

//#############################
const int MAXN = 1000005;

int main() {
    fastIO();

    ll b,p,m;
    while(cin >> b){
        cin >> p >> m;
        ll ans = ModularArithmetic::pow(b,p,m);
        cout << ans << endl;
    }
    return 0;
}