#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATheNumberOfPositions {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a, b, n, x, y, ans = 0;
		in >> n >> a >> b;
		x = 0;
		y = n-1;
		while(y >= 0){
		    if (x >= a && y <= b)
		        ans++;
		    y--;
		    x++;
		}
		out << ans;

	}
};