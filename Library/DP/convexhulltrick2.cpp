/*
	CONVEX HULL TRICK - Caso 2
	dp[i][j] = min(k < j) dp[i-1][k] + b[k]*a[j]
	donde b[k] >= b[k+1] y opcionalmente a[j] <= a[j+1]
	Permite solucionar este dp de O(n^2*k) en O(n*k)

	Ejemplo: Solucion al problema Arranging Heaps 

*/

#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL dp[1010][1010];
LL x[1010], S[1010], W[1010], w[1010];
int n, k;
class line{
public:
	LL m, b;
	line(){}
	line(LL _m, LL _b){
		m = _m; b = _b;
	}
};
line ST[1000010];
int P, top;
bool left_to(line l1, line l2, line l3){
	return (l3.b - l1.b)*(l1.m-l2.m) < (l2.b-l1.b)*(l1.m-l3.m);
}
LL query(LL x){
	while(P < top && ST[P].m * x + ST[P]. b > ST[P+1].m * x + ST[P+1].b) P++;
	return ST[P].m * x + ST[P].b;
}
void insert(line l3){
	while(top > P && left_to(ST[top-1], ST[top], l3)) top--;
	ST[++top] = l3;
	if(top==1) P = 1;
}
int main(){
	while(scanf("%d %d", &n, &k)!=-1){
		for(int i=1; i<=n; i++){
			scanf("%lld %lld", &x[i], &w[i]);
		}
		W[0] = S[0] = 0;
		for(int i=1; i<=n; i++){
			S[i] = S[i-1] + w[i];
			W[i] = W[i-1] + x[i]*w[i];
		}
		dp[0][0] = 0;
		for(int i=1; i<=k; i++){
			top = P = 0;
			for(int j=i; j<=n; j++){
				if(!(i==1 && j>1)) insert(line(-S[j-1], dp[i-1][j-1] + W[j-1]));
				dp[i][j] = query(x[j]) + x[j]*S[j] - W[j];
			}
		}
		printf("%lld\n", dp[k][n]);
	}
	return 0;
}