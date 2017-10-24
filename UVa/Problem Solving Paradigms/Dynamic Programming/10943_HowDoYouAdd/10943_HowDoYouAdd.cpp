#include <bits/stdc++.h>
using namespace std;

int memo[202][202];
int mod = 1000000;

int binomial_coefficient(int n, int k){
	if (n == k || k == 0 || k > n)
		return 1;
	if (memo[n][k] != -1)
		return memo[n][k];
	memo[n][k] = (binomial_coefficient(n-1, k-1) + binomial_coefficient(n-1, k)) % mod;
	return memo[n][k];	
}

int main(){
	int n, k;
	memset(memo, -1, sizeof(memo));
	while(scanf("%d %d", &n, &k), n || k){
		int ans = binomial_coefficient(n+k-1, k-1);
		printf("%d\n", ans);
	}
	return 0;
}