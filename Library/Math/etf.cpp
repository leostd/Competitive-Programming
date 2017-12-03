/*
	Funcion Phi(n) de Euler
	E[n] = Cantidad de numeros menores a n, tal que gcd(x,n) = 1
*/
#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define pii pair<int,int>
#define matrix vector<VI>
#define LL long long
#define ULL unsigned long long
#define MOD 1000000007
#define uedge(g,a,b) g[a].pb(b), g[b].pb(a)
#define dedge(g,a,b) g[a].pb(b)
using namespace std;
const int N = 1000000;
int E[N+10];
void sieve(){
	for(int i = 0; i <= N; i++) E[i] = i;
	for(int i = 2; i <= N; i++){
		if(E[i] != i) continue;
		E[i] = i-1;
		for(int j = i; j <=N; j+=i) E[j] -= E[j]/i;
	}
}
int main(){
	sieve();
	int t;
	scanf("%d", &t);
	int x;
	while(t--){
		scanf("%d", &x);
		printf("%d\n", E[x]);
	}
	return 0;
}