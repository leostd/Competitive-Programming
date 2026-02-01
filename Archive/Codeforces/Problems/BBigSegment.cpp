#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define N 100005

class BBigSegment {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		ll f[N], l[N], minf = 0x3f3f3f3f, maxl = -1;
		REP(i,n){
		    in >> f[i] >> l[i];
		    minf = min(minf, f[i]);
		    maxl = max(maxl, l[i]);
		}
		REP(i,n)
		    if (f[i] == minf && l[i] == maxl){
                out << i+1;
                return;
		    }
		out << -1;
	}
};