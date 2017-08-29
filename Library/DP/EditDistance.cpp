/*
	Este algoritmo calcula el minimo numero de operaciones
	que deben realizarse para convertir el string
	a en el string b. Las operaciones contempladas son
	insertar, eliminar y modificar.

	Relacion de recurrencia:
		edit(i_a, i_b) : i_b + 1 	si i_a < 0
		edit(i_a, i_b) : i_a + 1 	si i_b < 0
		edit(i_a, i_b) : 0 			si a[i_a] == b[i_b]
		edit(i_a, i_b) : min(edit(i_a-1, i_b-1), edit(i_a, i_b-1), edit(i_a-1, i_b-1))+1

	Complejidad en tiempo O(nm)
	Complejidad en espacio O(nm)

	Donde n y m representan la longitud de los strings
	a y b
*/

#include <bits/stdc++.h>
using namespace std;

string a = "sunday";
string b = "saturday";

int memo[1000][1000];

int edit(int ida, int idb){
	if (ida < 0)
		return idb+1;
	if (idb < 0)
		return ida+1;
	if (memo[ida][idb] != -1)
		return memo[ida][idb];
	if (a[ida] == b[idb])
		return memo[ida][idb] = edit(ida-1, idb-1);
	int x = edit(ida, idb-1);
	int y = edit(ida-1, idb);
	int z = edit(ida-1, idb-1);
	return memo[ida][idb] = min(x, min(y, z))+1;
}

int main(){
	int n, m;
	n = a.size();
	m = b.size();
	memset(memo, -1, sizeof(memo));
	printf("%d\n", edit(n, m));
	return 0;
}