#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AFlippingGame {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<int> a,b;
		int n, *ones;
		in >> n;
		int x;
		ones = new int[n+1];
		memset(ones, 0, sizeof(int)*(n+1));
		REP(i,n)
			in >> x, a.pb(x), ones[i] = (i > 0) ? ones[i] += ones[i-1] + x : x;
		int ans = -1;
		int last = ones[n-1];
		REP(i,n){
			int o;
			for(int j = i; j < n; j++){
				if (i == j)
					o = last - (ones[j]) + (1 - (ones[j]));
				else
			    	o = last - (ones[j]-ones[i]) + ((j-i+1) - (ones[j] - (i-1 >= 0 ? ones[i-1] : 0)));
			    if (o > ans){
			        ans = o;
			    }
			}
		}
		out << ans;



	}
};