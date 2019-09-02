#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATenki {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s,t;
		
		in >> s >> t;
		int ans = 0;
		
		for (int i = 0; i < s.size(); i++)
			ans += (s[i] == t[i]);
		
		out << ans;

	}
};