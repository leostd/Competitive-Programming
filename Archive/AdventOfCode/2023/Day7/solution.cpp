#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
#define sz(x) ((int)x.size())
#define forn(i, n) for(int i = 0; i < (int)(n); ++i)
#define for1(i, n) for(int i = 1; i < (int)(n); ++i)
#define nfor(i, n) for(int i = int(n) - 1; i >= 0; --i)
#define fore(i, l, r) for(int i = int(l); i < int(r); ++i)
#define correct(x, y, n, m) (0 <= x && x < n && 0 <= y && y < m)
#define all(x) (x).begin(), (x).end()
#define lsb(x) ((-x)&(x))
#define fst first
#define snd second
#define endl "\n"

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef tuple<int,int,int> iii;
typedef tuple<ll, ll, ll> lll;
typedef tuple<ld, ld, ld> ddd;

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

template<typename A, typename B>
string to_string(pair<A, B> p) { return "(" + to_string(p.first) + ", " + to_string(p.second) + ")"; }

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> t) { return "(" + to_string(get<0>(t)) + ", " + to_string(get<1>(t)) +  ", " + to_string(get<2>(t)) + ")"; }

template<typename A>
string to_string(priority_queue<A> pq) {
    bool first = true;
    string res = "{";
    int sz = pq.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(pq.top());
        pq.pop();
    }
    res += "}";
    return res;
}

template<typename A>
string to_string(queue<A> q) {
    bool first = true;
    string res = "{";
    int sz = q.size();
    forn(i, sz) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(q.front());
        q.pop();
    }
    res += "}";
    return res;

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
const string abc = "abcdefghijklmnopqrstuvwxyz";
//#############################
const int MAXN = 1000005;

int n, m; // sizes
vector<vector<int>> g; //graph, grid

struct hand {
    string h;
    ll bid;
    int type;
    hand() {bid = 0; type = 0; h = "";}
    hand(string _h, ll _bid) {bid = _bid; h = _h; type = 0;}
};

bool isHighCard(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;

    return sz(f) == sz(h);
}

bool isOnePair(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;
    bool flag1 = false, flag2 = true;
    for(auto x : f) {
        if (flag1) {
            flag2 = flag2 && x.snd == 1;
            continue;
        }
        if (x.snd == 2) {
            flag1 = true;
            continue;
        }
    }

    return flag1 && flag2;
}

bool isTwoPair(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;
    bool flag1 = false, flag2 = false;
    for(auto x : f) {
        if (flag1 && !flag2) {
            flag2 = x.snd == 2;
        } else if (!flag1){
            flag1 = x.snd == 2;
        }
    }

    return flag1 && flag2;
}

bool isThree(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;
    for(auto x: f) {
        if (x.snd == 3) return true;
    }
    return false;
}

bool isFullHouse(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;
    if (sz(f) > 2) return false;
    pair<char, int> a = *f.begin(), b = *f.rbegin();
    return a.snd == 3 || b.snd == 3;
}

bool isFour(string h) {
    map<char, int> f;
    for(auto x : h) f[x]++;
    if (sz(f) > 2) return false;
    pair<char, int> a = *f.begin(), b = *f.rbegin();
    return a.snd == 4 || b.snd == 4;
}

int getValue(char x) {
    if (x == 'A') return 20;
    if (x == 'K') return 19;
    if (x == 'Q') return 18;
    if (x == 'J') return 0;
    if (x == 'T') return 16;
    return x - '0';
}

bool cmp(hand a, hand b) {
    if (a.type != b.type) return a.type < b.type;
    vector<int> na(sz(a.h)), nb(sz(b.h));
    forn(i, sz(a.h)) {
        na[i] = getValue(a.h[i]);
        nb[i] = getValue(b.h[i]);
    }
    return na < nb;
}



int getType(string h) {
    if (any_of(all(h), [](char x){return x == 'J';})) {
        map<char, int> f;
        int mx = 0;
        for (auto x : h) {
            f[x]++;
            if (x != 'J') mx = max(mx, f[x]);
        }

        int aux = f['J'] + mx;

        if (aux == 5) return 7;
        if (aux == 4) return 6;
        if (mx == 2 && sz(f) == 3) return 5;
        if (aux == 3) return 4;
        if (aux == 2) return 2;
        
    } 
    if (all_of(all(h), [&h](char x){return x == h[0];})) return 7;
    if (isFour(h)) return 6;
    if (isFullHouse(h)) return 5;
    if (isThree(h)) return 4;
    if (isTwoPair(h)) return 3;
    if (isOnePair(h)) return 2;
    if (isHighCard(h)) return 1;
    return 0;
}

signed main() {
    fastIO();     
    vector<hand> hands;
    string h;
    ll bid;
    while(cin >> h >> bid) {
        hand hh(h, bid);
        hh.type = getType(h);
        dbg(hh.h, hh.bid, hh.type);
        hands.pb(hh);
    }

    sort(all(hands), cmp);
    ll ans = 0;
    forn(i, sz(hands)) {
        dbg(i, hands[i].h, hands[i].bid, hands[i].type);
        dbg(ans);
        ans += hands[i].bid * (ll)(i+1);
        dbg(i, ans, hands[i].bid * (i+1));
    }

    cout << ans << endl;
    
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

    Checklist:
    - I/O make sense?   - Exclusion/inclusion           - Is a known sequence?
    - Reverse           - Brute force approach          - DP
    - Sort input        - Greedy approach               - Split into cases: Even/odd cases
    - Check diagonals   - Divide and Conquer approach
*/

