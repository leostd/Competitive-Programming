#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 1000005
class BXeniaAndRingroad {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n,m, a[N];
		in >> n >> m;
		FOR(i,1,m)
			in >> a[i];
		int cur = 1;
		ll ans = 0;
		FOR(i,1,m){
			if (a[i] < cur){
				ans += (n-cur) + a[i];
			}
			else if (a[i] > cur){
				ans += (a[i] - cur);
			}
			cur = a[i];
		}
		out << ans;
	}
};