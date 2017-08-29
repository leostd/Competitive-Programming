/*
	Este algoritmo calcula los numeros de Fibonacci
	hasta n, implementando el paradigma de Top-Down
	DP.

	Relacion de recurrencia:
		Fib(n) = 1 si n == 1 || n == 0
		Fib(n) = Fib(n-1) + Fib(n-2)

	Complejidad en tiempo O(n)
	Complejidad en espacio O(n)
*/

#include <bits/stdc++.h>
using namespace std;

const int n = 5;
int memo[1000];

int Fib(int number){
	if (number == 1 || number == 0)
		return 1;
	if (memo[number] != -1)
		return memo[number];
	memo[number] = Fib(number-1) + Fib(number-2);
	return memo[number];
}


int main(){
	memset(memo,-1,sizeof(memo));
	printf("%d\n", Fib(n));
	return 0;
}