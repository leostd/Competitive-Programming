#include <math.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int k, r;
double p[25], F[1100000];

//a^e
int mypow(int a, int e){
	if (e == 1)
		return a;
	if (e == 0)
		return 1;
	else
	{
		if (e % 2 == 0)
			return mypow(a, e/2) * mypow(a, e/2);
		else
			return mypow(a, e-1) * a; 
	}
}
// ln( nCm ) => ln ( n choose m ) 
double logFactorial(int n){
	double ans = 0.0L;
	for (int i = 2; i <= n; i++){
		ans += log(i);
		F[i] = ans;
	}
}

int main()
{
    scanf("%d %d", &k, &r);
    long double numerator, denominator;
    int players = mypow(2, k);
    int worsep = players - r;
    double b = 0.0L, c = 0.0L, ans = 0.0L;
    logFactorial(players);
    double worsef = F[worsep];
    double playersf = F[players-1];
    for (int i = 1; i <= k; i++){
        double a, b;
        int aux = mypow(2, i)-1;
        if (aux > worsep)
       		a = b = -1L;
        else{
        	double auxf = F[aux];
        	a = worsef - auxf - F[worsep-aux];
        	b = playersf - auxf - F[players - 1 - aux];
        }
        if (a != -1L && b != -1L)
            p[i] = exp(a - b);
        else
            p[i] = 0.0L;
        ans += p[i];
    }
    printf("%.5lf\n", ans);
    return 0;
}