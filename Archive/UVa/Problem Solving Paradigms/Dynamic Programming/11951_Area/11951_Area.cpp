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
#include <limits>
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

int n, m, k;
ll p[110][110];

int main(){
    int t;
    scan(t);
    FOR(tc, 1, t+1){
        scan(n,m,k);
        FOR(i,0,n)
            FOR(j,0,m)
                scan(p[i][j]);
        ll sum[110];
        deque<ll> dq;
        ll acum = 0, min_cost = numeric_limits<long long>::max();
        int mx_size = -1;
        FOR(s,0,m){
            memset(sum, 0, sizeof(sum));
            FOR(e,s,m){
                FOR(i,0,n)
                    sum[i] += p[i][e];
                dq.clear();
                acum = 0;
                FOR(i,0,n){
                    acum += sum[i];
                    dq.push_back(sum[i]);
                    while(k - acum < 0){
                        acum -= dq.front();
                        dq.pop_front();
                    }
                    if ((int)dq.size() * (e - s + 1) > mx_size){
                        min_cost = acum;
                        mx_size = max(mx_size, (int)dq.size() * (e-s+1));
                    }
                    else if((int)dq.size() * (e - s + 1) == mx_size)
                        min_cost = min(min_cost, acum);
                }
            }
        }
        printf("Case #%d: %d %lld\n", tc, mx_size, min_cost);
    }
    return 0;

}
