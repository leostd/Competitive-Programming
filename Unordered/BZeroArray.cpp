#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class BZeroArray {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		const int MAXN = 1e5 + 2;
		int a[MAXN], mx = -1;
		ll sum = 0;
		in >> n;
		for(int i = 1;i <= n; i++)
			in >> a[i], sum += a[i], mx = max(a[i], mx);

		if (sum%2 == 0 && (sum - mx) >= mx)
		    out << "YES\n";
		else
		    out << "NO\n";
	}
};