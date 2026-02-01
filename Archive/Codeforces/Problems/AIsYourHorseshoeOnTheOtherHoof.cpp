#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AIsYourHorseshoeOnTheOtherHoof {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a,b,c,d;
		set<int> s;
		in >> a >> b >> c >> d;
		s.insert(a);
		s.insert(b);
		s.insert(c);
		s.insert(d);
		out << 4 - s.size();

	}
};