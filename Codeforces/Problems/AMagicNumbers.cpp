#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AMagicNumbers {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in >> str;
		REP(i,str.size()){
			if (str[i] != '1' && str[i] != '4'){
				out << "NO";
				return;
			}
			if (str[i] == '4'){
				if (i-1 >= 0 && str[i-1] == '1')
					continue;
				if (i-1 >= 0 && str[i-1] == '4' && i-2 >= 0 && str[i-2] == '1')
					continue;
				out << "NO";
				return;
			}
		}
		out << "YES";
	}
};