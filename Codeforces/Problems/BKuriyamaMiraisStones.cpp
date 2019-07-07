#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BKuriyamaMiraisStones {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, m;
		in >> n;
		int x;
		vector<ll> v;
		REP(i,n)
			in >> x, v.pb(x);
		FenwickTree s(v);
		sort(v.begin(), v.end());
		FenwickTree os(v);
		in >> m;
		int l, r, t;
		REP(i,m){
			in >> t >> l >> r;
			if (t == 1){
				out << s.get_sum(r-1) - s.get_sum(l-2);
			} else
				out << os.get_sum(r-1) - os.get_sum(l-2);
			out << "\n";

		}
	}
};