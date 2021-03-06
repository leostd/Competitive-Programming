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
#define endl "\n"

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
int KXMOV[8] = {};
int KYMOV[8] = {};
int FXMOV[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int FYMOV[8] = {1, -1, 0, 0, 1, -1, 1, -1};

//#############################
const int MAXN = 1000005;

double f(double p1, double p2, double a, double b) {
    return ((a*p2)/(b*p1) + 1.0);
}

int main() {
    fastIO();
    int n, m, k;
    vector<int> x,y,z;

    n = nxt();
    x = vector<int>(n, 0);
    generate(all(x), nxt);

    m = nxt();
    y = vector<int>(m, 0);
    generate(all(y), nxt);

    k = nxt();
    z = vector<int>(k, 0);
    generate(all(z), nxt);

    int a = nxt(), b = nxt();

    // debug_out(x);
    // debug_out(y);
    // debug_out(z);

    double ans = 0x3f3f3f3f;
    REP(j, y.size()){
            REP(l, z.size()){
                ans = min(ans, f(y[j], z[l], a, b));
            }
    }
    
    double max_r1 = -1.0;
    REP(i, x.size()){
        max_r1 = max((double)sqr(x[i]), max_r1);
    }

    ans = max_r1/ans;

    cout << setprecision(18) << fixed << sqrt(ans) << endl;
    return 0;
}