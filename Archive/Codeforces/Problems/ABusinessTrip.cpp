#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ABusinessTrip {
public:
	void solve(std::istream& in, std::ostream& out) {
		int k, a[12];
		in >> k;
		REP(i,12)
		    in >> a[i];
		sort(a, a+12, greater<int>());
		int x = 0, ans = 0;
		REP(i, 12){
		    if (a[i] > 0 && k > x){
		        x+=a[i];
		        ans++;
		    }
		}
		out << (k > x ? -1 : ans);
    
	}
};