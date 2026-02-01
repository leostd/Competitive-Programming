#pragma GCC diagnostic ignored "-Wunused-const-variable"

#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define mt make_tuple
#define pb push_back
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

template<typename A, typename B, typename C>
string to_string(tuple<A, B, C> t); 


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
 
const int dx[6] = {0, 0, 1, -1, 0, 0};
const int dy[6] = {1, -1, 0, 0, 0, 0};
const int dz[6] = {0, 0, 0, 0, 1, -1};
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

int n, m; // sizes
vector<vector<int>> g; //graph, grid
map<iii, int> freq;
set<iii> aux;
set<iii> cubes;

vector<iii> genCube(int cx, int cy, int cz) {
    cx *= 2;
    cy *= 2;
    cz *= 2;
    aux.insert(mt(cx+1, cy+1, cz-1));
    aux.insert(mt(cx+1, cy-1, cz-1));
    aux.insert(mt(cx-1, cy+1, cz-1));
    aux.insert(mt(cx-1, cy-1, cz-1));
    aux.insert(mt(cx+1, cy+1, cz+1));
    aux.insert(mt(cx+1, cy-1, cz+1));
    aux.insert(mt(cx-1, cy+1, cz+1));
    aux.insert(mt(cx-1, cy-1, cz+1)); 
    vector<iii>  cube(all(aux));
    return cube;
}

//vector<iii> genCube(int x, int y, int z) {
//    vector<iii> cube;
//    cube.pb(mt(x,y,z));
//    cube.pb(mt(x-1, y, z));
//    cube.pb(mt(x, y-1, z));
//    cube.pb(mt(x-1, y-1, z));
//    cube.pb(mt(x, y, z+1));
//    cube.pb(mt(x-1, y, z+1));
//    cube.pb(mt(x, y-1, z+1));
//    cube.pb(mt(x-1, y-1, z+1));
//
//    return cube;
//}

void countFaces(int x, int y, int z) {
    x *= 2, y *=2, z *= 2;
    freq[mt(x+1, y, z)]++;
    freq[mt(x-1, y, z)]++;
    freq[mt(x, y+1, z)]++;
    freq[mt(x, y-1, z)]++;
    freq[mt(x, y, z+1)]++;
    freq[mt(x, y, z-1)]++;
}

const int MAX = 60;
const int MIN = -MAX;
bool ok(int x, int y, int z) {
    return x >= MIN && x <= MAX && y >= MIN && y <= MAX && z >= MIN && z <= MAX;
}

vector<iii> isLava(int x, int y, int z) {
    vector<iii> ret;
    forn(i, 6) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        int nz = z + dz[i];
        iii b = mt(nx, ny, nz);
        if (freq.count(b) && freq[b] == 1)
            ret.pb(b);
    }

    return ret;
}

ll surface() {
    set<iii> surface;
    queue<iii> q;
    q.push(mt(MAX, MAX, MAX));
    set<iii> vis;
    vis.insert(mt(MAX, MAX, MAX));
    ll ret = 0;
    while(!q.empty()) {
        iii a = q.front();
        //dbg(a);
        q.pop();
        int x, y, z;
        tie(x,y,z) = a;
        forn(i, 6) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            iii b = mt(nx, ny, nz);
            if (ok(nx, ny, nz) && !vis.count(b)) {
                //vector<iii> lava = isLava(nx, ny, nz);
                //if (!lava.empty()){
                //    for(auto l : lava) surface.insert(l);
                //} else if (!freq.count(b)){
                //    vis.insert(b);
                //    q.push(b);
                //} else {
                //    dbg(x, y, z);
                //    dbg(nx, ny, nz);
                //    dbg("here is one culprit!");
                //}
                if (cubes.count(b)) {
                    ret++;
                    surface.insert(b);
                } else {
                    q.push(b);
                    vis.insert(b);
                }
            }
        }
    }

    return ret;
}

int main() {
    fastIO(); 
    int x,y,z;
    while(cin >> x >> y >> z) {
        //vector<iii> cube = genCube(x,y,z);
        cubes.insert(mt(x,y,z));
        dbg(genCube(x,y,z));
        countFaces(x,y,z);
    }
    dbg(freq);
    ll ans = surface();
    //for(auto x : freq) {
    //    if (x.snd > 1) continue;
    //    ans++;
    //}
    //dbg(freq);
    cout << ans << endl;
    vector<iii> aa = isLava(5,3,5);
    dbg(aa);
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

