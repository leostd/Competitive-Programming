#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 100055
class ABestSubsegment {
public:
	void solve(std::istream& in, std::ostream& out) {
		int a[N], n, mx = -1;
		in >> n;
		REP(i,n){
		    in >> a[i];
		    mx = max(mx, a[i]);
		}
		auto x = (equal_range(a,a+n,mx).second-a);
		auto y = (equal_range(a,a+n,mx).first-a);
		int ans = (equal_range(a,a+n,mx).second-a) - (equal_range(a,a+n,mx).first-a) + 1;
		out << ans;
	}
};