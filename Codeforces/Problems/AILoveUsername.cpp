#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class AILoveUsername {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, ans = 0;
		in >> n;
		vector<int> a(n, 0);
		REP(i, n)
			in >> a[i];
		FOR(i, 1, n-1){
			bool f1, f2;
			f1 = f2 = true;
			REP(j, i){
				f1 = f1 && a[i] > a[j];
				f2 = f2 && a[i] < a[j];
			}
			ans += (f1 || f2);
		}
		out << ans;


	}
};