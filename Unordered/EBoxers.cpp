#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class EBoxers {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		in >> n;
		set<int> uq;
		vector<int> b;
		int x;
		
		for (int i = 0; i < n; i++)
		    in >> x, b.pb(x);
		
		int lst = 0x3f3f3f, ans = 0;
		sort(b.begin(), b.end(), greater<int>());
		for(int i = 0; i < b.size();i++){
		    if (b[i] + 1 < lst)
		        lst = b[i] + 1, ans++;
		    else if (b[i] < lst)
		        lst = b[i], ans++;
		    else if (b[i] - 1 > 0 && b[i] - 1 < lst)
		        lst = b[i]-1, ans++;
		}
		
		out << ans;

	}
};