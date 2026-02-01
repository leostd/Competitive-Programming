#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BPashmakAndFlowers {
public:
	void solve(std::istream& in, std::ostream& out) {
		map<ll,ll> c;
		ll mx, mn;
		mx = -1; mn = 0x3f3f3f3f;
		ll ans = 0;
		int n;
		in >> n;
		int x;
		REP(i,n){
			in >> x;
			c[x]++;
			if (x > mx)
			    mx = x;
			if (x < mn)
			    mn = x;
		}
		if (mn != mx)
			ans = c[mn] * c[mx];
		else
			ans = c[mn] * (c[mn]-1)/2;

		out << mx-mn << " " << ans;
	}
};