#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ATwoBagsOfPotatoes {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll y, k, n;
		vector<ll> s;
		in >> y >> k >> n;
		int i = 1;
		while (k*i <= n){
			if (k*i > y)
				s.pb(k*i-y);
			i++;
		}
		if (s.empty())
		    out << -1;
        else
            REP(i, s.size())
                out << s[i] << " ";
	}
};