#pragma GCC diagnostic ignored "-Wunused-const-variable"

#ifdef MAC
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
#else
#include <bits/stdc++.h>
#endif
 
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

// int n, m; // sizes
vector<vector<int>> g; //graph, grid

class Blocks {
public:
    int n;
    map<int, int> blockToPile;
    vector<deque<int>> pile;
    
    Blocks(int _n) {
        n = _n;
        pile = vector<deque<int>>(n, deque<int>());
        forn(i, n){
            pile[i].pb(i);
            // dbg(pile[i]);
            blockToPile[i] = i;
        }
        // dbg(n);
        // dbg(blockToPile);
    }

    void pileOver(int a, int b) {
        moveBatch(a, b);
    }

    void pileOnto(int a, int b) {
        returnToInit(b);
        moveBatch(a, b);
    }

    void moveOver(int a, int b) {
        int x = blockToPile[a];
        int y = blockToPile[b];
        returnToInit(a);
        pile[y].push_back(a);
        pile[x].pop_back();
        blockToPile[a] = y;
    }

    void moveOnto(int a, int b) {
        int x = blockToPile[a];
        int y = blockToPile[b];
        dbg(pile[x]);
        dbg(pile[y]);
        returnToInit(a);
        returnToInit(b);
        pile[y].push_back(a);
        blockToPile[a] = y;
        pile[x].pop_back();
        dbg(pile[x]);
        dbg(pile[y]);
    }

    void returnToInit(int x) {
        deque<int> &dq = pile[blockToPile[x]];
        // printPile(blockToPile[x]);
        dbg(pile[blockToPile[x]]);
        dbg(x, blockToPile[x]);
        while(dq.back() != x){
            int a = dq.back();
            pile[a].push_back(a);
            dq.pop_back();
            blockToPile[a] = a;
        }
    }

    void moveBatch(int a, int b) {
        int x = blockToPile[a];
        int y = blockToPile[b];
        dbg(pile[x]);
        dbg(pile[y]);
        deque<int> aux;
        while(pile[x].back() != a) {
            aux.pb(pile[x].back());
            pile[x].pop_back();
        }
        aux.pb(pile[x].back());
        pile[x].pop_back();
        dbg(aux);
        while(!aux.empty()){
            blockToPile[aux.back()] = y;
            pile[y].pb(aux.back());
            aux.pop_back();
        }
    }

    // void printPile(int i) {
    //     int sz = pile[i].size();
    //     forn(i, sz) {
    //         int a = pile[i].front();
    //         pile[i].pop_front();
    //         pile[i].push_back(a);
    //         cout << a << " ";
    //     }
    //     cout << endl;
    // }
};
 
int main() {
    fastIO();
    int n = nxt();
    dbg(n);
    Blocks blocks(n);
    while(true){
        string s;
        getline(cin, s);
        stringstream ss(s);
        string command, type;
        int a, b;
        cin >> command;
        if (command == "quit")
            break;
        cin >> a >> type >> b;
        dbg(command, a, type, b);
        if (a == b || blocks.blockToPile[a] == blocks.blockToPile[b])
            continue;

        if (command == "move") {
            if (type == "over") blocks.moveOver(a, b);
            else blocks.moveOnto(a, b);
        } else {
            if (type == "over") blocks.pileOver(a, b);
            else blocks.pileOnto(a, b);
        }
    }
    forn(i, n){
        cout << i << ":";
        int sz = blocks.pile[i].size();
        // dbg(sz);
        forn(j, sz) {
            cout << " ";
            cout << blocks.pile[i].front();
            // blocks.pile[i].pb(blocks.pile[i].front());
            blocks.pile[i].pop_front();
        }
        cout << endl;
        // dbg(blocks.pile[i]);
    }
    return 0;
}

/*
    RECALL CORNER CASES - e.g. n = 1, n = 0
    WRITE SOME STUFF

    think first, always - 
    1. concretely
    2. graphically 
    3. abstractly
    4. algebraically
*/