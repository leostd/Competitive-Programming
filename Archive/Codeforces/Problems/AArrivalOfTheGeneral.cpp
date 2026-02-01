#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AArrivalOfTheGeneral {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, mn = 102, mx = -1, mxi = -1, mni = -1;
		in >> n;
		vector<int> s(n, 0);
		REP(i,n){
		    in >> s[i];
		    if (s[i] > mx){
		        mx = s[i];
		        mxi = i;
		    }
		}
		int ans = mxi;
		s.erase(s.begin()+mxi);
		s.insert(s.begin(), mx);
		REP(i, n){
			if(s[i] <= mn){
				mn = s[i];
				mni = i;
			}
		}
		ans += (n-mni-1);
		out << ans;
	}
};