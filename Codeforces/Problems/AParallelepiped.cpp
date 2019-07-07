#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AParallelepiped {
public:
	void solve(std::istream& in, std::ostream& out) {
		int x, y, z;
		in >> x >> y >> z;

		int a, b, c;
		a = (int) sqrt(x*z/y);
		b = (int) sqrt(x*y/z);
		c = (int) sqrt(z*y/x);
		out << 4*(a+b+c);
	}
};