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
int t, n, k;
LL fpow(LL a, LL e){
	LL x = 1, y = a;
	while(e){
		if(e & 1) x = (x*y);
		y = y*y;
		e >>= 1;
	}
	return x;
}
LL C[1010];
int main(){
	for(int i = 0; i <= 1001; i++) C[i] = i*i*i;
	fastInt(t);
	while(t--){
		fastInt(n); fastInt(k);
		if(k >= n) printf("%lld\n", C[n+1]);
		else{
			LL ans = C[k+1];
			ans += (LL)(n - k)*(LL)(1 + 3*k*k + 3*k);
			printf("%lld\n", ans); 
		}
		/*
		int ans1 = 0;
		for(int i = 0; i <= n; i++){
			for(int j = 0; j <= n; j++){
				for(int r = 0; r <= n; r++){
					if(abs(i - j) <= k && abs(i - r) <= k && abs(j - r) <= k) ans1++;
				}
			}
		}
		printf("%d\n", ans1);
		LL s = 0LL;
		for(int i = 0; i <= k; i++) s += 2LL*k - i + 1;
		LL l = k, r = n - k;
		LL ans = 0LL;
		if(l <= r && (r - l + 1) >= 2*k + 1LL) ans += (r - l + 1)*s;
		ans += fpow(min(n, k + 1), 3);
		if(n != k) ans += fpow(min(n, k + 1), 3);
		//printf("%lld\n", ans);
		*/
	}
	return 0;
}