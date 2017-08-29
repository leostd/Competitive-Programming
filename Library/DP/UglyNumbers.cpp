/*
	Un 'Ugly number' es aquel que sus factores primos son unicamente
	2, 3 y 5.

	1,2,3,4,5,6,8,9,10,12,15 son los primeros 11 'Ugly numbers'

	Este algoritmo genera todos los 'Ugly Numbers' hasta n. Utilizando
	un metodo parecido al merge implementado en el mergesort. Cada numero
	pertnece a alguna de las siguientes series:

	(1) 1x2, 2x2, 3x2, 4x2, 5x2, 6x2, 8x2, 9x2...
	(2) 1x3, 2x3, 3x3, 4x3, 5x3, 6x3, 8x3, 9x3...
	(3) 1x5, 2x5, 3x5, 4x5, 5x5, 6x5, 8x5, 9x5...

	Complejidad de tiempo de este algoritmo es O(n)
	Complejidad en memoria de este algoritmo es O(n)
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 150;

unsigned NthUglyNumber(unsigned n){
	unsigned ugly[N];
	unsigned i2, i3, i5;
	unsigned next_multiple_of_2 = 2;
	unsigned next_multiple_of_3 = 3;
	unsigned next_multiple_of_5 = 5;
	unsigned next_ugly_number = 1;
	i2 = i3 = i5 = 0;
	ugly[0] = 1;
	for (int i=1; i < n; i++){
		next_ugly_number = min(next_multiple_of_2, \
			min(next_multiple_of_3,next_multiple_of_5));
		ugly[i] = next_ugly_number;
		if (next_ugly_number == next_multiple_of_2){
			i2++;
			next_multiple_of_2 = ugly[i2] * 2;
		}
		if (next_ugly_number == next_multiple_of_3){
			i3++;
			next_multiple_of_3 = ugly[i3] * 3;
		}
		if (next_ugly_number == next_multiple_of_5){
			i5++;
			next_multiple_of_5 = ugly[i5] * 5;
		}
	}
	return next_ugly_number;
}
int main(){
	int n = 150;
	printf("%d\n", NthUglyNumber(n));
	return 0;
}