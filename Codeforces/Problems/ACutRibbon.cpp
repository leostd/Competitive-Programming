#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ACutRibbon {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,a,b,c;
		int ans = -1;
		in >> n >> a >> b >> c;
		for(int x = 0; x <= 4000; x++){
		    for(int y = 0; y <= 4000; y++){
		        int z = (-a*x - b*y + n) / c;
		        if (z < 0)
		        	continue;
		        if (a*x + b*y + c*z == n && (x+y+z) > ans){
		            ans = x+y+z;
		        }
		    }
		}
        out << ans;
	}
};