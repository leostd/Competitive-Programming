#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AThreePilesOfCandies {
public:
	void solve(std::istream& in, std::ostream& out) {
		int q;
		in >> q;
		while(q--){
			ll a, b, c;
			in >> a >> b >> c;
			ll sum = a + b + c;
			out << sum / 2 << "\n";
		}

	}
};