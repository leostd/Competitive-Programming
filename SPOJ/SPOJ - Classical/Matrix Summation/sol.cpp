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
#define lsb(x) ((x)&(-x))

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

ll bit[1050][1050];
int n;

void update(int x, int y, int val) {
    for (int i = x; i <= n; i += lsb(i)) {
        for (int j = y; j <= n; j += lsb(j)) {
            bit[i][j] += val;
        }
    }
}

ll sum (int x, int y) {
    ll s = 0;
    for (int i = x; i > 0; i -= lsb(i)) {
        for (int j = y; j > 0; j -= lsb(j)) {
            s += bit[i][j];
        }
    }
    return s;
}

int main() {
    int t;

    cin >> t;
    while(t--) {
        fastIO();
        string op;
        int x,y,val;

        cin >> n;
        memset(bit, 0, sizeof(bit));
        do{
            cin >> op;

            if (op == "SET"){
                cin >> x >> y >> val;
                update(x+1,y+1,val);
            }
            else if (op == "SUM"){
                int x2, y2;
                cin >> x >> y >> x2 >> y2;
                ll ans = sum(x2+1, y2+1) - sum(x+1, y+1);
                cout << ans << "\n";
                // cout << "SUM";
            }
        }while(op != "END");
    }
    return 0;
}