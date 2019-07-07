#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AFreeCash {
public:
	void solve(std::istream& in, std::ostream& out) {
		pii x;
		int n;
		in >> n;
		int ans = 0;
		map<pii, int> m;
		REP(i,n)
			in >> x.fst >> x.snd, m[x]++, ans= max(ans, m[x]);
		out << ans;

	}
};