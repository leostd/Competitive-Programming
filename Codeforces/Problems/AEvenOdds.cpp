#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AEvenOdds {
public:
	void solve(std::istream& in, std::ostream& out) {
		ll k,n;
		in >> n >> k;
		ll ans = 0;
		if(n % 2 == 0){
			if (k > n/2)
				ans = (k - n/2) * 2;
			else
				ans = 2*k-1;
		}
		else{
			if (k > (n/2+1)){
				ans = (k - n/2 - 1)*2;
			}
			else
				ans = 2*k-1;
			
		}
		out << ans;
	}
};