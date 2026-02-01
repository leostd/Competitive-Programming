/*
    think first, always - c,g,a, alg - r,s,iag?,iabs?
*/

#pragma GCC diagnostic ignored "-Wunused-const-variable"
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

#define mp make_pair
#define pb push_back
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
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

template<typename T> inline T abs(T a){ return ((a < 0) ? -a : a); }
template<typename T> inline T sqr(T a){ return a * a; }
template<class T> T gcd(T a, T b) { return a ? gcd (b % a, a) : b; }
template<class T> T lcm(T a, T b) { return a / gcd (a, b) * b; }
template<class T> T sign(T a) { return a > 0 ? 1 : (a < 0 ? -1 : 0); }

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

void dbg() { cout << endl; }
template <typename Head, typename... Tail>
void dbg(Head H, Tail... T) {
    cout << " " << to_string(H);
    dbg(T...);
}

#ifdef DEBUG
#define dbg(...) cout << "(" << #__VA_ARGS__ << "):", dbg(__VA_ARGS__)
#else
#define dbg(...)
#endif

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

const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};
const int dxKn[8] = {-2, -1, 1, 2,  2,  1, -1, -2};
const int dyKn[8] = { 1,  2, 2, 1, -1, -2, -2, -1};
const int dxK[8] = {0, 0, 1, -1, 1, 1, -1, -1};
const int dyK[8] = {1, -1, 0, 0, 1, -1, 1, -1};

const int MOD = int(1e9) + 7;
const int INF = int(1e9) + 100;
const ll INF64 = 2e18;
const ld PI = ld(3.1415926535897932384626433832795);
const ld e = ld(2.7182818284590452353602874713527);
const ld EPS = 1e-9;

//#############################
const int MAXN = 1000005;

void replaceMatching(string p, string &s) {
    int i=0;
    do {
        i = s.find(p, i);
        if (i == string::npos)
            break;

        s[i] = '2'; // matched closing bracket/parenthesis/whatever
        s[i+1] = '0'; // matched opening ^
    }while (i < s.size());
}

bool match(char o, char c){
    bool b = (o == '{' && c == '}');
    bool p = (o == '(' && c == ')');
    bool sb = (o == '[' && c == ']');
    bool ab = (o == '<' && c == '>');

    return b || p || sb || ab;
}

void process(int l, int r, string &s){
    while(l-1 >= 0 && r < s.size() && match(s[l-1], s[r+1])){
        s[l-1] = '2', s[r+1] = '0';
    }
}

void solve() {
    string s;
    cin >> s;

    replaceMatching("()", s);
    dbg(s);
    replaceMatching("{}", s);
    dbg(s);
    replaceMatching("[]", s);
    dbg(s);
    replaceMatching("<>", s);
    dbg(s);

    vector<pii> matched;
    for(int i = 0; i < s.size(); i++){
        if (s[i] == '2')
            matched.pb(mp(i, i+1));
    }

    for(int i = 0; i < matched.size(); i++) {
        process(matched[i].fst, matched[i].snd, s);
    }

    dbg(s);

    vector<int> aux(s.size(), 0);
    for(int i = 0;i < s.size(); i++) {
        if (s[i] == '2') aux[i] = 2;
        else aux[i] = 0;
    }

    vector<int> rpf(s.size(), 0);
    rpf[s.size()-1] = (s[s.size()-1] != '0' ? -1 : 0);
    for(int i = s.size()-2; i >= 0; i--){
        if (s[i] != '0' && s[i] != '2'){
            rpf[i] = -1;
            continue;
        }
        if (aux[i] > 0){
            rpf[i] = aux[i];
            // if (rpf[i+1] != 0)
            //     rpf[i] += rpf[i+1];
        }
    }


    vector<int> mx(s.size(), 0);
    int cur = 0;
    for(int i = s.size()-2; i >= 0; i--) {
        if (rpf[i] == -1){
            cur = 0;
            mx[i] = mx[i+1];
        } else if (rpf[i] == 0) {
            mx[i] = 0;
        } else {
            cur += rpf[i];
            mx[i] = max(mx[i+1], cur);
        }
    }



    dbg(rpf);
    dbg(mx);

    for(auto x : mx){
        cout << x << endl;
    }

}

int main() {
    fastIO(); 
    int t = nxt();
    int cs = 1;
    while(t--) {
        cout << "Case " << cs++ << ":" << endl;
        solve();
    }
    return 0;
}