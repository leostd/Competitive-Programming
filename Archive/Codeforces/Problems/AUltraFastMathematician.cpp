#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AUltraFastMathematician {
public:
	void solve(std::istream& in, std::ostream& out) {
		string a, b, c;
		in >> a >> b;
		REP(i, a.size()){
		    if (a[i] != b[i])
		        c.pb('1');
		    else
		        c.pb('0');
		}
		out << c;
	}
};