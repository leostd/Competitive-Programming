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

//#############################
const int MAXN = 1000005;
vector<vector<int>> a;
int n,m,x;
ll ans;
bool mark[13];

bool check(vector<ll> &v) {
    for(int i = 0; i < v.size(); i++)
        if (v[i] < x )
            return false;
    
    return true;
}

int main() {
    n = nxt(), m = nxt(), x = nxt();
    a = vector<vector<int>>(n, vector<int>(m+1, 0));
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m+1; j++){
            cin >> a[i][j];
        }
    }
    memset(mark, 0, sizeof(mark));
    ans = 0x3f3f3f3f;
    for(int bitmask = 0; bitmask < (1 << n); bitmask++){
        vector<ll> skills(m, 0);
        ll sum = 0;
        for(int bit = 0; bit < n; bit++){
            if ((1 << bit) & bitmask){
                for(int i = 0;i < m; i++){
                    skills[i]+= a[bit][i+1];
                    // cout << a[bit][0] << endl;
                }
                sum += a[bit][0];
            }
        }
        if (check(skills)){
            // cout << "x: " << x << " " << to_string(skills) << " " << sum << " " << bitset<3>(bitmask) << endl;
            ans = min(ans, sum);
        }
    }
    cout << (ans == 0x3f3f3f3f? -1 : ans) << endl;
    return 0;
}