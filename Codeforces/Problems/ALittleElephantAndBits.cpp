#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ALittleElephantAndBits {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in >> str;
		bool first = true;
		bool ones = true;
		REP(i,str.size())
			if (str[i] == '0'){
				ones = false;
				break;
			}
		if (ones)
			REP(i, str.size()-1)
				out << str[i];
		else{
			REP(i,str.size()){
				if (str[i] == '0' && first){
					first = false;
				}
				else
					out << str[i];
			}
		}
	}
};