#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ASoftDrinking {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, k, l, c, d, p, nl, np;
		in >> n >> k >> l >> c >> d >> p >> nl >> np;
		int ml = k * l / nl;
		int sl = c * d;
		p = p / np;
		out << min(min(p, ml), sl)/n;

	}
};