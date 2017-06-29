#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef set<ll> si;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return (a*b) / gcd(a, b);
}


si divisors(ll n){
	si d;
	for(ll p = 1; p*p <= n; ++p){
		if (n % p == 0){
			d.insert(n/p);
			d.insert(p);
		}
	}
	return d;
}


int main(){
	ll n;
	while(scanf("%lli", &n), n) {
		si d = divisors(n);
		ll counter = 0;
		for (auto it = d.begin(); it != d.end(); it++){
			for (auto it2 = it; it2 != d.end(); ++it2){
				if (lcm(*it, *it2) == n) counter++;
			}
		}
		printf("%lli %lli\n", n, counter);
	}
	return 0;
}