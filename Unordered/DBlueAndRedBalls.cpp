#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define MOD 1000000007
#define MULT(a,b) (((a%MOD)*(b%MOD))%MOD)

ll f[2005], inv[2005], pows[2005][2005];

ll bpow(ll a, ll b){
	if (b == 0)
		return 1;
	else if ( b % 2 == 0 )
		return bpow((MULT(a, a)), b/2)%MOD;
	else
		return MULT(bpow(a, b-1), a);
}

ll minv(ll a){
	return bpow(a, MOD-2);
}

ll fact(ll x) {
	if (x == 1 || x == 0)
		return 1;
	else if (f[x] != -1)
		return f[x];
	else
		return f[x] = MULT(x, fact(x-1));
}

ll c(ll n, ll m){
	if (n < 0 || m < 0 || n < m) return 0;
	//n!/(n-m)!m!
	ll a, b, c;
	a = fact(n);
	b = minv(fact(n-m));
	c = minv(fact(m));
	return MULT(a, MULT(b, c));
}

void init(){
	memset(f, -1, sizeof(f));
	memset(pows, -1, sizeof(pows));
	fact(2005);
	for(int i = 1; i < 2005; i++)
		inv[i] = minv(i);
}



class DBlueAndRedBalls {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k, n;
		init();
		in >> n >> k;
		for (int i = 1; i <= k; i++){
			ll bucket_ways = c(n-k+1, i);
			ll blue_balls_arrangements = c(k-1, i-1);
			out << (i == 1 ? c(n-k+1, i) : MULT(bucket_ways, blue_balls_arrangements)) << "\n";
		}


	}
};