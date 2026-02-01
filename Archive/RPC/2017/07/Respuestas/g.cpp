#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL long long
#define pb push_back
#define pii pair<LL,LL>
#define mp make_pair
using namespace std;

/*
void solve(int count, char source, char destination, char intermediate){
	if(count == 1){
		printf("Move top disc from pole %c to pole %c\n", source, destination);
	}else{
		solve(count-1, source, intermediate, destination);
		solve(1, source, destination, intermediate);
		solve(count-1, intermediate, destination, source);
	}
}
*/
int A[60], B[60], C[60];
int LOC[60];
bool ok;
LL f(int N, int src, int inter, int des){
	if(!N) return 0;
	if(LOC[N] != src && LOC[N] != des){
		ok = false;
		return 0;
	}
	if(LOC[N] == src) return f(N-1, src, des, inter);
	else return f(N-1, inter, src, des) + (1LL<<(N-1));
}
int main(){
	ok = true;
	memset(LOC, -1, sizeof(LOC));
	int n = 0;
	for(int i = 0; i < 3; i++){
		int mm;
		scanf("%d", &mm);
		for(int j = 0; j < mm; j++){
			int x;
			scanf("%d", &x);
			LOC[x] = i;
		}
		n += mm;
	}
	LL msk = 0LL;
	LL prev = 0LL;
	LL ans = f(n, 0, 1, 2);
	if(!ok) printf("No\n");
	else printf("%lld\n", (1LL<<n) - ans - 1);
	return 0;
}