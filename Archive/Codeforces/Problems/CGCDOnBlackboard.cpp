#include "../library/lib.hpp"
#include <iostream>
using namespace std;

int gcd(int a, int b){
	int mn = min(a,b);
	int mx = max(a,b);
	a = mn;
	b = mx;
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

class CGCDOnBlackboard {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		int x;
		vector<int> a, l, r;
		REP(i,n)
			in >> x, a.pb(x);
		l.assign(n+1, 0);
		r.assign(n+1, 0);
		l[0] = a[0];
		r[n-1] = a[n-1];
		for(int i = 1; i < a.size(); i++){
			int aux = l[i-1];
			l[i] = gcd(a[i], aux);
		}

		for(int i = n-2; i >= 0; i--){
			r[i] = gcd(a[i], r[i+1]);
		}

		int ans = max(l[n-2], r[1]);
		for(int i = 1; i < n; i++){
			ans = max(ans, gcd(l[i-1], r[i+1]));
		}
		out << ans;
	}
};