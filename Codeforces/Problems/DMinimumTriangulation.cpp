#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class DMinimumTriangulation {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		ll ans = 0;
		FOR(i,2,n-1)
			ans += i*(i+1);
		out << ans;

	}
};