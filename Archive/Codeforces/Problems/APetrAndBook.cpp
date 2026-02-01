#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class APetrAndBook {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, d[8];
		in >> n;
		FOR(i,1,7)
			in >> d[i];
		int i = 1;
		int ans = -1;
		while(n > 0){
			n -= d[(i % 7 == 0 ? 7 : i % 7) ];
			ans = i % 7;
			i++;
		}
		out << (ans == 0 ? 7 : ans);

	}
};