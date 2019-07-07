#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 200005

class BChocolates {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<int> a;
		int x;
		in >> n;
		REP(i,n){
			in >> x;
			a.pb(x);
		}
		reverse(a.begin(), a.end());
		ll mx=-1, aux = 0, ans = 0;
		REP(i,n){
			if (mx == -1){
				ans += a[i];
				mx = a[i];
			}
			else if (a[i] < mx){
				mx = a[i];
				ans += a[i];
			}
			else if (a[i] >= mx && mx == 1){
				break;
			}
			else if (a[i] >= mx){
				mx--;
				ans += mx;
			}
		}
		out << ans;
	}
};