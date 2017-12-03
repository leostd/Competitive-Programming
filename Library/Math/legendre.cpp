/*
	Formula de Legendre L(n,p)
	Obtiene el exponente mas grande de un primo p, que divide a n!
	O(log n)
	L(n,p) = (n - sp(n))/(p-1)
	Donde sp es la suma de los digitos de n, representados en base p
*/
#include <bits/stdc++.h>
using namespace std;
int L(int n, int p){
	int sum = 0, m = n;
	while(m){
		sum += m%p;
		m /= p;
	}
	return (n - sum)/(p-1);
}