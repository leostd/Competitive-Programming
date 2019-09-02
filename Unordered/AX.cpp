#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AX {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a,b;
		in >> a >> b;
		
		out << max(a+b, max(a-b, a*b));

	}
};