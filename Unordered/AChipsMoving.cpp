#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AChipsMoving {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;

		ll a[101];
		map<ll, ll> c;
		REP(i,n)
			in >> a[i], c[a[i]]++;

		ll ans = 0x3f3f3f3f;
		REP(i, n){
			ll aux = 0;
			REP(j, n){
				aux += (abs(a[i]-a[j]))%2;
			}
			ans = min(ans, aux);
		}
		
		out << ans;

	}
};