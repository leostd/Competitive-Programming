#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BSale {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		int a[102];
		in >> n >> m;
		REP(i,n)
			in >> a[i];
		sort(a,a+n);
		int ans = 0;
		REP(i,m)
			ans += (a[i] < 0 ? -1*a[i] : 0);
		out << ans;

	}
};