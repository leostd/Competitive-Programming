#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CFiveTransportations {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<ll> v;
		ll x;
		ll n;
		in >> n;
		REP(i,6)
			in >> x, v.pb(x);
		sort(v.begin(), v.end());
		ll ans = ceil(n/(double)v[0]);
		ans += 4;
		out << ans;

	}
};