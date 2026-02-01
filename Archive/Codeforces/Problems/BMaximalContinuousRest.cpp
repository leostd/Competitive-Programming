#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BMaximalContinuousRest {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		string str;
		int x;
		REP(i, n)
			in >> x, str += (x + '0');
		str += str;
		int ans = 0, cur = 0;
		REP(i, str.size()){
			if (str[i] == '1'){
				cur++;
			}
			else{
				ans = max(ans, cur);
				cur = 0;
			}
		}
		out << ans;
	}
};