#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL unsigned long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
inline void fastInt(int &a){
    char c;
    int s = 1;
    a = 0;
	while(true){
		c = getchar_unlocked();
		if(c=='-') s = -1;
		if(c>='0' && c<='9') break;
	}
	while(true){
		a = a*10 + c-'0';
		c = getchar_unlocked();
		if(c<'0' || c>'9') break;
	}
	a *= s;
}
bool mark[4][30][30];
LL memo[2][30][30];
int n, m;
LL dp(int d, int N, int M){
	if(N == 1 || M == 1) return 1;
	LL& ans = memo[d][N][M];
	if(mark[d][N][M]) return ans;
	mark[d][N][M] = true;
	ans = 0;
	if(d == 0){
		for(int i = 1; i <= N; i++){
			ans += dp(1, i, M - 1);
		}
	}else{
		for(int i =1; i <= M; i++){
			ans += dp(0, N - 1, i);
		}
	}
	return ans;
}
int main(){
	int t;
	fastInt(t);
	while(t--){
		fastInt(n); fastInt(m);
		memset(mark, false, sizeof(mark));
		printf("%lld\n", dp(0, n, m));
	}
	return 0;
}