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

bool check (vector<int> &a) {
    int n = a.size();
    vector<int> diff;
    for(int i = 0; i < n-1; i++) {
        diff.pb(abs(a[i]-a[i+1]));
    }
    if (is_sorted(all(diff))){
        cout << "Diff: " << to_string(diff) << endl;
    }
    return is_sorted(all(diff));
}

void force() {
    int n;

    // cin >> n;
    for(int i = 1; i <= 5; i++){
        vector<int> a(i);
        generate(all(a), rand);   
        if(check(a))
            cout << to_string(a) << endl;
        while(next_permutation(all(a))){
            if (check(a))
                cout << to_string(a) << endl;
        }
        cout << "---" << endl;
    }
    // REP(i,n) cin >> a[i];

}

void solve() {
    ll n;
    cin >> n;

    vector<ll> a(n);
    generate(all(a), nxt);

    sort(all(a));

    ll cur, min_diff = 0x3f3f3f3f;
    REP(i, n-1){
        if (abs(a[i]-a[i+1]) < min_diff){
            min_diff = abs(a[i]-a[i+1]);
            cur = i;
        }
    }

    cur = n/2;
    vector<ll> ans;
    ll prev = cur-1, next = cur + 1;
    ans.pb(a[cur]);
    int cur_diff = 0;
    int i = 1;
    while(cur + i < n || cur - i >= 0){
        if (cur - i >= 0)
            ans.pb(a[cur-i]);
        if (cur + i < n)
            ans.pb(a[cur+i]);
        i++;
    }
    
    REP(i, n)
        cout << ans[i] << " ";
    cout << "\n";
}   

int main() {

    int t;
    cin >> t; 

    while(t--) {
        solve();
    }
    return 0;
}