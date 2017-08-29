/*
	Cantidad de combinaciones posibles para dar un cambio
	para un monto m, teniendo NCOINS monedas distintas,
	almacenadas en coins

	Relacion de recurrencia:
	ways(0,_): 1
	ways(money < 0,_): ways(m, coin >= NCOINS): 0
	ways(m, coin): ways(m-coins[coin], coin) + ways(m, coin+1)
*/

#include <bits/stdc++.h>
#define NCOINS 5
using namespace std;

typedef long long int lli;
int coins[NCOINS] = {1, 2, 3, 4, 5};
int memo[1000][NCOINS];

lli ways(int money, int coin){
	if (money == 0)
		return 1;
	if (money < 0 || coin >= NCOINS)
		return 0;
	if (memo[money][coin] != -1)
		return memo[money][coin];
	memo[money][coin] = ways(money-coins[coin], coin) + ways(money, coin+1);
	return memo[money][coin];
}

int main(){
	int m;
	while(scanf("%d", &m), m){
		memset(memo, -1, sizeof(memo));
		printf("%lli\n", ways(m, 0));
	}
	return 0;
}