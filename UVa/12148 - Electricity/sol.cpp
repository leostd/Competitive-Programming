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
int months[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool consecutive_dates(int d1, int m1, int y1, int d2, int m2, int y2) {
    // cout << d1 << " " << m1 << " " << y1 << " " << d2 << " " << m2 << " " << y2 << endl;
    d2--;
    if (d2 == 0) {
        m2--;
        if (m2 == 0) {
            y2--;
            m2 = 12;
        }
        bool isleap = (y2 % 4 == 0 && (y2 % 100 || y2 % 400));
        // cout << "leap: " << isleap << endl;
        d2 = months[m2];
        if (isleap && m2 == 2) {
            d2 = 29;
        }
    }
    // cout << (d1 == d2 && m1 == m2 && y1 == y2) << endl;
    return d1 == d2 && m1 == m2 && y1 == y2;
}

int main() {
    int n,d1,m1,y1,c1,d2,m2,y2,c2;
    bool first = true;
    while (cin >> n && n) {
        long long ans = 0;
        int days = 0;
        for (int i = 0; i < n; i++) {
            cin >> d2 >> m2 >> y2 >> c2;
            // cout << d2 << " " << m2 << " " << y2 << endl;
            if (consecutive_dates(d1,m1,y1,d2,m2,y2)) {
                days++;
                // cout << "c1: " << c1 << " " << c2 << endl;
                ans += (c2 - c1);
            }
            d1 = d2; m1 = m2; y1 = y2; c1 = c2;
        }
        cout << days << " " << ans << "\n";
    }
    return 0;
}