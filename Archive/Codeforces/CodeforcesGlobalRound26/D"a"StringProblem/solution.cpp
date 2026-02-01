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
                       //
struct Hash {
    int P=1777831,MODS[2],PIS[2];
    vector<int> h[2],pi[2];
    Hash(string& s){
        MODS[0]=999727999;MODS[1]=1070777777;
        PIS[0]=212190789, PIS[1]=41113825; // inversa de P en MOD0 y MOD1
        fore(k,0,2)h[k].resize(s.size()+1),pi[k].resize(s.size()+1);
        fore(k,0,2){
            h[k][0]=0;pi[k][0]=1;
            ll p=1;
            fore(i,1,s.size()+1){
                h[k][i]=(h[k][i-1]+p*(s[i-1]-'a'))%MODS[k];
                pi[k][i]=(1LL*pi[k][i-1]*PIS[k])%MODS[k];
                p=(p*P)%MODS[k];
            }
        }
    }
    ll get(int l, int r){ // [s,e)
        ll h0=(h[0][r]-h[0][l]+MODS[0])%MODS[0];
        h0=(1LL*h0*pi[0][l])%MODS[0];
        ll h1=(h[1][r]-h[1][l]+MODS[1])%MODS[1];
        h1=(1LL*h1*pi[1][l])%MODS[1];
        return (h1<<32)|h0;
    }
};

void solve() {
    string s;
    cin >> s;
    n = sz(s);
    dbg(s);
    vector<int> nona(n+1, n);
    nfor(i, n) {
        if (s[i] != 'a') nona[i] = i;
        else nona[i] = nona[i+1];
    }

    dbg(nona);

    if (nona[0] == n) {
        cout << n-1 << endl;
        return;
    }

    ll ans = 0;
    Hash h(s);
    int i1 = nona[0];
    for(int len = 1; i1+len <= n; len++) {
        dbg("length of the string: ", len);
        int cur = i1+len; // next position to the right of the last letter of the candidate string
        int mn = i1;
        bool works = true;
        ll h0 = h.get(i1, cur);
        while(cur < n) {
            if (nona[cur] == n) break; // next non-a char does not exist
            int bt = nona[cur] - cur;
            mn = min(mn, bt); // unused 'a's between candidate strings
            cur += bt;
            if (cur+len > n || h0 != h.get(cur, cur+len)) {
                works = false;
                break;
            }
            if (len == 21) {
                dbg(h.get(cur, cur+len));
                dbg(h0);
                dbg(s.substr(cur, len));
                dbg(s.substr(i1, len));
            }
            cur += len;
        }
        if (works) {
            ans += mn+1;
            dbg(len);
        }
    }

    cout << ans << endl;

}
 
signed main() {
    fastIO(); 
    int t =nxt();
    while(t--) solve();
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

