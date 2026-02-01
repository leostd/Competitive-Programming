#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class OnionWars {
public:
	void solve(std::istream& in, std::ostream& out) {
		int c, cs=1;
		in >> c;
		while (c--){
			int n, m;
			in >> n >> m;
			out << "Case #" << cs++ << ": " << n/2+n%2+m/2+m%2 << "\n";
		}
	}
};