#include "../library/lib.hpp"
#include <iostream>
using namespace std;

class ARestoringThreeNumbers {
public:
	void solve(std::istream& in, std::ostream& out) {
		vector<int> n;
		int x;
		REP(i,4)
			in >> x, n.pb(x);
		sort(n.begin(), n.end());
		int m = n.back();
		for(int i = 2; i >= 0; i--)
			out << m - n[i] << " ";

	}
};