#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AAddingDigits {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll a,b,n;
		bool flag = false;
		in >> a >> b >> n;
		FOR(i,0,9){
		    if ((a*10+i) % b == 0){
		        out << (a*10+i);
		        REP(i, n-1)
		            out << 0;
		        return;
		    }
		}

		    out << -1;
	}
};