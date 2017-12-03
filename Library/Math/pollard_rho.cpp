/*
	Método de factorización de números usando la función Rho de Pollard
*/
#include <bits/stdc++.h>
#define LL long long
using namespace std;
LL ABS(LL x){
	if(x < 0 ) return -x;
	return x;
}
LL mrandom(){
	LL x = ((LL)rand()) * ((LL)rand());
	return x;
}
LL my_random(LL a, LL b){
	LL dif = b - a + 1;
	return mrandom()%dif + a;
}
LL gcd(LL a, LL b){
	if(a==0LL) return b;
	if(b==0LL) return a;
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
	while(!(d & 1LL)){ r++; d/=2LL;}
	for(int i=0; i<k; i++){
		LL a = my_random(2LL, n-2);
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
LL f(LL x, LL c, LL n){
	return (mulmod(x,x,n) + c)%n;
}
LL pollard_rho(LL n, LL c){
	int i = 0, k = 2;
	LL x = 2, y = 2;
	while(true){
		i++;
		x = f(x,c, n); 
		LL d = gcd(ABS(y-x), n);
		if(d>1) return d;
		if(i==k) y = x, k<<=1LL;	
	}
	return -1;
}
map<LL,int> pfactors;
void factorize(LL n){
	if(n==1LL) return;
	LL x = n;
	bool P = primetest(n, 3);
	for(LL i=2; x==n && !P; i++){
		x = pollard_rho(n, i);
	}
	if(x==n){ pfactors[n]++;  return;}
	factorize(n/x); factorize(x);
}
int main(){
	srand(time(NULL));
	int t;
	scanf("%d", &t);
	while(t--){
		LL x;
		scanf("%lld", &x);
		factorize(x);
		map<LL,int>::iterator it;
		int i = 0;
		printf("%lld = ", x);
		for(it = pfactors.begin(); it!=pfactors.end(); ++it, i++){
			printf("%s", (i==0) ? ("") : (" * "));
			printf("%lld", (*it).first);
			if((*it).second!=1) printf("^%d", (*it).second);
		}
		if(x==1) printf("1");
		printf("\n");
		pfactors.clear();
	}
	return 0;
}