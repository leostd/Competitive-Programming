//perreo a poca luz

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <assert.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void fastIO() {
    std::ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
}

#define EPS (1e-12)
#define FOR(i,f,t) for(int i=f; i<(int)t; i++)
#define FORR(i,f,t) for(int i=f; i>(int)t; i--)
#define FORE(i,c) for(auto i = (c).begin(); i != (c).end(); i++)
#define pb push_back
#define all(obj) obj.begin(), obj.end()
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)

#define fst first
#define snd second

template<typename T, typename U> inline void mnze(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void mxze(T &x, U y) { if(x < y) x = y; }

void _scan( int &x ) { scanf("%d",&x); }
void _scan( long long &x ) { scanf("%lld",&x); }
void _scan( double &x ) { scanf("%lf",&x); }
void _scan( long double &x ) { scanf("%Lf",&x); }
void _scan( char &x ) { scanf(" %c",&x); }
void _scan( char *x ) { scanf("%s",x); }
void scan() {}
template<typename T, typename... U>
void scan( T& head, U&... tail ) { _scan(head); scan(tail...);}

template<typename T> void _dbg(const char* sdbg, T h) { cerr<<sdbg<<"="<<h<<"\n"; }
template<typename T, typename... U> void _dbg(const char* sdbg, T h, U... t) {
    while(*sdbg != ',')cerr<<*sdbg++; cerr<<"="<<h<<","; _dbg(sdbg+1, t...);
}

#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#define debugv(x) {{cerr <<#x <<" = "; FORE(_i, (x)) cerr <<*_i <<", "; cerr <<"\n"; }}
#define debuga(x, sz) {{cerr <<#x <<" = "; FOR(_i, 0, sz) cerr << x[_i] <<", "; cerr <<"\n"; }}
#else
#define debug(...) (__VA_ARGS__)
#define debugv(x)
#define debuga(x, sz)
#define cerr if(0)cout
#endif

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

#define N 200010
#define MAXLOG 20
using namespace std;

typedef pair<ll, ll> ii;


ll p[N], dsu_size, par[N][MAXLOG], mx[N][MAXLOG], h[N];
vector<pair<ll, ii>> g, aux; // edges
vector<ii> tree[N];

int dsu_find(int x){
    if (p[x] == x)
        return x;
    return p[x] = dsu_find(p[x]);
}

void dsu_union(int x, int y){
    int rootx = dsu_find(x);
    int rooty = dsu_find(y);
    if (rootx != rooty){
        p[rooty] = rootx;
        dsu_size++;
    }
}

void dsu_init(int n){
    dsu_size = n;
    for(int i = 0; i <= n; i++)
        p[i] = i;
}

void binary_lifting_dfs(int v, int p, ll w=0){
    par[v][0] = p;
    mx[v][0] = w;
    if (p + 1) // if it's not the root
        h[v] = h[p] + 1;
    for (int i = 1; i < MAXLOG; i++){
        if (par[v][i-1]){
            par[v][i] = par[par[v][i-1]][i-1];
            mx[v][i] = max(mx[v][i-1], mx[par[v][i-1]][i-1]);
        }
    }
    for (auto u : tree[v])
        if (p - u.second)
            binary_lifting_dfs(u.second, v, u.first);
}

ll lca(int v, int u){
    if (h[v] < h[u])
        swap(v,u); // v is lower
    ll mxv = -1;
    for (int i = MAXLOG - 1; i >= 0; i--) {
        if (par[v][i]  && h[par[v][i]] >= h[u]){
            mxv = max(mxv, mx[v][i]);
            v = par[v][i];
        }

    }
    if (v==u)
        return mxv;
    for (int i = MAXLOG -1; i >= 0; i--)
        if(par[v][i] - par[u][i]){
            mxv = max(mxv, max(mx[v][i], mx[u][i]));
            v = par[v][i], u = par[u][i];
        }
    return max(mxv, max(mx[v][0], mx[u][0]));
}

int main(){
    int n,m;
    scanf("%d %d", &n, &m);
    dsu_init(n);
    ll mst_weight = 0, root = 1;
    if (m != 0){
        g.assign(m, pair<int, ii> (0x3f3f3f3f, ii(-1,-1)));
        for (int i = 0; i < m; i++){
            scanf("%lld %lld %lld", &g[i].second.first, &g[i].second.second, &g[i].first); // x y weight
        }
        aux = vector<pair<ll, ii>>(g.begin(), g.end());
        sort(g.begin(), g.end());
        for (int i = 0; i < m; i++){
            ll a = g[i].second.first, b = g[i].second.second, c = g[i].first;
            if (dsu_find(a) != dsu_find(b)){
                tree[a].push_back(ii(c, b));
                tree[b].push_back(ii(c, a));
                dsu_union(a, b);
                mst_weight += c;
            }
        }
        memset(par, -1, sizeof(par));
        memset(h, 0, sizeof(h));
        binary_lifting_dfs(root, root);
        ll a, b, x, ans;
        for (int i = 0; i < (int)aux.size(); i++){
            a = aux[i].second.first, b = aux[i].second.second;
            x = lca(a,b);
            ans = mst_weight - x + aux[i].first;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
