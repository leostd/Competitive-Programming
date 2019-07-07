#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BGoodString {
public:
	void solve(std::istream& in, std::ostream& out) {
		int t;
		in >> t;
		while(t--){
		    int n;
		    string s, ss;
		    in >> n;
		    char x;
		    in >> s;
			int l = 0;
			int mn = 0x3f3f3f3f;
			if (s[0] == '>' || s[s.size()-1] == '<'){
				out << "0\n";
				continue;
			}
			else if (s[0] == '<' && s[s.size()-1] == '>'){
				
				int i = 0;
				int aux = 0;
				while (s[i] == '<')
					aux++, i++;
				mn = min(mn, aux);
				reverse(s.begin(), s.end());
				i = aux = 0;
				while(s[i] == '>')
					aux++, i++;
				mn = min(mn, aux);
			}
			out << mn << "\n";
		}

	}
};