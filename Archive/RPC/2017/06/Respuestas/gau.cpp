//marico el que lo lea
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
using namespace std;

#define FOR(i,f,t) for(int i=f; i<t; i++)
#define FORR(i,f,t) for(int i=f; i>t; i--)
#define ms(obj, val) memset(obj, val, sizeof(obj))
#define ms2(obj, val, sz) memset(obj, val, sizeof(obj[0])*sz)
#define pb push_back
#define ri(x) scanf("%d",&x)
#define rl(x) scanf("%lld",&x)
#define rii(x,y) ri(x), ri(y)

#define fst first
#define snd second

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;

const int MAXN = 502;

int M1[MAXN][MAXN], M[MAXN][MAXN], N;
int sig[MAXN];

int main(){
	int TC; ri(TC);
	while(TC--){
		ri(N);
		FOR(i,0,N) FOR(j,0,N) ri(M1[i][j]);
		FOR(i,0,N) ri(sig[i]);
		FOR(i,0,N) FOR(j,0,N) M[i][j] = M1[sig[i]][sig[j]];
		ll ans = 0;
		FORR(k,N-1,-1){
			FOR(i,0,N) FOR(j,0,N){
				M[i][j] = min(M[i][j], M[i][k] + M[k][j]);
				if(i>=k && j>=k) ans += M[i][j];
			}
		}
		printf("%lld\n",ans);
	}
}