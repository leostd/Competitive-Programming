#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class CUnification {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s, aux;
		in >> s;
		int ans = 0;
		REP(i, s.size()){
			if (aux.empty())
				aux.pb(s[i]);
			else{
				if (aux.back() != s[i]){
					aux.pop_back();
					ans += 2;
				} else
					aux.pb(s[i]);
			}
		}
		out << ans;

	}
};