#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AInsomniaCure {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k,l,m,n,d;
		in >> k >> l >> m >> n >> d;
		int ans = 0;
		FOR(i,1,d){
			if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0)
				ans++;
		}
		out << ans;

	}
};