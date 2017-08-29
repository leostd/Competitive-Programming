/*
	Este algoritmo calcula la minima cantidad de operaciones
	aritmeticas que deben realizarse para multiplicar una 
	serie de Matrices. Dadas las dimensiones de las matrices
	y utilizando la propiedad asociativa de la multiplicacion
	de matrices, es posible obtener este numero.

	Complejidad en tiempo: O(n^3)
	Complejidad en espacio: O(n^2)
*/

#include <bits/stdc++.h>
using namespace std;

const int n = 4;

int m[n][n];
int q, j;
int dimensions[] = {1, 2, 3, 4};

void initMatrix(){
	for (int i = 1; i < n; i++)
		m[i][i] = 0;
}

int MatrixChainOrder(){
	for (int L = 2; L < n; L++){
		for(int i = 1; i < n-L+1; i++){
			j = i+L-1;
			m[i][j] = 0x3f3f3f3f;
			for(int k=1; k<=j-1; k++){
				q = m[i][k] + m[k+1][j] + dimensions[i-1]*dimensions[k]*dimensions[j];
				if (q < m[i][j])
					m[i][j] = q;
			}
		}
	}
	return m[1][n-1];
}

int main(){
	initMatrix();
	int ans = MatrixChainOrder();
	printf("%d\n", ans);
	return 0;
}