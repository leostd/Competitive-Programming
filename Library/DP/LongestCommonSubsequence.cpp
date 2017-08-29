/*
	Este algoritmo calcula la subsecuencia
	mas larga, comun, entre 2 strings

	Relacion de recurrencia:
		lcs(i, j) : 0 					si i < 0 || j < 0
		lcs(i, j) : 1 + lcs(i-1, j-1)	si x[i] == y[j]
		lcs(i, j) : max(lcs(i-1, j), lcs(i, j-1), lcs(i-1, j-1))

	Complejidad en tiempo: O(nm)
	Complejidad en espacio: O(nm)
*/

#include <bits/stdc++.h>
using namespace std;

int n, m, memo[1000][1000];
string x = "mxelyenocanqtqas";
string y = "sameqezncwantxas";	

int lcs(int idx, int idy){
	if (idx < 0 || idy < 0)
		return 0;
	if (memo[idx][idy] != -1)
		return memo[idx][idy];
	if (x[idx]==y[idy])
		return memo[idx][idy] = 1 + lcs(idx-1, idy-1);
	int a = lcs(idx-1, idy);
	int b = lcs(idx, idy-1);
	return memo[idx][idy] = max(a, b);
}

int main(){
	m = x.size();
	n = y.size();
	memset(memo, -1, sizeof(memo));
	printf("%d\n", lcs(m-1, n-1));
	return 0;
}