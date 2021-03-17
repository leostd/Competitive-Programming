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
typedef pair<double, double> pdd;
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
int n, l;

bool intersect(pdd a, pdd b) {
    double x = max(a.first, b.first);
    double y = min(a.second, b.second);

    return x <= y;
}

bool f(double mid, vector<ll> &lg){
    for(int i = 1; i < lg.size()-1; i++){
        pdd a = mp(lg[i-1]-mid, lg[i-1]+mid);
        pdd b = mp(lg[i+1]-mid, lg[i+1]+mid);
        pdd c = mp(lg[i]-mid, lg[i]+mid);
        if (!intersect(a, c) || !intersect(c, b))
            return false;
    }

    pdd a = mp(lg[0]-mid, lg[0]+mid);
    pdd b = mp(lg[n-1]-mid, lg[n-1]+mid);
    // cout << to_string(a) << " " << to_string(b) << endl;
    // cout << mid << endl; 
    // cout << intersect(a, mp(0,0)) << " " << intersect(b, mp(l,l)) << endl;
    if (lg.size() == 2)
        return intersect(a, mp(0,0)) && intersect(b, mp(l,l)) && intersect(a, b); 
    return intersect(a, mp(0,0)) && intersect(b, mp(l,l));
}

int main() {
    n = nxt(), l = nxt();
    // cout << n << " " << l << endl;
    vector<ll> lg(n, 0);
    generate(all(lg), nxt);
    sort(all(lg));
    double lf = 0, r = l, mid;
    for(int i = 0; i < 50; i++) {
        mid = (r+lf)/2;
        if (f(mid, lg))
            r = mid;
        else
            lf = mid;
        
    }
    cout << setprecision(10) << fixed;
    cout << lf << endl;
    return 0;
}