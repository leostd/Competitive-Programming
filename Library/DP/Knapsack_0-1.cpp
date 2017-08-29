/*
	Dado un conjunto de items con un valor y un peso,
	determinar un subconjunto optimo en valor que,
	a su vez, cumpla con una restriccion de peso
	dado y mostrar el valor del subconjunto.

	Relacion de recurrencia:
		Knapsack(w, i) : 0 	si w == 0
		Knapsack(w, i) : -INF si w < 0
		Knapsack(w, i) : 0 si i >= nitems
		Knapsack(w, i) : max(Knapsack(w-weight[i], i+1)+value[i], Knapsack(w, i+1))
	
	Complejidad en tiempo O(nw)
	Complejidad en espacio O(nw)
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXWEIGHT 2000
#define NITEMS 200
typedef long long ll;
ll memo[MAXWEIGHT][NITEMS];
int values[NITEMS], weights[NITEMS];
int nitem;

ll knapsack(int weight, int item){
	if (weight == 0)
		return 0;
	if (weight < 0)
		return -1000000000;
	if (item >= nitem)
		return 0;
	if (memo[weight][item] != -1)
		return memo[weight][item];
	ll a = values[item] + knapsack(weight-weights[item], item+1);
	ll b = knapsack(weight, item+1);
	memo[weight][item] = max(a, b);
	return memo[weight][item];
}

int main(){
	int w;
	while(scanf("%d %d", &nitem, &w), nitem || w){
		for (int i = 0; i < nitem; i++)
			scanf("%d %d", &values[i], &weights[i]);
		memset(memo, -1, sizeof(memo));
		ll ans = knapsack(w, 0);
		printf("%lli\n", ans);
	}
	return 0;
}