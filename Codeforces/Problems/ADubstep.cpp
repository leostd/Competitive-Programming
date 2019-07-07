#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ADubstep {
public:
	void solve(std::istream& in, std::ostream& out) {
		string str;
		in >> str;
		REP(i,str.size()-2){
		    if (str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B')
		        str[i] = str[i+1] = str[i+2] = '0';
		}
		string ans, w;
		REP(i,str.size()){
		    if (str[i] == '0' && w != ""){
		        ans += w ;
		        ans += " ";
		        w = "";
		    }
		    else if (str[i] != '0'){
		        w += str[i];
		    }
		}
		if (w != "")
			ans += w;
		out << ans;

	}
};