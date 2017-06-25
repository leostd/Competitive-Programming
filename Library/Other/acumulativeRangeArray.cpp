/*
	Stacks consecutivas. Este algoritmo actualiza un rango en el arreglo
	de stacks en O(N).
*/

#include <bits/stdc++.h>
#define N 1000006
using namespace std;

int acum[N], s[N];

int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	memset(acum, 0, sizeof(acum));
	int a, b;
	for(int i = 0; i < k; ++i) {
		scanf("%d %d", &a, &b);
		acum[a]++;
		acum[b+1]--;
	}
	for (int i = 1; i <= n; ++i)
		acum[i] += acum[i-1];
	sort(acum+1, acum+n+1);
	printf("%d\n", acum[n/2 + 1]);
	return 0;
}