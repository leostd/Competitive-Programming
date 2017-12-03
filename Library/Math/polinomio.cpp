/*
	Operaciones sobre polinomios (aritmética para polinomios de grado pequeño)
	Suma, resta y multiplicación
	También verifica si un número dado es una raíz de un polinomio O(n)
*/

#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define VI vector<int>
#define pii pair<int,int>
#define matrix vector<VI>
#define LL long long
#define MOD 1000000007
#define ULL unsigned long long
#define uedge(g,a,b) g[a].pb(b), g[b].pb(a)
#define dedge(g,a,b) g[a].pb(b)
using namespace std;
typedef vector<LL> poly;
char e[50];
poly polymul(poly& A, poly& B){
	int n = (int)A.size(), m = (int)B.size();
	poly C = poly(n + m - 1, 0LL);
	for(int i = 0; i < n + m - 1; i++){
		for(int j = 0; j <= i; j++){
			if(j >= n || i-j >= m) continue;
			C[i] += A[j]*B[i-j];
		}
	}
	return C;
}
poly polysum(poly& A, poly& B, LL op){
	int n = (int)A.size(), m = (int)B.size();
	poly C = poly(max(n,m), 0LL);
	for(int i = 0; i < max(n, m); i++){
		if(i >= n) C[i] = op*B[i];
		else if(i >= m) C[i] = A[i];
		else C[i] = A[i] + op*B[i];
	}
	return C;
}
LL ANS[10010];
bool root(LL divi, poly& P){
	LL x = 0;
	for(int i = (int)P.size() - 1; i >= 0; i--){
		if(x % divi != 0) return false;
		x /= divi;
		x -= P[i];
	}
	return x == 0;
}