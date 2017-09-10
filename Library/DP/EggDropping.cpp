/*
	Este algoritmo consigue el numero minimio de lanzamientos dados n
	huevos y k pisos.
	Al lanzar un huevo desde un piso p, el huevo puede romperse o no. 
	Se  toma el peor caso de ambos.
	
	k ==> Number of floors
  	n ==> Number of Eggs
  	eggDrop(n, k) ==> Minimum number of trials needed to find the critical
                    floor in worst case.
  	eggDrop(n, k) = 1 + min{max(eggDrop(n - 1, x - 1), eggDrop(n, k - x)): 
                 x in {1, 2, ..., k}}
*/


#include <bits/stdc++.h>
using namespace std;

int memo[1000][1000];

int eggDrop(int n, int k){
	if(k == 0 || k == 1)
		return k;
	if (n == 1)
		return k;
	if(memo[n][k] != -1)
		return memo[n][k];
	int worstcase, minWorst = 0x3f3f3f3f;
	for (int i = 1; i <= k; i++){
		worstcase = max(eggDrop(n-1, i-1), eggDrop(n, k-i));
		if (worstcase < minWorst)
			minWorst = worstcase;
	}
	return memo[n][k] = minWorst+1;
}

int main(){
	int n = 2, k = 10;
	memset(memo, -1, sizeof(memo));
	printf("%d\n", eggDrop(n, k));
	return 0;
}