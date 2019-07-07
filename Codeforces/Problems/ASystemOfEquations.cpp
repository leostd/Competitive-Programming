#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ASystemOfEquations {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n >> m;
		int ans = 0;
		REP(a,1001){
		    REP(b,1001){
		        if (sqr(a) + b == n && sqr(b) + a == m){
		            ans++;
		        }
		    }
		}
		out << ans;

	}
};