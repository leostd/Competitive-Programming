#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class D2RemoveTheSubstringHardVersion {
public:
	void solve(std::istream& in, std::ostream& out) {
		string s, t;
		in >> s >> t;

		vector<int> r(t.size());
		for (int i = (int)t.size()-1; i >= 0; i--){
			int pos = (int)s.size()-1;
			if (i+1 < t.size()) pos = r[i+1] - 1;
			while(s[pos] != t[i]) pos--;
			r[i] = pos;
		}

		int ans = 0, pos = 0;
		for (int i = 0; i < s.size(); i++){
			int rpos = s.size()-1;
			if (pos < t.size()) rpos = r[pos] - 1;
			ans = max(ans, rpos - i + 1);
			if (pos < t.size() && t[pos] == s[i]) pos++;
		}
		out << ans;


	}
};