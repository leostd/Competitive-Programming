#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BResistorsInParallel {
public:
	void solve(std::istream& in, std::ostream& out) {
		double x, ans = 0.0;
		int n;
		in >> n;
		
		for (int i = 0; i < n; i++)
		    in >> x, ans += 1.0/x;
        
		out.precision(16);
		out << 1/ans;
	}
};