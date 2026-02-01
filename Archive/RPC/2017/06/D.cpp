#include <bits/stdc++.h>
#define N 10004
using namespace std;

typedef long long ll;
typedef vector<int> vi;

int main() {
	int t;
	scanf("%d", &t);
	ll h[N], x[N], xacum[N];
	vi surface;
	while(t--) {
		int n, a;
		scanf("%d %d", &a, &n);
		memset(xacum, 0, sizeof(xacum));
		surface.clear();
		for (int i = 1; i <= n; i++) {
			scanf("%lli", &x[i]);	
			xacum[i] = xacum[i-1] + x[i];
		}
		for(int i = 0; i <= n; i++) 
			scanf("%lli", &h[i]);
		int i = 0,j, hmaxi;
		ll acum = 0,hmax;
		while (i < n) {
			j = i+1;
			hmax = -1;
			while(j <= n) {
				if (h[j] > hmax){
					hmax = h[j];
					hmaxi = j;
				}
				if (h[i] < hmax) break;
				j++;
			}
			acum += (xacum[hmaxi]-xacum[i]) * min(h[i], hmax);
			i = hmaxi;
		}
		printf("%lli\n", acum*a);
	}
	return 0;
}