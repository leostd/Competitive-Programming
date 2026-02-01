#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BParityAlternatedDeletions {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<ll> even, odd, osum, esum;
		ll x;
		in >> n;
		REP(i, n){
			in >> x;
			if (x % 2 == 0)
				even.pb(x);
			else
				odd.pb(x);

		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());
		REP(i, even.size()){
			x = even[i];
			if (esum.empty())
				esum.pb(x);
			else
				esum.pb(esum[i-1]+x);
		}
		REP(i,odd.size()){
			x = odd[i];
			if(osum.empty())
				osum.pb(x);
			else
				osum.pb(osum[i-1]+x);
		}
		int o, e;
		o = e = 0;
		if(abs((int)even.size()-(int)odd.size()) <= 1){
			out << 0;
			return;
		}
		else if(even.size() == 0){
			if (osum.size() >= 2)
				out << osum[osum.size()-2];
			else
				out << 0;
			return;
		}
		else if(odd.size() == 0){
			if (esum.size() >= 2)
				out << esum[esum.size()-2];
			else
				out << 0;
			return;
		}
		else {
			ll ans = 0x3f3f3f3f;
			if (odd.size() < even.size()){ //start with evens
				out << esum[esum.size()-1-odd.size()-1];
			}
			else{
				out << osum[osum.size()-1 - even.size() -1];
			}
		}

	}
};