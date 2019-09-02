#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class DModSum {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll n;

		in >> n;
		n--;
		out << n*(n+1)/2L;

	}
};