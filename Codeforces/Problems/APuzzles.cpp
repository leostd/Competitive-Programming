#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class APuzzles {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		int a[53];
		REP(i, m)
		    in >> a[i];
		sort(a,a+m);
		int ans = 0x3f3f3f3f;
		REP(i, m-n+1){
		   ans = min(ans, a[i+n-1] - a[i]); 
		}
        out << ans;
	}
};