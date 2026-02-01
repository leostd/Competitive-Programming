#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AWord {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s;
		in >> s;
		int upc = 0;
		REP(i, s.size()){
			upc += isupper(s[i]);
		}
		if (upc > s.size()/2)
			transform(s.begin(), s.end(), s.begin(), ::toupper);
		else 
		    transform(s.begin(), s.end(), s.begin(), ::tolower);
		out << s;
	}
};