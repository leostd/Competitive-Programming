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
const int MAXN = 100005;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        set<int> k[MAXN];
        set<int> s;
        int m, x;
        REP(i, n) {
            cin >> m;
            s.insert(i+1);
            REP(j, m)
                cin >> x, k[i].insert(x);
        }

        // cout << to_string(s) << endl;
        int aux = -1;
        REP(i, n){
            bool flag = false;
            // cout << "k[i]: " << to_string(k[i].) << endl;
            // cout << "i: " <<k[i].empty() << endl;
            while(!k[i].empty()){
                // cout << "k[i]: " << k[i].top() << endl;
                auto it = k[i].lower_bound(*s.begin());
                if (!s.empty() && s.count((k[i].top()))){
                    s.erase(k[i].top());
                    k[i].erase(it);
                    flag = true;
                    break;
                }
                k[i].pop();
            }
            // cout << "s: " <<to_string(s) << endl;
            if (!flag && aux == -1)
                aux = i+1;
        }

        if (!s.empty()){
            cout << "IMPROVE\n";
            cout << aux << " " << *s.begin() << endl;
        }
        else {
            cout << "OPTIMAL\n";
        }

    }   
    return 0;
}