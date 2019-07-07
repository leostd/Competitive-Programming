#include <iostream>
#include <vector>
#include <set>
using namespace std;

typedef pair<int,int> ii;

class BDraw {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n, ans = 0;
		in >> n;
		vector<int> a(n,0),b(n,0);
		for (int i = 0; i < n; i++)
			in >> a[i+1] >> b[i+1];

		out << ans;
	}
};