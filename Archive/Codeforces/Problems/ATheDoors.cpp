#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATheDoors {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, last1, last0;
	    last1 = last0 = 0x3f3f3f3f;
	    vector<int> a;
	    int x;
	    in >> n;
	    RE(i, n){
	        in >> x;
	        if (x == 1)
	            last1 = i;
	        else
	            last0 = i;
	    }
	    out << min(last0, last1);
	}
};