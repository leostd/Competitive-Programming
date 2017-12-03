/*
	Optimizacion de Knuth Yao
	DP[i][j] = min(i <= c <= j) DP[i][c] + DP[c][j] + cost(i,j)
	Permite realizar este DP O(n^3) en O(n^2)
	Para poder aplicarlo, debe cumplirse, para a<=b<=c<=d:
	Desigualdad cuadrangular:	cost(a,c) + cost(b,d) <= cost(a,d) + cost(b,c)
	Monotocidad:				cost(b,c) <= cost(a,d)
	Al garantizar esto, se cumple que
	op[L][R+1] <= op[L][R] <= op[L+1][R]

	Donde op[L][R] es el c optimo que resuelve la recursion planteada

	Caso de ejemplo: ZOJ - Breaking Strings
*/
#include <bits/stdc++.h>
#define LL long long
#define INF 1000000000000000000LL
using namespace std;
int B[1010];
int n, m;
LL dp[1010][1010];
int op[1010][1010];
int main(){
	while(scanf("%d %d", &n, &m)!=-1){
		m += 2;
		B[0] = 0; B[m-1] = n;
		for(int i=1; i<m-1; i++) scanf("%d", &B[i]);
		for(int s = 0; s<m; s++){
			for(int i=0; i+s<m; i++){
				int L = i, R = i+s;
				if(s < 2){
					dp[L][R] = 0;
					op[L][R] = L;
				}else{
					dp[L][R] = INF;
					int opleft = op[L][R-1], opright = op[L+1][R];
					for(int j = opleft; j <= opright; j++){
						int cost = B[R] - B[L];
						if(dp[L][j] + dp[j][R] + cost < dp[L][R]){
							dp[L][R] = dp[L][j] + dp[j][R] + cost;
							op[L][R] = j;
						}
					}
				}
			}
		}
		printf("%lld\n", dp[0][m-1]);
	}
	return 0;
}