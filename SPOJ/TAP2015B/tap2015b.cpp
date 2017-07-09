#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int k, l;
ll arr[1000006];
bool f(ll c) {
	int counter = 0;
	ll acum = 0;
	for (int i = 1; i <= l; ++i){
		acum += arr[i];
		if (acum >= c) {
			counter++;
			acum = 0;
		}
		if (counter >= k) break;
	}
	return counter >= k;
}

int main(){
	for (int i = 1; i <= 1000000; ++i)
		arr[i] = i + (i-1);
	while(scanf("%d %d", &l, &k) != EOF) {
		ll s, mid, e;
		s = 1; e = (ll)l*l;
		while(e - s > 1){
			mid = (e-s)/2 + s;
			if (f(mid))
				s = mid;
			else
				e = mid-1;
		}
		if (f(e))
			printf("%lli\n", e);
		else
			printf("%lli\n", s);
	}
	return 0;
}