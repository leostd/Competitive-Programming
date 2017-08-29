/*
	Este algoritmo obtiene la mayor ganancia
	que se puede obtener al vender una barra
	de longitud n. El comprador tiene un
	precio para barras de diferentes longitudes.
	Esta barra se puede cortar para obtener 
	mayores ganancias.
	
	Relacion de recurrencia:
		rod(size): 0 	si size == 0
		rod(size): max(rod(size-i) + price[i])  para todo i < n

	Complejidad en tiempo: O(n^2)
	Complejidad en espacio: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

const int n = 8;
//added a 0 at index 0 for simplicity
int price[] = {0,1,5,8,9,10,17,17,20};
int memo[1000];

int CuttingRod(int size){
	if (size == 0)
		return 0;
	if (size == 1)
		return price[1];
	if (memo[size] != -1)
		return memo[size];
	memo[size] = -0x3f3f3f3f;
	for (int i = 1; i <= size; i++)
		memo[size] = max(memo[size], CuttingRod(size-i) + price[i]);
	return memo[size];
}

int main(){
	memset(memo, -1, sizeof(memo));
	printf("%d\n", CuttingRod(n));
	return 0;
}