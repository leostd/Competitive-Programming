#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class B {
public:
	void solve(std::istream& in, std::ostream& out) {
	    vector<string> g;
	    string s;
	    int n, m;
	    in >> n >> m;
	    REP(i, n)
	        in >> s, g.pb(s);
	    REP(i, n-1){
	    	int cnt = 0;
	        REP(j, m-1){
	            if (g[i][j] == '#')
	                cnt++;
	            if (g[i+1][j] == '#')
	            	cnt++;
	        }
	        if (cnt <= 1 || cnt >= 3){
	            out << "YES";
	            return;
	        }
	    }
	    out << "NO";

	}
};