#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CEdgyTrees {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<pii> g;
		int x,y,z;
		int n, k;
		in >> n >> k;
		REP(i,n-1){
			in >> x >> y >> z;
			g[x].pb(mp(y,z));
		}
	}
};