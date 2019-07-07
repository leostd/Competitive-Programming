#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AStickersAndToys {
public:
	void solve(std::istream& in, std::ostream& out) {
		int tc, n, s,t;
		in >> tc;
		int ans;
		REP(i,tc){
			in >> n >> s >> t;
			assert(n <= s+t);
			if (s + t > n){
			    int both = s + t - n;
			    int m = max(s-both, t-both);
			    ans = m + 1;
			} else if ( s + t == n){
			    ans = max(s, t) + 1;
			}
			out << ans << "\n";
		}

	}
};