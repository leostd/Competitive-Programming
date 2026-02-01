#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BPoloThePenguinAndMatrix {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m,d;
		in >> n >> m >> d;
		vector<int> v;
		int a = -1, x;
		REP(i,n){
			REP(j,m){
				in >> x, v.pb(x);
				if (a == -1)
					a = x % d;
				else{
					if (x%d != a){
					    out << -1;
					    return;
					}
				}
			}
		}
		sort(v.begin(), v.end());
		int t = v[n*m/2];
		ll ans = 0;
		REP(i,n*m){
		    ans += abs(t-v[i]);
		}
		out << ans / d;

	}
};