#include "../library/lib.hpp"
#include <iostream>
using namespace std;

bool check(vector<int> h){
	bool flag = true;
	int n = (int)h.size();
	for (int i = n-2; i >= 0; i--) {
		if (h[i] <= h[i+1]) {
			continue;
		}
		else if (h[i] - 1 == h[i+1]){
			h[i]--;
		}
		else{
			flag = false;
			break;
		}
	}
	return flag;
}

class CBuildStairs {
public:
	void solve(std::istream& in, std::ostream& out) {
		int n;
		vector<int> h;
		int x;

		in >> n;
		for (int i = 0; i < n; i++)
			in >> x, h.pb(x);

		vector<int> h1(h);
		h1[n-1]--;
		bool flag = check(h) || check(h1);
		out << (flag ? "Yes" : "No");
	}
};