#include "../library/lib.hpp"
#include <iostream>
using namespace std;
#define N 10005

class ADetectiveBook {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<int> a;
		int x;
		in >> n;
		a.pb(-1);
		REP(i,n)
			in >> x, a.pb(x);
		int ans = 0, mx = a[1];
		int i = 1;
		while(i <= n){
			mx = max(mx, a[i]);
			while(i <= mx){
				mx = max(mx, a[i]);
				i++;
			}
			ans++;
		}
		out << ans;
	}
};