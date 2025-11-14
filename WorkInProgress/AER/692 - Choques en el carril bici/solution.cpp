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
typedef long double ld;
typedef pair<ld, ll> pld;

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
 

int n, m; // sizes
const double EPS = 1e-10;
vector<pld> posId;
vector<ll> vel;

bool f(ld x) {
    vector<pld> aux = posId;
    for(auto &y : aux) {
        y.fst = y.fst + (ld)vel[y.snd]*x;
    }

    sort(all(aux));
    for1(i, n) {
        if (abs(aux[i].fst - aux[i-1].fst) < EPS) return true;
    }
    forn(i, n) {
        if (aux[i].snd != posId[i].snd) return true;
    }

    return false;
}

void solve() {
    ll x, v;
    posId.clear();
    vel.assign(n, 0);
    forn(i, n) {
        cin >> x >> v;
        vel[i] = v;
        posId.pb(mp(x, i));
    }
    sort(all(posId));
    if(n == 1) {
        cout << "SIN COLISION"  << endl;
        return;
    }
    for1(i, n) {
        if (abs(posId[i].fst - posId[i].snd) < EPS) {
            cout << 0 << endl;
            return;
        }
    }
    
    ld l = 0, r = 1e10;
    ld mid;
    ld prevl, prevr;
    forn(i, 100) {
        mid = (l+r) / (ld)2.0;
        prevl = l;
        prevr = r;
        dbg(mid);
        if (f(mid))
            r = mid;
        else
            l = mid;
        if (abs(l-prevl) < EPS && abs(r-prevr) < EPS) break;
    }
    ld ans = (f(l) ? l : r);
    if (!f(ans)) {
        cout << "SIN COLISION" << endl;
    } else {
        cout << floor(ans) << endl;
    }
}

signed main() {
    fastIO();
    while(cin >> n, n > 0) {
        solve();
    }
    return 0;
}
