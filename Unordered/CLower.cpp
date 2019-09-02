#include "../library/lib.hpp"
#include <iostream>
using namespace std;

#define MAXN  100005

class CLower {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;

		int h[MAXN];
		for (int i = 0; i < n; i++)
			in >> h[i];

		int ans = 0;
		int fidx, lidx, fval, lval;
		fidx = lidx = 0;
		lval = 0x3f3f3f3f;
		for (int i = 0; i < n; i++){
		    if (lval >= h[i]){
		        lval = h[i];
		        lidx = i;
		    }
		    else {
		        ans = max(ans, lidx - fidx);
		        lidx = fidx = i;
		        lval = h[i];
		    }
		}
		ans = max(ans, lidx-fidx);
		out << ans;



	}
};