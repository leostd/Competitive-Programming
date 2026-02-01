#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class APythagoreanTheoremII {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int c, ans = 0;
		RE(a,n){
			RE(b, a){
				c = (int)sqrt(sqr(a) + sqr(b) + 0.0001);
				if (sqr(c) == (sqr(a)+sqr(b)) && c <= n ){
				    ans++;
//				    out << a << " " << b << endl;
				}
			}
		}
		out << ans;

	}
};