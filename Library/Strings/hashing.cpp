/*
	Implementación de Hashing, con p = 10^9 + 7 y MOD = 2^64
	Como usar:
		Preprocesar la cadena H O(n)
		Obtener hash values por rango usando hash_val(i,j)
		hash_val(i,j) = Valor hash del substring H[i..j]
*/
#include <bits/stdc++.h>
#define LL unsigned long long
const LL p = 1000000007;
LL H[100010];
LL POW[100010];
LL hash_val(int i, int j){
	return H[j+1] - H[i]*POW[j-i+1];
}

int main(){
	POW[0] = 1LL;
	for(int i = 1; i <= 100000; i++) POW[i] = POW[i-1]*p;
	scanf("%s", W);
	n = strlen(W);
	H[0] = 0;
	for(int i = 1; i <= n; i++){
		H[i] = W[i-1]-'a' + 1 + H[i-1]*p;
	}
	return 0;
}