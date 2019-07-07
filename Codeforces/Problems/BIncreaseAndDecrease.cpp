#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BIncreaseAndDecrease {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int x;
		ll sum = 0;
		REP(i, n)
			in >> x, sum+= x;
		if (sum % n == 0)
			out << n;
		else
			out << n-1;

	}
};