#include <iostream>
#include "../library/lib.hpp"
#define MOD 1000000007
ll memo[200][2];
int d;

inline ll count(int n, int k, bool flag){
	if (n == 0 && flag)
		return 1;
	if (n < 0 || (n== 0 && !flag))
		return 0;
	if (memo[n][flag] != -1)
		return memo[n][flag];
	ll &a = memo[n][flag];
	a = 0;
	for (int i = 1; i <= k; i++){
		a = (a%MOD + count(n-i, k, flag || i >= d)%MOD)%MOD;
	}
	return a;
}

class CKTree {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k;
		in >> n >> k >> d;
		memset(memo, -1, sizeof(memo));
		ll ans = count(n,k,false);
		out << ans;
	}
};