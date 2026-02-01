#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ARedOrNot {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a;
		string s;
		
		in >> a >> s;
		
		out << (a < 3200? "red" : s);

	}
};