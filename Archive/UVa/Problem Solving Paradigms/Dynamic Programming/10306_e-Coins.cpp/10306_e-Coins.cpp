#include <bits/stdc++.h>
#define M 41
#define S 90001
using namespace std;

typedef pair<int, int> ii;

ii coins[M];
int memo[301][301];
int n, m, s, mod;

int dp(int v, int it){
	if (mod - (v*v + it*it) == 0)
		return 0;
	if (mod - (v*v + it*it) < 0)
		return 0x3f3f3f3f;
	if (memo[v][it] != -1)
		return memo[v][it];
	int ans = 0x3f3f3f3f;
	for (int i = 0; i < m; i++){
		int a = coins[i].first + v;
		int b = coins[i].second + it;
		ans = min(ans,dp(a, b));
	}
	return memo[v][it] = ans+1;
}


int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d %d", &m, &s);
		for (int i = 0; i < m; i++)
			scanf("%d %d", &coins[i].first, &coins[i].second);
		memset(memo, -1, sizeof(memo));
		mod = s*s;
		int ans = dp(0, 0);
		if (ans >= 0x3f3f3f)
			printf("not possible\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}