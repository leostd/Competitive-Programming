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
const int MAXN = 1000005;
struct node {
    public:
        bitset<26> bitmask;
    node() {
        bitmask = 0;
    }
};

node tree[20*MAXN];
string s;
int left(int x){ return x << 1;}
int right(int x) { return (x << 1) + 1;}

void _build(int x, int l, int r) {
    if (l == r) {
        int bit = s[l] - 'a';
        tree[x].bitmask = (1 << bit);
    }
    else if(l < r) {
        int mid = (l + r) / 2;

        _build(left(x), l, mid);
        _build(right(x), mid+1, r);
        tree[x].bitmask = tree[left(x)].bitmask | tree[right(x)].bitmask; 
    }
}

void build() {
    int n = s.size();
    int l = 0, r = n-1;
    _build(1, l, r);
}

bitset<26> _query(int x, int rl, int rr, int l, int r) {
    if (l > r)
        return 0;
    if (rl == l && rr == r)
        return tree[x].bitmask;
    else {
        int mid = (rl + rr) / 2;
        bitset<26> a = _query(left(x), rl, mid, l, min(r, mid));
        bitset<26> b = _query(right(x), mid+1, rr, max(l, mid+1), r);
        return b | a;
        
    }
}

void _update(int v, int l, int r, int idx, char x, char old) {
    if (l == r){
        tree[v].bitmask ^= (1 << (old - 'a')); 
        tree[v].bitmask |= (1 << (x - 'a'));
    }
    else if(l < r){
        int mid = (l + r) / 2;
        if (idx <= mid)
            _update(left(v), l, mid, idx, x, old);
        else
            _update(right(v), mid+1, r, idx, x, old);
        tree[v].bitmask = tree[left(v)].bitmask | tree[right(v)].bitmask;
    }
}

void update(int idx, char x, char old) {
    _update(1, 0, s.size()-1, idx, x, old);
}

bitset<26> query(int l, int r) {
    return _query(1, 0, s.size()-1, l, r);
}

int main() {
    int n, q;

    cin >> n >> s >> q;

    build();
    int type, l, r, idx;
    char x;
    REP(i, q) {
        cin >> type;
        if (type == 1){
            cin >> idx >> x;
            update(idx, x, s[i-1]);
        }else {
            cin >> l >> r;
            cout << (query(l-1, r-1)).count() << endl;
        }
    }
    return 0;
}