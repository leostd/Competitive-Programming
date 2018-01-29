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

#define N 5005

///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////

int main(){
    int n;
    char str[N], rstr[N];
    int memo[2][N];
    scanf("%d", &n);
    scanf("\n%s", str);
    strcpy(rstr, str);
    reverse(rstr, rstr+n);
    memset(memo, 0, sizeof(memo));
    FOR(i,0,n){
        FOR(j,0,n){
            if (rstr[i] == str[j])
                memo[1][j] = (j-1 >= 0)? memo[0][j-1] + 1: 1;
            else
                memo[1][j] = ((j-1 >= 0) ? max(memo[1][j-1], memo[0][j]) : 0);
        }
        FOR(j,0,n)
            memo[0][j] = memo[1][j];
    }
    printf("%d\n", n-memo[1][n-1]);
    return 0;
}
