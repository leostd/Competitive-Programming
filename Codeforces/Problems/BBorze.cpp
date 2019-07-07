#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BBorze {
public:
	void solve(std::istream& in, std::ostream& out) {
		string c, d;
		int i = 0;
		in >> c;
		while(i < c.size()){
		    if (c[i] == '.')
		        d.pb('0');
		    else if (c[i+1] == '.'){
		        i++;
		        d.pb('1');
		    }
		    else if (c[i+1] == ' '){
		        i++;
		        d.pb('2');
		    }
		    i++;
		}
		out << d;
	}
};