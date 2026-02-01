#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ADomino {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<int> oddsl, oddsr;
		bool m[100000];
		memset(m, 0, sizeof(m));
		int n, x, y;
		in >> n;
		REP(i,n){
		    in >> x >> y;
		    if (x % 2 != 0)
		        oddsl.pb(i);
		    if (y % 2 != 0)
		        oddsr.pb(i);
		    if (y % 2 && x % 2)
		    	m[i] = true;
		}
		if ((!oddsl.empty() || !oddsr.empty()) && oddsl.size() % 2 && oddsr.size() % 2){
		    REP(i, oddsl.size()){
		        REP(j, oddsr.size()){
		            if (oddsl[i] != oddsr[j] && !m[i]){
		                out << 1;
		                return;
		            }
		        }
		    }
		}
		if ((oddsl.empty() && oddsr.empty()) || (oddsl.size() % 2 == 0 && oddsr.size() % 2 == 0))
			out << 0;
		else
			out << -1;
	}
};