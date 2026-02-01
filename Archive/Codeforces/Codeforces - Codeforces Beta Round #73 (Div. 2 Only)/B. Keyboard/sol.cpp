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

int main() {
    fastIO();
    int n = nxt(), m = nxt(), x = nxt();
    string l;
    vector<vector<char>> k(n, vector<char>(m, '1'));
    map<char, vector<pii>> idx;
    // cout << to_string(idx) << endl;
    // cout << to_string(k)<< endl;
    for(int i = 0; i < n; i++) {
        cin >> l;
        for(int j = 0; j < m; j++){
            k[i][j] = l[j];
            idx[k[i][j]].pb(mp(i,j));
        }
    }

    int md = 0x3f3f3f3f;
    map<char, double> aux;
    for(int i = 0; i < k.size(); i++){
        for(int j = 0; j < k[i].size();j++){
            if (aux.count(k[i][j])==0)
                aux[k[i][j]] = md;
            for(int w = 0; w < idx['S'].size(); w++){
                aux[k[i][j]] = min(aux[k[i][j]], sqrt(sqr(idx['S'][w].fst - i) + sqr(idx['S'][w].snd - j)));

            }
        }
    }
    int q = nxt();
    // cout << q << endl;
    string txt;
    cin >> txt;
    ll ans = 0;
    // cout << txt << endl;
    // cout << to_string(idx['S']) << " " << idx.count('S') << endl;
    // cout << (isupper(txt[0]) && idx.count('S') == 0) << endl; 
    // cout << isupper(txt[0]) << "  " << (idx.count('S') == 0) << endl; 
    for (int i = 0; i < txt.size(); i++) {
        if ((isupper(txt[i]) && idx.count(tolower(txt[i]))== 0) || (isupper(txt[i]) && idx['S'].size() == 0) || (islower(txt[i]) && idx.count(txt[i]) == 0)) {
            cout << -1 << endl;
            return 0;
        }
        else if(isupper(txt[i])){
            // debug_out(aux[tolower(txt[i])]);
            ans += (aux[tolower(txt[i])] > (double)x);
        }
    }
    cout << ans << endl;
    return 0;
}