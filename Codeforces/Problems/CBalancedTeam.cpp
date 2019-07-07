#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 100005
class CBalancedTeam {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, ans = -1;
		in >> n;
		vector<int> s(n, -1);
		REP(i, n)
			in >> s[i];
		sort(s.begin(), s.end());
		REP(i, n){
		    int cur = s[i];
		    int b = upper_bound(s.begin(), s.end(), cur+5) - s.begin() -1;
		    ans = max(ans, b-i + 1);
		}
		out << ans;
	}
};