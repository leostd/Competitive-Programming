/*	
	Este algoritmo, conocido como Kadane, encuentra
	la mayor suma contigua en un arreglo de numeros.
	La idea de este algoritmo es acarrear 2 variables,
	una que contiene la maxima suma y otra, 
	la suma hasta el indice i-esimo. Si la suma hasta i
	es mayor, se actualiza el maximo. Si la suma hasta i
	es menor que 0, se le asigna 0.

	Complejidad en tiempo O(n)
	Complejidad en espacio O(n)
	
	Donde n es la longitud del arreglo
*/

#include <bits/stdc++.h>
using namespace std;

int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
const int n = 8;

int main(){
	int max_so_far, max_ending_here;
	max_ending_here = max_so_far = 0;
	for (int i = 0; i < n; i++){
		max_ending_here += arr[i];
		if (max_ending_here > max_so_far)
			max_so_far = max_ending_here;
		if (max_ending_here < 0)
			max_ending_here = 0;
	}
	printf("%d\n", max_so_far);
	return 0;
}