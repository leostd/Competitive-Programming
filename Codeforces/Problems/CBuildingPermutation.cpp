#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CBuildingPermutation {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		int p[300005];
		in >> n;
		RE(i,n)
		    in >> p[i];
		sort(p+1,p+n+1);
		ll ans = 0;
		RE(i, n){
		    ans += abs(i - p[i]);
		}
        out << ans;
	}
};