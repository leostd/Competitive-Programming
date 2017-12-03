#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL gcd(LL a, LL b){
	if(!b) return a;
	return gcd(b, a%b);
}
LL mulmod(LL a, LL b, LL m){
	LL x = 0LL, y = a%m;
	while(b > 0LL){
		if(b & 1LL) x = (x + y)%m;
		y = (y*2)%m;
		b>>=1LL;
	}
	return x%m;
}
LL fpow(LL a, LL e, LL m){
	LL x = 1, y = a;
	while(e > 0LL){
		if(e & 1LL) x = mulmod(x,y,m);
		y = mulmod(y,y,m);
		e>>=1LL;
	}
	return x%m;
}
bool primetest(LL n, int k){
	if(n==1LL) return false;
	if(n==2LL || n==3LL) return true;
	if(!(n & 1LL)) return false;
	LL r = 0, d = n-1;
	random_device rd;
	uniform_int_distribution<LL> D(2, n-2);
	mt19937 gen(rd());
	while(!(d & 1LL)){ r++; d/=2LL;}
	for(int i=0; i<k; i++){
		LL a = D(gen);
		LL x = fpow(a, d, n);
		if(x==1LL || x==n-1LL) continue;
		bool compo = true;
		for(int i=0; i<r-1 && compo; i++){
			x = fpow(x, 2LL, n);
			if(x==1LL) return false;
			if(x==n-1LL){
				compo = false;
			}
		}
		if(compo) return false;
	}
	return true;
}
vector<LL> F;
LL brent(LL N){
	if(!(N&1LL)) return 2LL;
	if(primetest(N, 3)) return N;
	random_device rd;
	uniform_int_distribution<LL> d(1, N);
	mt19937 gen(rd());
	LL y = d(gen), c = d(gen), m = d(gen);
	LL g = 1, r = 1, q = 1, x, ys;
	while(g == 1){
		x = y;
		for(LL i = 0; i < r; i++)
			y = (mulmod(y,y,N)+c)%N;
		LL k = 0;
		while(k < r && g == 1){
			ys = y;
			for(LL i = 0; i < min(m, r-k); i++){
				y = (mulmod(y,y,N)+c)%N;
				q = mulmod(q,llabs(x-y),N);
			}
			g = gcd(q, N);
			k = k + m;
		}
		r <<= 1LL;
	}
	if(g == N){
		while(true){
			ys = (mulmod(ys,ys,N)+c)%N;
			g = gcd(llabs(x-ys),N);
			if(g > 1) break;
		}
	}
	if(g == N) return brent(g);
	return g;
}
void factorize(LL x){
	LL p = brent(x);
	if(p == x) F.push_back(x);
	else{
		factorize(p);
		factorize(x/p);
	}
}
int main(){
	LL x;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld", &x);
		factorize(x);
		sort(F.begin(), F.end());
		for(int i = 0; i < F.size(); i++) printf("%s%lld", (i == 0) ? (""):(" "), F[i]); printf("\n");
		F.clear();
	}
	return 0;
}