#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BDrinks {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		double c = 0, x;
		in >> n;
		REP(i, n){
			in >> x;
			c+= x;
		}
		out << (c / (double)(n*100)) * 100;
	}
};