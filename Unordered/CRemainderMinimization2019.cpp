#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CRemainderMinimization2019 {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll l, r;
		in >> l >> r;
		ll ans = INFINITY;
		r = min(l+2019, r);
		for (ll i = l; i <= r; i++){
			for (ll j = i+1; j <= r; j++){
				ans = min(ans, (i*j)%2019);
			}
		}
		out << ans;

	}
};