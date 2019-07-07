#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AlphabetFromOuterSpace {
public:
	void solve(std::istream& in, std::ostream& out) {
	    int n, m, cs = 1;
	    in >> n;
	    while(n--){
	        in >> m;
	        vector<string> s;
	        set<char> alphabet;
	        string str;
	        REP(i,m){
	            in >> str, s.pb(str);
	            REP(j, s.size())
	                alphabet.insert(str[j]);
	        }
	        if (alphabet.size() < m){
	            out << "AMBIGUOUS\n";
	            continue;
	        }
	        else{
	            vector<char> g[80];
	            for (int i = 0; i < m-1; ++i){
	                string a, b;
	                a = s[i];
	                b = s[i+1];
	            }
	        }
	    }

	}
};