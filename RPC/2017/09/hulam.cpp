#include <bits/stdc++.h>
using namespace std;
bool H[100010];
int h[100010];
int main(){
	h[0] = 1; h[1] = 2;
	H[3] = true;
	int x = 4;
	for(int i = 2; i < 10000; i++){
		while(H[x]) x++;
		h[i] = x;
		for(int j = 0; j < i; j++) H[h[j] + x] = true;
		H[x] = true;
	}
	int t, n;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		printf("%d\n", h[n-1]);
	}
	return 0;
}
