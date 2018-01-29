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

typedef pair<int,int> ii;
typedef pair<char, ii> cii;
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

char str[110];
int memo[110][110], n;
cii p[110][110];
deque<char> dq;

void outp(int i, int j){
    if (i > j)
        return;
    if (i == j){
        dq.push_back(str[i]);
        return;
    }
    if (str[i] == str[j]) {
        outp(i + 1, j - 1);
        dq.push_back(str[j]);
        dq.push_front(str[i]);
    }
    else{
        if (memo[i][j-1] < memo[i+1][j] || (memo[i+1][j] == memo[i][j-1] && str[j] < str[i])){
            outp(i, j-1);
            dq.push_back(str[j]);
            dq.push_front(str[j]);
        }
        else{
            outp(i+1,j);
            dq.push_front(str[i]);
            dq.push_back(str[i]);
        }
    }
}

int dp(int i, int j){
    if (i > j)
        return 0;
    if (memo[i][j] != -1)
        return memo[i][j];
    if (str[i] == str[j])
        return memo[i][j] = dp(i+1, j-1);
    else{
        int a = dp(i, j-1) + 1;
        int b = dp(i+1,  j) + 1;
        if (a < b)
            return memo[i][j] = a;
        else
            return memo[i][j] = b;
    }
}

int main(){
    int t;
    scan(t);
    FOR(i,1,t+1){
        scan(str);
        memset(memo, -1, sizeof(memo));
        n = strlen(str);
        int ans = dp(0, strlen(str)-1);
        printf("Case %d: %d ", i, ans);
        dq.clear();
        outp(0, n-1);
        while(!dq.empty()){
            printf("%c", dq.front());
            dq.pop_front();
        }
        printf("\n");
    }
}
