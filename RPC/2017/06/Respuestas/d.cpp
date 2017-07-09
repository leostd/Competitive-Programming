#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define VI vector<int>
#define LL unsigned long long
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
using namespace std;
inline void fastInt(int &a){
    char c;
    int s = 1;
    a = 0;
	while(true){
		c = getchar_unlocked();
		if(c=='-') s = -1;
		if(c>='0' && c<='9') break;
	}
	while(true){
		a = a*10 + c-'0';
		c = getchar_unlocked();
		if(c<'0' || c>'9') break;
	}
	a *= s;
}
int n, a;
int x[100010], h[100010];
int L[100010], R[100010];
pii B[100010];
bool mark[100010];
int main(){
	int t;
	fastInt(t);
	while(t--){
		fastInt(a); fastInt(n);
		x[0] = 0;
		for(int i = 1; i <= n; i++){
			int len;
			fastInt(len);
			x[i] = x[i-1] + len;
		}
		for(int i = 0; i <= n; i++) fastInt(h[i]);
		L[0] = -1;
		for(int i = 1; i <= n; i++){
			int p = i - 1;
			while(p >= 0 && h[p] <= h[i]){
				if(L[p] == -1 && h[p] == h[i]) break;
				p = L[p];
			}
			L[i] = p;
		}
		R[n] = n + 1;
		for(int i = n - 1; i >= 0; i--){
			int p = i + 1;
			while(p < n + 1 && h[p] <= h[i]){
				if(R[p] == n + 1 && h[p] == h[i]) break;
				p = R[p];
			}
			R[i] = p;
		} 
		
		memset(mark, false, sizeof(mark));
		LL total = 0;
		for(int i = 0; i <= n; i++) B[i] = mp(h[i], i);
		sort(B, B + n + 1);
		//for(int i = 0; i <= n; i++) printf("%d ", L[i]); printf("\n");
		//for(int i = 0; i <= n; i++) printf("%d ", R[i]); printf("\n");
		for(int i = n; i >= 0; i--){
			if(mark[B[i].second]) continue;
			mark[B[i].second] = true;
			int l = L[B[i].second], r = R[B[i].second];
			//printf("P %d %d %d\n", B[i].second, l, r);
			if(l >= 0){
				for(int j = B[i].second; j >= l; j--) mark[j] = true;
				total += (LL)h[B[i].second]*(LL)(x[B[i].second] - x[l]);
				//printf("L %lld\n", (LL)h[B[i].second]*(LL)(x[B[i].second] - x[l]));
			}
			if(r < n + 1){
				for(int j = B[i].second; j <= r; j++) mark[j] = true;
				total += (LL)h[B[i].second]*(LL)(x[r] - x[B[i].second]);
				//printf("R %lld\n", (LL)h[B[i].second]*(LL)(x[r] - x[B[i].second]));
			}
		}
		printf("%lld\n", total*(LL)a);
	}
	return 0;
}