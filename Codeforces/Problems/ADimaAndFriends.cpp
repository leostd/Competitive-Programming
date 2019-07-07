#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ADimaAndFriends {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, sum = 0, x;
		in >> n;
		REP(i, n)
			in >> x, sum+=x;
		int ans = 0;
		n++;
		FOR(i,1,5){
			if ((sum + i) % n != 1)
				ans++;
		}
		out << ans;
			
	}
};